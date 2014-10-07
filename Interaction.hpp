#ifndef FLATLAND_INTERACTION_HPP
#define FLATLAND_INTERACTION_HPP

class Entity;
class TileMap;

struct Interaction {
    void treat(Entity*, TileMap*);
};

#endif // FLATLAND_INTERACTION_HPP
