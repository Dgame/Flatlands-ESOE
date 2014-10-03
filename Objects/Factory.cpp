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

    if (id >= 1 && id < 7)
        return Cat::Tile;
    if (id >= 7 && id < 11)
        return Cat::Stream;
    if (id >= 11 && id < 14)
        return Cat::Item;
    if (id >= 14 && id < 16)
        return Cat::Entity;

    return Cat::None;
}

Tile* make_tile(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
    const sgl::int8 tile_id = id - 1;
    switch (id) {
        case Type::EdgeGroundLeft:
        case Type::EdgeGroundRight:
        case Type::Ground:
            return new Ground(tile_id, texture, pos);
        case Type::EdgeGrasLeft:
        case Type::EdgeGrasRight:
        case Type::Gras:
            return new Gras(tile_id, texture, pos);
    }

    return nullptr;
}

Item* make_item(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
    const sgl::int8 tile_id = id - 1;
    switch (id) {
        case Type::Crystall_1:
            return new Crystall(5, tile_id, texture, pos);
        case Type::Crystall_2:
            return new Crystall(15, tile_id, texture, pos);
        case Type::Crystall_3:
            return new Crystall(25, tile_id, texture, pos);
    }

    return nullptr;
}

Stream* make_stream(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
    const sgl::int8 tile_id = id - 1;
    switch (id) {
        case Type::StreamDown:
            return new Stream(Direction::Down, tile_id, texture, pos);
        case Type::StreamUp:
            return new Stream(Direction::Up, tile_id, texture, pos);
        case Type::StreamLeft:
            return new Stream(Direction::Left, tile_id, texture, pos);
        case Type::StreamRight:
            return new Stream(Direction::Right, tile_id, texture, pos);
    }

    return nullptr;
}

Entity* make_entity(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
    const sgl::int8 tile_id = id - 1;
    switch (id) {
        case Type::Quinn:
            return new Quinn(tile_id, texture, pos);
        case Type::Bug:
            return new Bug(tile_id, texture, pos);
    }

    return nullptr;
}
