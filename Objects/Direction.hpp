#ifndef FLATLAND_DIRECTION_HPP
#define FLATLAND_DIRECTION_HPP

enum class Direction : char {
    Up,
    Down,
    Left,
    Right,
};

inline int DirectionToInt(Direction dir) {
    if (dir == Direction::Up || dir == Direction::Right)
        return 1;
    return -1;
}

#endif // FLATLAND_DIRECTION_HPP
