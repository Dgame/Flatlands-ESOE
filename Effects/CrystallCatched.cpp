#include "CrystallCatched.hpp"
#include <SGL/Window/Window.hpp>

CrystallCatched::CrystallCatched(sgl::int16 value, const sgl::vec2s& pos) : Effect(pos), _font("media/arial.ttf", 16), _text(_font) {
    _font.setStyle(sgl::Font::Style::Bold);

    _text.setData(value);
    _text.foreground = sgl::Color4b::Green;
    _text.setPosition(pos);
}

void CrystallCatched::update() {
    if (_clock.getElapsedMs() > 100) {
        _clock.reset();

        _position.y -= 4;
        _text.setPosition(_position);

        _updates++;
    }
}

void CrystallCatched::draw(const sgl::Window* wnd) const {
    wnd->draw(_text);
}
