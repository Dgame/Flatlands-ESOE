#ifndef FLATLAND_INTERACTION_HPP
#define FLATLAND_INTERACTION_HPP

#include "Objects/FlatLandObject.hpp"

class TileMap;

struct Interaction {
    void handle(Tile*, TileMap*);
    void handle(Entity*, TileMap*);
    void handle(Item*, TileMap*);
    void handle(Stream*, TileMap*);
};

#endif // FLATLAND_INTERACTION_HPP
