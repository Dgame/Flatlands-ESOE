#include <iostream>
#include <sstream>
#include <SGL/Window/Window.hpp>
#include "TileMap.hpp"

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

void TileMap::draw(const sgl::Window* wnd) const {
    for (const std::unique_ptr<Tile>& tile : _tiles) {
        tile->draw(wnd);
    }
}

TileMap::TileMap(const std::string& filename) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filename.c_str());

    if (result) {
        pugi::xml_node map_node = doc.child("map");
        this->_width = map_node.attribute("width").as_int();
        this->_height = map_node.attribute("height").as_int();

//        map.attribute("tilewidth").value()
//        map.attribute("tileheight").value()

        pugi::xml_node image_node = map_node.child("tileset").child("image");

        const std::string tileset_file = image_node.attribute("source").value();

        const std::string dirname = split(filename, '/')[0];
        sgl::Surface tileset(dirname + '/' + tileset_file);
        this->_texture.load(tileset);

        sgl::vec2s pos(0, 0);

        pugi::xml_node data = map_node.child("layer").child("data");
        for (pugi::xml_node_iterator it = data.begin(); it != data.end(); ++it) {
            // Layer
            for (pugi::xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait) {
                sgl::int16 gid = static_cast<sgl::int16>(*ait->value()) - '0';
                if (gid != 0) {
                    //std::cout << ait->name() << "::" << ait->value() << "::" << gid << std::endl;
                    _tiles.push_back(make_tile(gid, _texture, pos));
                }
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

const Tile* TileMap::at(const sgl::vec2s& pos) const {
    return this->at(pos.x + (pos.y * this->_height + 1));
}

const Tile* TileMap::at(sgl::uint32 index) const {
    return this->_tiles.at(index).get();
}
