#ifndef TILE_GRAS_HPP
#define TILE_GRAS_HPP

#include "Tile.hpp"

struct Gras : public Tile {
    explicit Gras(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Gras() { }

    void draw(const sgl::Window*) const override;
};

#endif // TILE_GRAS_HPP
