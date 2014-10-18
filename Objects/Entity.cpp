#include "Entity.hpp"
#include "Tile.hpp"
#include "../Config.hpp"

Entity::Entity(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : FlatLandObject(id, texture, pos) {

}

void Entity::jump() {
    if (_onGround && !_onStream)
        _onJump = true;
}

void Entity::update() {
    if (_onJump)
        _sprite.move(DOUBLE_TILE_SIZE * DirectionToInt(_dir), JUMP_FORCE * -1);
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
    const bool my_on_ground = _onGround;

    if (tile && tile->isGround())
        _onGround = true;
    else if (_onGround)
        _onGround = false;

    if (my_on_ground != _onGround)
        _onJump = false;
}
