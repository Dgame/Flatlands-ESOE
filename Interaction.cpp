#include "Interaction.hpp"

#include "Objects/Tile.hpp"
#include "Objects/Entity.hpp"
#include "Effects/Effect.hpp"

#include "TileMap.hpp"

Effect* Interaction(Entity* entity, TileMap* tm) {
    // TODO: observe if entity is falling and animate falling smooth
    sgl::vec2f pos = entity->getPosition();
    // if not effected by gravity: look forward
    if (!entity->isEffectedByGravity()) {
        // Look a half tile to the left / right
        if (entity->getDirection() == Direction::Left)
            pos.x -= HALF_TILE_SIZE;
        else
            pos.x += HALF_TILE_SIZE;
    }
    // look down
    pos.y += GRAVITY;

    const Tile* tile = tm->getTileAt(pos);
    entity->interactWith(tile);

    pos = entity->getPosition();

    const Stream* stream = tm->getStreamAt(pos);
    entity->interactWith(stream);

    Item* item = tm->getItemAt(pos);
    if (item && item->isActive()) {
        entity->interactWith(item);

        if (item && entity->catchItems()) {
            item->disable();

            return item->getEffect();
        }
    }

    return nullptr;
}
