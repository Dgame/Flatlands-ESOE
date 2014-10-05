#ifndef FLATLAND_CLOUD_HPP
#define FLATLAND_CLOUD_HPP

#include "FlatLandObject.hpp"
#include <SGL/Graphic/Texture.hpp>

class Cloud : public FlatLandObject {
private:
    sgl::Texture _texture;

    void _spawn();
    void _respawn();

public:
    Cloud(int which);

    virtual void update() override;
};

#endif // FLATLAND_CLOUD_HPP
