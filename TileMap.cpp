#include "TileMap.hpp"
#include <SGL/Window/Window.hpp>
#include <SGL/Graphic/Surface.hpp>
#include "Objects/Factory.hpp"
#include "Objects/Entities/Quinn.hpp"
#include "Interaction.hpp"

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
        }
        break;
    }

    if (cat == Cat::Item || cat == Cat::Entity) {
        Tile* tile = make_tile(ID::Gras, _tileset, pos);
        _tiles.push_back(std::unique_ptr<Tile>(tile));
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
        tile->update();
    }

    for (std::unique_ptr<Entity>& entity : _entities) {
        Effect* effect = Interaction(entity.get(), this);
        if (effect)
            _effects.push_back(std::unique_ptr<Effect>(effect));

        entity->update();
    }

    for (std::unique_ptr<Item>& item : _items) {
        if (item->isActive())
            item->update();
    }

    for (std::unique_ptr<Stream>& stream : _streams) {
        stream->update();
    }

    for (std::unique_ptr<Effect>& effect : _effects) {
        if (effect->isValid())
            effect->update();
    }
}

void TileMap::draw(const sgl::Window* wnd) const {
    for (const std::unique_ptr<Tile>& tile : _tiles) {
        tile->draw(wnd);
    }

    for (const std::unique_ptr<Item>& item : _items) {
        if (item->isActive())
            item->draw(wnd);
    }

    for (const std::unique_ptr<Entity>& entity : _entities) {
        entity->draw(wnd);
    }

    for (const std::unique_ptr<Stream>& stream : _streams) {
        stream->draw(wnd);
    }

    for (const std::unique_ptr<Effect>& effect : _effects) {
        if (effect->isValid())
            effect->draw(wnd);
    }
}

Tile* TileMap::getTileAt(const sgl::vec2f& pos) {
    return this->getAt(pos, _tiles);
}

Item* TileMap::getItemAt(const sgl::vec2f& pos) {
    return this->getAt(pos, _items);
}

Entity* TileMap::getEntityAt(const sgl::vec2f& pos) {
    return this->getAt(pos, _entities);
}

Stream* TileMap::getStreamAt(const sgl::vec2f& pos) {
    return this->getAt(pos, _streams);
}
