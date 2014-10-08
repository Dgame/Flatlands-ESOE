#include "Entity.hpp"
#include "Tile.hpp"

Entity::Entity(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : FlatLandObject(id, texture, pos) {

}

void Entity::interactWith(const Tile* tile) {
    if (tile && tile->isGround())
        _onGround = true;
    else if (_onGround)
        _onGround = false;
}
