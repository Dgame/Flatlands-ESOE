#include "Level.hpp"
#include <sstream>
#include <SGL/Window/Window.hpp>

void Level::load() {
    std::stringstream buf;
    buf << "media/level_";
    buf << _levelNr;
    buf << ".tmx";

    std::string filename = buf.str();

    _map = std::unique_ptr<TileMap>(new TileMap(filename));

    filename.replace(filename.find(".tmx"), 4, ".png");

    sgl::Surface bg(filename);
    _bg.load(bg);

    if (!bg)
        bg.loadFromFile(DEFAULT_BACKGROUND);
    if (!_background)
        _background = std::unique_ptr<sgl::Sprite>(new sgl::Sprite(_bg));
}

void Level::loadNext() {
    _levelNr++;
    this->load();
}

void Level::draw(const sgl::Window* wnd) const {
    wnd->draw(*_background);
    _map->draw(wnd);
}
