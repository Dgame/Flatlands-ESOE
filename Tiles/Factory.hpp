#ifndef TILE_FACTORY_HPP
#define TILE_FACTORY_HPP

#include "../Patch.hpp"
#include "Tile.hpp"

struct Ground;
struct Gras;
class Stream;

enum class TileType {
//    Unknown = 0,
    EdgeLeft = 1,
    Ground = 2,
    EdgeRight = 3,
    Gras = 4,
    StreamRight = 5,
    StreamLeft = 6,
    StreamDown = 7,
    StreamUp = 8
};

std::unique_ptr<Tile> make_tile(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);

#endif // TILE_FACTORY_HPP
