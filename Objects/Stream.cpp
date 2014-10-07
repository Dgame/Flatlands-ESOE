#include "Stream.hpp"
#include "Entity.hpp"
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
