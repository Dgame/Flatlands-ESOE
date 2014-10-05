#include "TileMap.hpp"
#include <SGL/Window/Window.hpp>
#include <SGL/Graphic/Surface.hpp>
#include "Objects/Factory.hpp"
#include "Objects/Entities/Quinn.hpp"

namespace {
    std::vector<std::string> split(const std::string& str, char delim) {
        std::vector<std::string> elems;
        std::stringstream ss(str);

        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
}

void TileMap::_generate(sgl::int8 id, const sgl::vec2s& pos) {
    const Cat cat = identifyID(id);
    switch (cat) {
        case Cat::Tile:
        {
            Tile* tile = make_tile(id, _tileset, pos);
            _tiles.push_back(std::unique_ptr<Tile>(tile));
        }
        break;
        case Cat::Item:
        {
            Item* item = make_item(id, _tileset, pos);
            _items.push_back(std::unique_ptr<Item>(item));

            Tile* tile = make_tile(ID::Gras, _tileset, pos);
            _tiles.push_back(std::unique_ptr<Tile>(tile));
        }
        break;
        case Cat::Stream:
        {
            Stream* stream = make_stream(id, _tileset, pos);
            _streams.push_back(std::unique_ptr<Stream>(stream));
        }
        break;
        case Cat::Entity:
        {
            Entity* entity = make_entity(id, _tileset, pos);
            _entities.push_back(std::unique_ptr<Entity>(entity));

            Tile* tile = make_tile(ID::Gras, _tileset, pos);
            _tiles.push_back(std::unique_ptr<Tile>(tile));
        }
        break;
    }
}

TileMap::TileMap(const std::string& filename) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filename.c_str());

    if (result) {
        pugi::xml_node map_node = doc.child("map");
        _width = map_node.attribute("width").as_int();
        _height = map_node.attribute("height").as_int();

//        map.attribute("tilewidth").value()
//        map.attribute("tileheight").value()

        pugi::xml_node image_node = map_node.child("tileset").child("image");

        const std::string tileset_file = image_node.attribute("source").value();
        const std::string dirname = split(filename, '/')[0];

        sgl::Surface tileset(dirname + '/' + tileset_file);
        _tileset.load(tileset);

        sgl::vec2s pos(0, 0);

        pugi::xml_node data = map_node.child("layer").child("data");
        for (pugi::xml_node_iterator it = data.begin(); it != data.end(); ++it) {
            // Layer
            for (pugi::xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait) {
                const int gid = toInt(ait->value());
                _generate(gid, pos);

                if (gid == ID::Quinn)
                    _quinn = static_cast<Quinn*>(_entities.back().get());

                pos.x++;
                if (pos.x >= _width) {
                    pos.x = 0;
                    pos.y++;
                }
            }
        }
    } else {
        std::cerr << "Could not load map " << filename << std::endl;
    }
}

void TileMap::update() {
    for (std::unique_ptr<Tile>& tile : _tiles) {
        _interaction.handle(tile.get(), this);

        tile->update();
    }

    for (std::unique_ptr<Entity>& entity : _entities) {
        _interaction.handle(entity.get(), this);

        entity->update();
    }

    for (std::unique_ptr<Item>& item : _items) {
        _interaction.handle(item.get(), this);

        item->update();
    }

    for (std::unique_ptr<Stream>& stream : _streams) {
        _interaction.handle(stream.get(), this);

        stream->update();
    }
}

void TileMap::draw(const sgl::Window* wnd) const {
    for (const std::unique_ptr<Tile>& tile : _tiles) {
        tile->draw(wnd);
    }

    for (const std::unique_ptr<Item>& item : _items) {
        item->draw(wnd);
    }

    for (const std::unique_ptr<Entity>& entity : _entities) {
        entity->draw(wnd);
    }

    for (const std::unique_ptr<Stream>& stream : _streams) {
        stream->draw(wnd);
    }
}

Tile* TileMap::getTileAt(const sgl::vec2f& pos) {
    const sgl::vec2s global_pos = PixelToPos(pos);

    for (std::unique_ptr<Tile>& tile : _tiles) {
        const sgl::vec2s global_tile_pos = PixelToPos(tile->getPosition());

        if (global_pos == global_tile_pos) {
//            std::cout << "Matchting tile!" << std::endl;
            return tile.get();
        }
    }

//    std::cout << "No tile..." << std::endl;

    return nullptr;
}

Item* TileMap::getItemAt(const sgl::vec2f&) {
    return nullptr;
}

Entity* TileMap::getEntityAt(const sgl::vec2f&) {
    return nullptr;
}

Stream* TileMap::getStreamAt(const sgl::vec2f&) {
    return nullptr;
}
