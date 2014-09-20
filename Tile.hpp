#ifndef TILE_HPP
#define TILE_HPP

#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Sprite.hpp>

struct Tile {
    sgl::int8 Id;
    sgl::Sprite sprite;

    explicit Tile(sgl::int8 id, sgl::Texture&);
};

#endif // TILE_HPP
