#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include <string>
#include <vector>
#include <SGL/Graphic/Texture.hpp>
#include <SGL/Graphic/Surface.hpp>
#include <SGL/Math/vec2.hpp>
#include <pugixml.hpp>
#include "Tile.hpp"

namespace {
    std::vector<std::string> split(const std::string&, char delim);
}

class TileMap {
private:
    std::vector<Tile> _tiles;
    sgl::Texture _texture;

    sgl::uint16 _width;
    sgl::uint16 _height;

public:
    explicit TileMap(const std::string&);

    const Tile& at(const sgl::vec2s&) const;
    const Tile& at(sgl::uint32 index) const;

    void replaceAt(const sgl::vec2s&, const Tile&);
    void replaceAt(sgl::uint32 index, const Tile&);

    sgl::uint16 width() const {
        return this->_width;
    }

    sgl::uint16 height() const {
        return this->_height;
    }
};

#endif // TILE_MAP_HPP
