#ifndef FLATLAND_ENTITY_HPP
#define FLATLAND_ENTITY_HPP

#include "FlatLandObject.hpp"
#include "Direction.hpp"

class Entity : public FlatLandObject {
protected:
    Direction _dir = Direction::Left;

public:
    explicit Entity(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Entity() { }

    Direction getDirection() const {
        return _dir;
    }

    virtual void noGround() { }

    virtual void interactWith(Entity*) { }
    virtual void interactWith(Item*) { }
};

#endif
