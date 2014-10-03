#ifndef FLATLAND_LEVEL_HPP
#define FLATLAND_LEVEL_HPP

#include <string>
#include <memory>
#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Surface.hpp>
#include <SGL/Graphic/Texture.hpp>
#include "TileMap.hpp"

namespace sgl {
    class Window;
}

const std::string DEFAULT_BACKGROUND = "media/level_1.png";

class Level {
private:
    sgl::uint16 _levelNr = 1;

    sgl::Texture _bg;

    std::unique_ptr<sgl::Sprite> _background;
    std::unique_ptr<TileMap> _map;

public:
    Level() = default;
    virtual ~Level() { }

    void load();
    void loadNext();

    void draw(const sgl::Window*) const;
};

#endif // FLATLAND_LEVEL_HPP
