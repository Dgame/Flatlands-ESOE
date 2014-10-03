#ifndef FLATLAND_STREAM_HPP
#define FLATLAND_STREAM_HPP

#include "FlatLandObject.hpp"

enum class Direction : char {
    Up,
    Down,
    Left,
    Right,
};

class Stream : public FlatLandObject {
private:
    Direction _dir;

public:
    explicit Stream(Direction dir, sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Stream() { }

    Direction getDirection() const {
        return _dir;
    }

    virtual void interactWith(Entity*) override;
};

#endif // FLATLAND_STREAM_HPP
