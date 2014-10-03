#include "Crystall.hpp"

Crystall::Crystall(sgl::int16 val, sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : Item(id, texture, pos), _value(val) {

}
