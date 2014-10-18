#ifndef FLATLAND_TILE_MAP_HPP
#define FLATLAND_TILE_MAP_HPP

#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <sstream>
#include <pugixml.hpp>

#include <SGL/Graphic/Texture.hpp>

#include "Objects/Tile.hpp"
#include "Objects/Stream.hpp"
#include "Objects/Item.hpp"
#include "Objects/Entity.hpp"

#include "Effects/Effect.hpp"

#include "Config.hpp"

class Quinn;

class TileMap {
private:
    std::vector<std::unique_ptr<Tile>> _tiles;
    std::vector<std::unique_ptr<Item>> _items;
    std::vector<std::unique_ptr<Stream>> _streams;
    std::vector<std::unique_ptr<Entity>> _entities;
    std::vector<std::unique_ptr<Effect>> _effects;

    Quinn* _quinn = nullptr;

    sgl::Texture _tileset;

    sgl::uint16 _width;
    sgl::uint16 _height;

private:
    void _generate(sgl::int8 id, const sgl::vec2s&);

public:
    explicit TileMap(const std::string&);

    void update();
    void draw(const sgl::Window*) const;

    Tile* getTileAt(const sgl::vec2f&);
    Item* getItemAt(const sgl::vec2f&);
    Entity* getEntityAt(const sgl::vec2f&);
    Stream* getStreamAt(const sgl::vec2f&);

    Quinn* getQuinn() {
        return _quinn;
    }

    sgl::uint16 width() const {
        return _width;
    }

    sgl::uint16 height() const {
        return _height;
    }
};

#endif // FLATLAND_TILE_MAP_HPP
