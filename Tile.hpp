#ifndef TILE_HPP
#define TILE_HPP

#define TILE_SIZE 64

#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Sprite>

struct Tile {
    sgl::int8 id;
    sgl::Sprite sprite;

    explicit Tile(int8 id, sgl::Texture&);
};

#endif // TILE_HPP
