#ifndef FLATLAND_BACKGROUND_HPP
#define FLATLAND_BACKGROUND_HPP

#include <string>
#include <memory>
#include <vector>
#include "Objects/Cloud.hpp"
#include <SGL/Graphic/Sprite.hpp>

class Background {
private:
    sgl::Texture _bg;
    sgl::Sprite _background;

    std::vector<std::unique_ptr<Cloud>> _clouds;

public:
    explicit Background(sgl::uint16 level);

    void update();
    void draw(const sgl::Window*) const;
};

#endif // FLATLAND_BACKGROUND_HPP
