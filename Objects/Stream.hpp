#ifndef FLATLAND_STREAM_HPP
#define FLATLAND_STREAM_HPP

#include "FlatLandObject.hpp"
#include "Direction.hpp"
#include <SGL/System/StopWatch.hpp>

class Stream : public FlatLandObject {
private:
    Direction _dir;
    sgl::StopWatch _clock;

    sgl::int8 _diff = 0;
    bool _reverse = false;

public:
    explicit Stream(Direction dir, sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Stream() { }

    Direction getDirection() const {
        return _dir;
    }

    virtual void interactWith(Entity*) override;
    virtual void update() override;
};

#endif // FLATLAND_STREAM_HPP
