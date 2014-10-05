#include "Factory.hpp"

#include "Tiles/Gras.hpp"
#include "Tiles/Ground.hpp"
#include "Items/Crystall.hpp"
#include "Entities/Quinn.hpp"
#include "Entities/Bug.hpp"
#include "Stream.hpp"

Cat identifyID(sgl::int8 id) {
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

Tile* make_tile(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
    const sgl::int8 tile_id = id - 1;
    switch (id) {
        case ID::EdgeGroundLeft:
        case ID::EdgeGroundRight:
        case ID::Ground:
            return new Ground(tile_id, texture, pos);
        case ID::Gras:
            return new Gras(tile_id, texture, pos);
    }

    return nullptr;
}

Item* make_item(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
    const sgl::int8 tile_id = id - 1;
    switch (id) {
        case ID::Crystall_1:
            return new Crystall(5, tile_id, texture, pos);
        case ID::Crystall_2:
            return new Crystall(15, tile_id, texture, pos);
        case ID::Crystall_3:
            return new Crystall(25, tile_id, texture, pos);
    }

    return nullptr;
}

Stream* make_stream(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
    const sgl::int8 tile_id = id - 1;
    switch (id) {
        case ID::StreamDown:
            return new Stream(Direction::Down, tile_id, texture, pos);
        case ID::StreamUp:
            return new Stream(Direction::Up, tile_id, texture, pos);
        case ID::StreamLeft:
            return new Stream(Direction::Left, tile_id, texture, pos);
        case ID::StreamRight:
            return new Stream(Direction::Right, tile_id, texture, pos);
    }

    return nullptr;
}

Entity* make_entity(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
    const sgl::int8 tile_id = id - 1;
    switch (id) {
        case ID::Quinn:
            return new Quinn(tile_id, texture, pos);
        case ID::Bug:
            return new Bug(tile_id, texture, pos);
    }

    return nullptr;
}
