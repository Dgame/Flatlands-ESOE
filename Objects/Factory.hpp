#ifndef FLATLAND_FACTORY_HPP
#define FLATLAND_FACTORY_HPP

#include <SGL/Core/Types.hpp>
#include <SGL/Graphic/Texture.hpp>
#include <SGL/Math/vec2.hpp>
#include "ID.hpp"

class Tile;
class Stream;
class Item;
class Entity;

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
