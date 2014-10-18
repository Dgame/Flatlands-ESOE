#ifndef FLATLAND_ID_HPP
#define FLATLAND_ID_HPP

#include <SGL/Core/Types.hpp>

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

enum class Cat : sgl::int8 {
    None,
    Tile,
    Item,
    Entity,
    Stream
};

Cat CategorizeID(sgl::int8 id);

#endif // FLATLAND_ID_HPP
