#include "Stream.hpp"
#include <SGL/Window/Window.hpp>

Stream::Stream(Direction dir, sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : Tile(id, texture, pos), _dir(dir) {

}

void Stream::draw(const sgl::Window* wnd) const {
    Tile::draw(wnd);
}

void Stream::interact(const sgl::Shape*) const {
    // TODO: Störmung
}
