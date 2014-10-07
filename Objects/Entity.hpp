#ifndef FLATLAND_ENTITY_HPP
#define FLATLAND_ENTITY_HPP

#include "FlatLandObject.hpp"
#include "Direction.hpp"
#include <SGL/System/StopWatch.hpp>

class Item;
class Stream;

class Entity : public FlatLandObject {
protected:
    sgl::StopWatch _clock;
    Direction _dir = Direction::Left;

private:
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

    void noGround() {
        _onGround = false;
    }

    void onGround() {
        _onGround = true;
    }

    virtual void interactWith(Entity*) { }
    virtual void interactWith(Item*) { }
    virtual void interactWith(Stream*) { }
};

#endif
