#ifndef FLATLAND_ENTITY_HPP
#define FLATLAND_ENTITY_HPP

#include "FlatLandObject.hpp"
#include "Direction.hpp"
#include <SGL/System/StopWatch.hpp>

class Item;
class Stream;
class Tile;

class Entity : public FlatLandObject {
protected:
    sgl::StopWatch _clock;
    Direction _dir = Direction::Left;

    bool _onGround = true;
    bool _onStream = false;

public:
    explicit Entity(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Entity() { }

    Direction getDirection() const {
        return _dir;
    }

    bool isOnGround() const {
        return _onGround;
    }

    bool isOnStream() const {
        return _onStream;
    }

    virtual bool catchItems() const {
        return false;
    }

    virtual bool isEffectedByGravity() const {
        return true;
    }

    virtual void interactWith(const Tile*);

    virtual void interactWith(const Item*) { }
    virtual void interactWith(const Stream*) { }
    virtual void interactWith(const Entity*) { }
};

#endif
