#include "FlatLandObject.hpp"
#include "Entity.hpp"
#include "Item.hpp"
#include <SGL/Window/Window.hpp>

FlatLandObject::FlatLandObject(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : _id(id), _sprite(texture) {
    _sprite.setPosition(pos * TILE_SIZE);
    _sprite.setClipRect(sgl::ShortRect(id * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
}

void FlatLandObject::draw(const sgl::Window* wnd) const {
    wnd->draw(_sprite);
}


void FlatLandObject::interactWith(Entity*) {

}

void FlatLandObject::interactWith(Item*) {

}
