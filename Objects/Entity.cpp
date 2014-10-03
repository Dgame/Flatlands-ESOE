#include "Entity.hpp"

Entity::Entity(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : FlatLandObject(id, texture, pos) {

}

void Entity::move(float cx, float cy) {

}

void Entity::move(const sgl::vec2f&) {

}

void Entity::interactWith(Item*) {

}
