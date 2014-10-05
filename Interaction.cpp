#include "Interaction.hpp"

#include "Objects/Tile.hpp"
#include "Objects/Item.hpp"
#include "Objects/Entity.hpp"
#include "Objects/Stream.hpp"

#include "TileMap.hpp"
#include "Objects/ID.hpp"

void Interaction::handle(Tile*, TileMap*) {

}

void Interaction::handle(Entity* entity, TileMap* tm) {
    sgl::vec2f pos = entity->getPosition();

    if (entity->getDirection() == Direction::Left)
        pos.x -= TILE_SIZE / 2;
    else
        pos.x += TILE_SIZE / 2;

    pos.y += TILE_SIZE;

    const Tile* tile = tm->getTileAt(pos);
    if (!tile || !tile->isGround())
        entity->noGround();
    else
        entity->onGround();
}

void Interaction::handle(Item*, TileMap*) {

}

void Interaction::handle(Stream*, TileMap*) {

}
