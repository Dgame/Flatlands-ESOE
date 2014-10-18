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
    Direction _dir = Direction::Right;

    bool _onGround = true;
    bool _onStream = false;
    bool _onJump = false;

public:
    explicit Entity(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Entity() { }

    Direction getDirection() const {
        return _dir;
    }

    void jump();

    bool isOnJump() const {
        return _onJump;
    }

    virtual void update() override;

    void reverseDirection();
    virtual sgl::vec2f getLookOffset() const;

    bool isOnGround() const {
        return _onGround;
    }

    bool isOnStream() const {
        return _onStream;
    }

    virtual bool catchItems() const {
        return false;
    }

    virtual void interactWith(const Tile*);
    virtual void interactWith(const Item*) { }
    virtual void interactWith(const Stream*) { }
    virtual void interactWith(const Entity*) { }
};

#endif
