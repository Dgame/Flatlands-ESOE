#include "Tile.hpp"
#include <SGL/Window/Window.hpp>

Tile::Tile(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : Id(id), sprite(texture) {
    this->sprite.setClipRect(sgl::ShortRect(id * TileSize, 0, TileSize, TileSize));
    this->sprite.setPosition(pos * TileSize);
}

void Tile::draw(const sgl::Window* wnd) const {
    wnd->draw(this->sprite);
}

void Tile::interact(const sgl::Shape*) const {

}
