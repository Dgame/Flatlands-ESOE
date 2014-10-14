#ifndef FLATLAND_CLOUD_HPP
#define FLATLAND_CLOUD_HPP

#include "../DrawObject.hpp"
#include <SGL/Graphic/Texture.hpp>
#include <SGL/Graphic/Sprite.hpp>
#include <SGL/System/StopWatch.hpp>

class Cloud : public DrawObject {
private:
    sgl::Texture _texture;
    sgl::Sprite _sprite;
    sgl::StopWatch _clock;

    void _spawn();
    void _respawn();

public:
    Cloud(int which);
    virtual ~Cloud() { }

    virtual void update() override;
    virtual void draw(const sgl::Window*) const override;
};

#endif // FLATLAND_CLOUD_HPP
