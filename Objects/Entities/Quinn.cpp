#include "Quinn.hpp"
#include "../Item.hpp"
#include "../Stream.hpp"
#include "../../Config.hpp"

Quinn::Quinn(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : Entity(id, texture, pos) {

}

void Quinn::move(Direction dir) {
    if (this->isOnGround()) {
        if (_clock.getElapsedMs() > 50) {
            _clock.reset();

            switch (dir) {
                case Direction::Left:
                    _sprite.move(-HALF_TILE_SIZE, 0);
                break;
                case Direction::Right:
                    _sprite.move(HALF_TILE_SIZE, 0);
            }

            _sprite.rotate(90);
        }
    }
}

void Quinn::update() {
    if (!this->isOnGround()) {
        if (_clock.getElapsedMs() > 50) {
            _clock.reset();
            _sprite.move(0, HALF_TILE_SIZE);
        }
    }
}

void Quinn::interactWith(Entity*) {

}

void Quinn::interactWith(Item*) {

}

void Quinn::interactWith(Stream*) {

}
