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

#include "Config.hpp"

class Quinn;

namespace {
    inline int toInt(const char* value) {
        std::stringstream buf;
        buf << value;

        int num = 0;
        buf >> num;

        return num;
    }

    inline sgl::vec2s PixelToPos(const sgl::vec2f& pos) {
        const sgl::int16 x = static_cast<sgl::int16>(std::round(pos.x / TILE_SIZE));
        const sgl::int16 y = static_cast<sgl::int16>(std::round(pos.y / TILE_SIZE));

        return sgl::vec2s(x, y);
    }
}

class TileMap {
private:
    std::vector<std::unique_ptr<Tile>> _tiles;
    std::vector<std::unique_ptr<Item>> _items;
    std::vector<std::unique_ptr<Stream>> _streams;
    std::vector<std::unique_ptr<Entity>> _entities;

    Quinn* _quinn = nullptr;

    sgl::Texture _tileset;

    sgl::uint16 _width;
    sgl::uint16 _height;

private:
    void _generate(sgl::int8 id, const sgl::vec2s&);

    template <typename T>
    T* getAt(const sgl::vec2f&, std::vector<std::unique_ptr<T>>&);

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

template <typename T>
T* TileMap::getAt(const sgl::vec2f& pos, std::vector<std::unique_ptr<T>>& my_values) {
    const sgl::vec2s pixel_pos = PixelToPos(pos);

    for (std::unique_ptr<T>& value : my_values) {
        const sgl::vec2s value_pixel_pos = PixelToPos(value->getPosition());

        if (pixel_pos == value_pixel_pos)
            return value.get();
    }

    return nullptr;
}

#endif // FLATLAND_TILE_MAP_HPP
