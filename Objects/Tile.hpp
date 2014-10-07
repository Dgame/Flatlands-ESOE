#ifndef FLATLAND_TILE_HPP
#define FLATLAND_TILE_HPP

#include "FlatLandObject.hpp"
#include "ID.hpp"

class Tile : public FlatLandObject {
public:
    explicit Tile(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Tile() { }

    bool isGround() const {
        return this->isEqual(ID::Ground) || this->isEqual(ID::EdgeGroundLeft) || this->isEqual(ID::EdgeGroundRight);
    }
};

#endif // FLATLAND_TILE_HPP
