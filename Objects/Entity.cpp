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

void Entity::reverseDirection() {
     if (_dir == Direction::Left)
        _dir = Direction::Right;
    else if (_dir == Direction::Right)
        _dir = Direction::Left;
}

void Entity::outOfBounds() {
    this->reverseDirection();
    if (_sprite.getPosition().x <= 0)
        _sprite.move(4, 0);
    else
        _sprite.move(-4, 0);
}
