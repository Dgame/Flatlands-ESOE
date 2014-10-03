#ifndef TILE_HPP
#define TILE_HPP

#include "FlatLandObject.hpp"

class Tile : public FlatLandObject {
public:
    explicit Tile(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Tile() { }

    virtual void interactWith(Entity*) override;
};

#endif // TILE_HPP
