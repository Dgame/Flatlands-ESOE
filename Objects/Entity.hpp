#ifndef FLATLAND_ENTITY_HPP
#define FLATLAND_ENTITY_HPP

#include "FlatLandObject.hpp"
#include "Direction.hpp"

class Entity : public FlatLandObject {
protected:
    Direction _dir = Direction::Left;
    bool _onGround = true;

public:
    explicit Entity(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Entity() { }

    Direction getDirection() const {
        return _dir;
    }

    bool isOnGround() const {
        return _onGround;
    }

    bool onGround() {
        _onGround = true;
    }

    virtual void noGround() {
        _onGround = false;
    }

    virtual void interactWith(Entity*) { }
    virtual void interactWith(Item*) { }
};

#endif
