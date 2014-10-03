#ifndef TILE_GROUND_HPP
#define TILE_GROUND_HPP

#include "../Tile.hpp"

class Ground : public Tile {
public:
    explicit Ground(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Ground() { }
};

#endif // TILE_GROUND_HPP
