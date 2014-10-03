#include "Tile.hpp"
#include "Entity.hpp"

Tile::Tile(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) : FlatLandObject(id, texture, pos) {

}

void Tile::interactWith(Entity*) {

}
