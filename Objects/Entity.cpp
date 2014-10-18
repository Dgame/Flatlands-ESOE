#include "Entity.hpp"
#include "Tile.hpp"

Entity::Entity(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : FlatLandObject(id, texture, pos) {

}

void Entity::reverseDirection() {
     if (_dir == Direction::Left)
        _dir = Direction::Right;
    else if (_dir == Direction::Right)
        _dir = Direction::Left;
}

sgl::vec2f Entity::getLookOffset() const {
    return sgl::vec2f(0, 0);
}

void Entity::interactWith(const Tile* tile) {
    if (tile && tile->isGround())
        _onGround = true;
    else if (_onGround)
        _onGround = false;
}
