#ifndef FLATLAND_TILE_GRAS_HPP
#define FLATLAND_TILE_GRAS_HPP

#include "../Tile.hpp"

class Gras : public Tile {
public:
    explicit Gras(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Gras() { }

    virtual void update() override;
};

#endif // FLATLAND_TILE_GRAS_HPP
