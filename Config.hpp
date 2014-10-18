#ifndef FLATLAND_CONFIG_HPP
#define FLATLAND_CONFIG_HPP

#include <string>

const int TILE_SIZE = 32;
const int HALF_TILE_SIZE = TILE_SIZE / 2;
const int DOUBLE_TILE_SIZE = TILE_SIZE * 2;

const int GRAVITY = HALF_TILE_SIZE;
const int JUMP_FORCE = TILE_SIZE;

const std::string DEFAULT_BACKGROUND = "media/level_1.png";

#endif // FLATLAND_CONFIG_HPP
