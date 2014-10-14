#include "Crystall.hpp"
#include "../ID.hpp"
#include "../../Effects/CrystallCatched.hpp"

namespace {
    const sgl::int16 Values[] = {200, 150, 100};
}

Crystall::Crystall(sgl::int16 val, sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : Item(id, texture, pos), _value(val) {
    _sprite.setCenter(16, 16);
}

Effect* Crystall::getEffect() const {
    return new CrystallCatched(this->getValue(), _sprite.getPosition());
}

sgl::int16 Crystall::getValue() const {
    const sgl::int16 idx = static_cast<sgl::int16>(_id) - ID::Crystall_1;
    return Values[idx + 1];
}
