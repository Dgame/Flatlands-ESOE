#ifndef TILE_STREAM_HPP
#define TILE_STREAM_HPP

#include "Tile.hpp"

enum class Direction : char {
    Up,
    Down,
    Left,
    Right,
};

class Stream : public Tile {
private:
    Direction _dir;

public:
    explicit Stream(Direction dir, sgl::int8 id, sgl::Texture&, const sgl::vec2s&);
    virtual ~Stream() { }

    void draw(const sgl::Window*) const override;
    void interact(const sgl::Shape*) const override;

    Direction getDirection() const {
        return _dir;
    }
};

#endif // TILE_STREAM_HPP
