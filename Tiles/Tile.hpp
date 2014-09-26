#ifndef TILE_HPP
#define TILE_HPP

#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Sprite.hpp>
#include <SGL/Graphic/Shape.hpp>

const sgl::int16 TileSize = 64;

namespace sgl {
    class Window;
}

struct Tile {
    sgl::int8 Id;
    sgl::Sprite sprite;

    explicit Tile(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Tile() { }

    virtual void draw(const sgl::Window*) const;
    virtual void interact(const sgl::Shape*) const;
};

#endif // TILE_HPP
