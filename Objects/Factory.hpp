#ifndef FLATLAND_FACTORY_HPP
#define FLATLAND_FACTORY_HPP

#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Texture.hpp>
#include <SGL/Math/vec2.hpp>

class Tile;
class Stream;
class Item;
class Entity;

namespace ID {
    enum {
        EdgeGroundLeft = 1,
        Ground = 2,
        EdgeGroundRight = 3,

        Gras = 4,

        StreamRight = 5,
        StreamLeft = 6,
        StreamUp = 7,
        StreamDown = 8,

        Crystall_1 = 9,
        Crystall_2 = 10,
        Crystall_3 = 11,

        Quinn = 12,
        Bug = 13
    };
}

enum class Cat {
    None,
    Tile,
    Item,
    Entity,
    Stream
};

Cat identifyID(sgl::int8 id);

Tile* make_tile(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
Item* make_item(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
Stream* make_stream(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
Entity* make_entity(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);

#endif // FLATLAND_FACTORY_HPP
