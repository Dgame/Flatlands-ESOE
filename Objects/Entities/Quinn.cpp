#include "Quinn.hpp"
#include "../../Config.hpp"

Quinn::Quinn(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : Entity(id, texture, pos) {

}

void Quinn::move(Direction dir) {
    switch (dir) {
        case Direction::Left:
            _sprite.move(-TILE_SIZE / 2, 0);
        break;
        case Direction::Right:
            _sprite.move(TILE_SIZE / 2, 0);
    }

    _sprite.rotate(90);
}

void Quinn::noGround() {
    _sprite.move(0, TILE_SIZE);

    Entity::noGround();
}
