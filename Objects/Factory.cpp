#include "Factory.hpp"

#include "Tiles/Gras.hpp"
#include "Tiles/Ground.hpp"
#include "Items/Crystall.hpp"
#include "Entities/Quinn.hpp"
#include "Entities/Bug.hpp"
#include "Stream.hpp"

#include <SGL/Graphic/Texture.hpp>
#include "ID.hpp"

Tile* MakeTile(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
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

Item* MakeItem(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
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

Stream* MakeStream(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
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

Entity* MakeEntity(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
    const sgl::int8 tile_id = id - 1;
    switch (id) {
        case ID::Quinn:
            return new Quinn(tile_id, texture, pos);
        case ID::Bug:
            return new Bug(tile_id, texture, pos);
    }

    return nullptr;
}
