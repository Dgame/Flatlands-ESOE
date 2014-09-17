#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include <string>
#include <vector>
#include "libs/pugixml/pugixml.hpp"
#include "Tile.hpp"

struct TileMap {
    std::vector<Tile> tiles;

    explicit TileMap(const std::string&);

    const Tile& at(const vec2&) const;
    const Tile& at(sgl::uint32 index) const;

    void replaceAt(const vec2&, const Tile&);
    void replaceAt(sgl::uint32 index, const Tile&);
};

#endif // TILE_MAP_HPP
