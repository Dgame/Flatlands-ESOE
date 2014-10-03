#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include <string>
#include <vector>
#include <memory>

#include <sstream>
#include <pugixml.hpp>

#include <SGL/Graphic/Texture.hpp>

#include "Objects/Tile.hpp"
#include "Objects/Stream.hpp"
#include "Objects/Item.hpp"
#include "Objects/Entity.hpp"

namespace {
    std::vector<std::string> split(const std::string&, char delim);

    inline int toInt(const char* value) {
        std::stringstream buf;
        buf << value;

        int num = 0;
        buf >> num;

        return num;
    }
}

class TileMap {
private:
    std::vector<std::unique_ptr<Tile>> _tiles;
    std::vector<std::unique_ptr<Item>> _items;
    std::vector<std::unique_ptr<Stream>> _streams;
    std::vector<std::unique_ptr<Entity>> _entities;

    sgl::Texture _tileset;

    sgl::uint16 _width;
    sgl::uint16 _height;

private:
    void _generate(sgl::int8 id, const sgl::vec2s&);

public:
    explicit TileMap(const std::string&);

    void draw(const sgl::Window*) const;

    const Tile* at(const sgl::vec2s&) const;
    const Tile* at(sgl::uint32 index) const;

    sgl::uint16 width() const {
        return this->_width;
    }

    sgl::uint16 height() const {
        return this->_height;
    }
};

#endif // TILE_MAP_HPP
