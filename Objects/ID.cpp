#include "ID.hpp"

Cat CategorizeID(sgl::int8 id) {
    if (id <= 0)
        return Cat::None;

    if (id >= ID::EdgeGroundLeft && id <= ID::Gras)
        return Cat::Tile;
    if (id >= ID::StreamRight && id <= ID::StreamDown)
        return Cat::Stream;
    if (id >= ID::Crystall_1 && id <= ID::Crystall_3)
        return Cat::Item;
    if (id >= ID::Quinn && id <= ID::Bug)
        return Cat::Entity;

    return Cat::None;
}
