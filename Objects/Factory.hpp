#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Texture.hpp>
#include <SGL/Math/vec2.hpp>

class Tile;
class Stream;
class Item;
class Entity;

namespace Type {
    enum {
        EdgeGroundLeft = 1,
        Ground = 2,
        EdgeGroundRight = 3,

        EdgeGrasLeft = 4,
        Gras = 5,
        EdgeGrasRight = 6,

        StreamRight = 7,
        StreamLeft = 8,
        StreamUp = 9,
        StreamDown = 10,

        Crystall_1 = 11,
        Crystall_2 = 12,
        Crystall_3 = 13,

        Quinn = 14,
        Bug = 15
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

#endif // FACTORY_HPP
