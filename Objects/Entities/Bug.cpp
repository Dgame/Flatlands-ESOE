#include "Bug.hpp"
#include "../../Config.hpp"
#include <SGL/Graphic/Surface.hpp>

Bug::Bug(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : Entity(id, texture, pos) {
    sgl::Surface lhs("media/bug_left.png");
    _left_texture.load(lhs);

    sgl::Surface rhs("media/bug_right.png");
    _right_texture.load(rhs);

    _sprite.setTexture(_left_texture);
    _sprite.setClipRect(sgl::ShortRect(0, 0, TILE_SIZE, TILE_SIZE));
}

sgl::vec2f Bug::getLookOffset() const {
    sgl::vec2f offset;
    if (this->getDirection() == Direction::Left)
        offset.x -= HALF_TILE_SIZE;
    else
        offset.x += HALF_TILE_SIZE;

    return offset;
}

void Bug::update() {
    if (_clock.getElapsedMs() > 250) {
        _clock.reset();

        if (!_onGround) {
            if (_dir == Direction::Left) {
                _dir = Direction::Right;
                _sprite.setTexture(_right_texture);
            } else if (_dir == Direction::Right) {
                _dir = Direction::Left;
                _sprite.setTexture(_left_texture);
            }

            _sprite.setClipRect(sgl::ShortRect(0, 0, TILE_SIZE, TILE_SIZE));
        }

        if (_dir == Direction::Left)
            _sprite.move(-1, 0);
        else if (_dir == Direction::Right)
            _sprite.move(1, 0);

        if (_sprite.getClipRect().x == 0) {
            _sprite.setClipRect(sgl::ShortRect(TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
        } else {
            _sprite.setClipRect(sgl::ShortRect(0, 0, TILE_SIZE, TILE_SIZE));
        }
    }
}
