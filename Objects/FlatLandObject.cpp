#include "FlatLandObject.hpp"
#include <SGL/Window/Window.hpp>

#include "../Config.hpp"

FlatLandObject::FlatLandObject(sgl::Texture& texture) : _id(0), _sprite(texture) {
    _sprite.setCenter(HALF_TILE_SIZE, HALF_TILE_SIZE);
}

FlatLandObject::FlatLandObject(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : _id(id), _sprite(texture) {
    _sprite.setPosition(pos * static_cast<sgl::int16>(TILE_SIZE));
    _sprite.setClipRect(sgl::ShortRect(_id * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    _sprite.setCenter(HALF_TILE_SIZE, HALF_TILE_SIZE);
}

const sgl::vec2f& FlatLandObject::getPosition() const {
    return _sprite.getPosition();
}

void FlatLandObject::draw(const sgl::Window* wnd) const {
    wnd->draw(_sprite);
}
