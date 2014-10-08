#include "Stream.hpp"
#include "Entity.hpp"
#include "../Config.hpp"
#include <SGL/Window/Window.hpp>

Stream::Stream(Direction dir, sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : FlatLandObject(id, texture, pos), _dir(dir) {

}

void Stream::update() {
    if (_clock.getElapsedMs() > 75) {
        _clock.reset();

        if (!_reverse) {
            _diff -= 1;
            if (_diff <= -3)
                _reverse = true;
        } else if (_reverse) {
            _diff += 1;
            if (_diff >= 3)
                _reverse = false;
        }

        switch (_dir) {
            case Direction::Up:
                _sprite.move(0, _diff);
            break;
            case Direction::Down:
                _sprite.move(0, _diff * -1);
            break;
            case Direction::Left:
                _sprite.move(_diff, 0);
            break;
            case Direction::Right:
                _sprite.move(_diff * -1, 0);
            break;
        }
    }
}

sgl::vec2s Stream::getForce() const {
    switch (_dir) {
        case Direction::Up:
            return sgl::vec2s(0, DOUBLE_TILE_SIZE * -1);
        case Direction::Down:
            return sgl::vec2s(0, DOUBLE_TILE_SIZE);
        case Direction::Left:
            return sgl::vec2s(DOUBLE_TILE_SIZE * -1, 0);
        case Direction::Right:
            return sgl::vec2s(DOUBLE_TILE_SIZE, 0);
    }

    throw std::runtime_error("No direction.");
}
