#ifndef FLATLAND_LEVEL_HPP
#define FLATLAND_LEVEL_HPP

#include <string>
#include <memory>
#include "TileMap.hpp"
#include "Background.hpp"

class Level {
private:
    sgl::uint16 _levelNr = 1;
    sgl::uint16 _lastLevel = 0;

    std::unique_ptr<Background> _bg;
    std::unique_ptr<TileMap> _map;

public:
    Level() = default;
    virtual ~Level() { }

    void load();
    void loadNext();

    Quinn* getQuinn() {
        return _map->getQuinn();
    }

    void update();
    void draw(const sgl::Window*) const;
};

#endif // FLATLAND_LEVEL_HPP
