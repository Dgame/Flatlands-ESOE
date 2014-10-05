#ifndef FLATLAND_TILE_HPP
#define FLATLAND_TILE_HPP

#include "FlatLandObject.hpp"

class Tile : public FlatLandObject {
public:
    explicit Tile(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Tile() { }

    virtual void interactWith(Entity*) override;
};

#endif // FLATLAND_TILE_HPP
