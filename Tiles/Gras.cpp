#include "Gras.hpp"
#include <SGL/Window/Window.hpp>

Gras::Gras(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : Tile(id, texture, pos) {

}

void Gras::draw(const sgl::Window* wnd) const {
    Tile::draw(wnd);
}
