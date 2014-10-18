#include "Interaction.hpp"

#include "Objects/Tile.hpp"
#include "Objects/Entity.hpp"
#include "Effects/Effect.hpp"

#include "TileMap.hpp"

Effect* Interaction(Entity* entity, TileMap* tm) {
    // Get position
    const sgl::vec2f& pos = entity->getPosition();
    // Get next position
    sgl::vec2f look = pos + entity->getLookOffset();
    // Look down
    look.y += GRAVITY;

    entity->interactWith(tm->getTileAt(look));
    entity->interactWith(tm->getStreamAt(pos));

    Item* item = tm->getItemAt(pos);
    if (item && item->isActive()) {
        entity->interactWith(item);

        if (entity->catchItems()) {
            item->disable();

            return item->getEffect();
        }
    }

    return nullptr;
}
