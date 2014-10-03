#include "Stream.hpp"
#include "Entity.hpp"

Stream::Stream(Direction dir, sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : FlatLandObject(id, texture, pos), _dir(dir) {

}

void Stream::interactWith(Entity*) {

}
