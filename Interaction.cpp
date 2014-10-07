#include "Interaction.hpp"

#include "Objects/Tile.hpp"
#include "Objects/Entity.hpp"

#include "TileMap.hpp"

void Interaction::treat(Entity* entity, TileMap* tm) {
    // TODO: observe if entity is falling and animate falling smooth
    sgl::vec2f pos = entity->getPosition();

    if (entity->isOnGround()) {
        // Look a half tile to the left and to the right
        if (entity->getDirection() == Direction::Left)
            pos.x -= HALF_TILE_SIZE;
        else
            pos.x += HALF_TILE_SIZE;
    }
    // look one tile down
    pos.y += HALF_TILE_SIZE;

    const Tile* tile = tm->getTileAt(pos);
    if (tile && tile->isGround())
        entity->onGround();
    else
        entity->noGround();
}
