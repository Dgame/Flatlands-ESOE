#include "Level.hpp"
#include <sstream>
#include <SGL/Window/Window.hpp>

void Level::load() {
    if (_lastLevel != _levelNr) {
        std::stringstream buf;
        buf << "media/level_";
        buf << _levelNr;
        buf << ".tmx";

        _map = std::unique_ptr<TileMap>(new TileMap(buf.str()));
        _bg = std::unique_ptr<Background>(new Background(_levelNr));

        _lastLevel = _levelNr;
    }
}

void Level::loadNext() {
    _levelNr++;
    this->load();
}

void Level::update() {
    _bg->update();
    _map->update();
}

void Level::draw(const sgl::Window* wnd) const {
    _bg->draw(wnd);
    _map->draw(wnd);
}
