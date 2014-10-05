#include "Cloud.hpp"
#include <random>
#include <sstream>
#include <SGL/Graphic/Surface.hpp>

namespace {
    sgl::uint16 CloudID = 1;
}

Cloud::Cloud(int which) : FlatLandObject(_texture) {
    _spawn();

    if (which < 0)
        which = 0;
    else if (which > 3)
        which = 3;

    std::stringstream buf;
    buf << "media/cloud_";
    buf << which;
    buf << ".png";

    sgl::Surface img(buf.str());
    if (img) {
        _texture.load(img);
        _sprite.setTexture(_texture);
    }

    CloudID += 1;
}

void Cloud::_spawn() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist_x(2000, 80000);
    std::uniform_real_distribution<float> dist_y(5000, 20000);

    float x, y;
    for (sgl::uint16 n = 0; n < 100; ++n) {
        x = dist_x(mt);
        y = dist_y(mt);

//        std::cout << x << ", " << y << std::endl;

        if (n == CloudID) {
//            std::cout << "----" << std::endl;
            break;
        }
    }

    _sprite.setPosition(x / 100, y / 100);
}

void Cloud::_respawn() {
    const sgl::vec2f pos = _sprite.getPosition();

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist_x(2000, 80000);
    std::uniform_real_distribution<float> dist_y(-1000, 20000);

    const float dx = dist_x(mt) / 1000;
    const float dy = dist_y(mt) / 1000;

    _sprite.setPosition(pos.x - 1200 + dx, pos.y - dy);
}

void Cloud::update() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist_x(0.1, 0.8);
    std::uniform_real_distribution<float> dist_y(-0.1, 0.1);

    _sprite.move(dist_x(mt), -dist_y(mt));

    const sgl::vec2f pos = _sprite.getPosition();
    if (pos.x > 1024 ||
        pos.y <= -_texture.height() || pos.y >= 768)
    {
        _respawn();
    }
}
