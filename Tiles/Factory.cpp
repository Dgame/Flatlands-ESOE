#include "Factory.hpp"
#include "Ground.hpp"
#include "Gras.hpp"
#include "Stream.hpp"
#include <iostream>

std::unique_ptr<Tile> make_tile(sgl::int8 id, sgl::Texture& texture, const sgl::vec2s& pos) {
    const TileType tt = static_cast<TileType>(id);
    id--; // To correct 0 as invalid value

    switch (tt) {
        case TileType::EdgeLeft:
        case TileType::EdgeRight:
        case TileType::Ground:
            return std::make_unique<Ground>(id, texture, pos);
        case TileType::Gras:
            return std::make_unique<Gras>(id, texture, pos);
        case TileType::StreamLeft:
            return std::make_unique<Stream>(Direction::Left, id, texture, pos);
        case TileType::StreamRight:
            return std::make_unique<Stream>(Direction::Right, id, texture, pos);
        case TileType::StreamDown:
            return std::make_unique<Stream>(Direction::Down, id, texture, pos);
        case TileType::StreamUp:
            return std::make_unique<Stream>(Direction::Up, id, texture, pos);
    }

    return std::make_unique<Tile>(id, texture, pos);
}
