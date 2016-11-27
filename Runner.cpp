//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Direction Runner::step() {
  if ((current_status.right == BlockType::FREE ||
       current_status.right == BlockType::EXIT) &&
      (!path[foo(x + 1, y)])) {
    ++x;
    path[foo(x, y)] = 1;
    return Direction::RIGHT;
  }
  if ((current_status.up == BlockType::FREE ||
       current_status.up == BlockType::EXIT) &&
      (!path[foo(x, y + 1)])) {
    ++y;
    path[foo(x, y)] = 1;
    return Direction::UP;
  }
  if ((current_status.left == BlockType::FREE ||
       current_status.left == BlockType::EXIT) &&
      (!path[foo(x - 1, y)])) {
    --x;
    path[foo(x, y)] = 1;
    return Direction::LEFT;
  }
  if ((current_status.down == BlockType::FREE ||
       current_status.down == BlockType::EXIT) &&
      (!path[foo(x, y - 1)])) {
    --y;
    path[foo(x, y)] = 1;
    return Direction::DOWN;
  }
  const std::vector<Direction> directions = {Direction::UP, Direction::DOWN,
                                             Direction::LEFT, Direction::RIGHT};
  Direction rand_dir = directions[std::rand() % directions.size()];

  if (rand_dir == Direction::UP) {
    ++y;
  } 
  if (rand_dir == Direction::DOWN) {
    --y;
  } 
  if (rand_dir == Direction::RIGHT) {
    ++x;
  } 
  if (rand_dir == Direction::LEFT) {
    --x;
  } 
  return rand_dir;
};
