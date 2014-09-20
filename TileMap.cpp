#include "TileMap.hpp"
#include <iostream>

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
        sgl::Surface tileset(tileset_file);
        this->_texture.load(tileset);

        pugi::xml_node data = map_node.child("layer").child("data");
        for (pugi::xml_node_iterator it = data.begin(); it != data.end(); ++it) {
            for (pugi::xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait) {
                if (ait->name() == "gid") {
                    int id = ait->as_int();
                    std::cout << id << std::endl;
                }
            }
        }
    } else {
        std::cerr << "Could not load map " << filename << std::endl;
    }
}

const Tile& TileMap::at(const sgl::vec2s& pos) const {
    return this->at(pos.x + (pos.y * this->_height + 1));
}

const Tile& TileMap::at(sgl::uint32 index) const {
    return this->_tiles.at(index);
}

void TileMap::replaceAt(const sgl::vec2s& pos, const Tile& tile) {
    // TODO:
}

void TileMap::replaceAt(sgl::uint32 index, const Tile& tile) {
    // TODO:
}
