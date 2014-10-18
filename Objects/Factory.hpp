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

Tile* MakeTile(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
Item* MakeItem(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
Stream* MakeStream(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
Entity* MakeEntity(sgl::int8 id, sgl::Texture&, const sgl::vec2s&);

#endif // FLATLAND_FACTORY_HPP
