#include "Quinn.hpp"
#include "../Item.hpp"
#include "../Stream.hpp"
#include "../../Config.hpp"

Quinn::Quinn(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : Entity(id, texture, pos) {

}

void Quinn::move(Direction dir) {
    if (_onGround) {
        _moving = true;
        _dir = dir;
    }
}

void Quinn::update() {
    if (_clock.getElapsedMs() > 100) {
        _clock.reset();

        Entity::update();

        // Fallen / Streamen mit Rotation
        if (!_onGround || _onStream) {
            _sprite.rotate(45);
            if (_onStream)
                _sprite.move(_stream->getForce());
        }

        // Bewegen
        if (_moving) {
            _moving = false;

            _sprite.move(HALF_TILE_SIZE * DirectionToInt(_dir), 0);
            _sprite.rotate(90);
        }

        // Gravity
        if (!_onGround && !_onStream)
            _sprite.move(0, GRAVITY);
    }

    // Liegen wir schr�g?
    if (_onGround && !_onStream) {
        const int mod = static_cast<int>(fmod(_sprite.getRotation(), 90));
        if (mod != 0) {
//            std::cout << mod << std::endl;
            _sprite.setRotation(0);
        }
    }
}

void Quinn::interactWith(const Item* item) {
    _vertex_count += item->getValue();
}

void Quinn::interactWith(const Stream* stream) {
    if (stream)
        _onStream = true;
    else if (_onStream) {
        // Wenn wir gestreamt haben -> weiter fortbewegen
        _moving = true;
        _onStream = false;
    }

    _stream = stream;
}
