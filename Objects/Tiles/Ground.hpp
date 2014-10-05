#ifndef FLATLAND_TILE_GROUND_HPP
#define FLATLAND_TILE_GROUND_HPP

#include "../Tile.hpp"

class Ground : public Tile {
public:
    explicit Ground(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Ground() { }
};

#endif // FLATLAND_TILE_GROUND_HPP
