//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"
#include <iostream>

Direction Runner::step() {

  if (current_status.right == BlockType::EXIT) {
    ++x;
    path[foo(x, y)] = 1;
    return Direction::RIGHT;
  }
   if (current_status.up == BlockType::EXIT) {
    ++y;
    path[foo(x, y)] = 1;
    return Direction::UP;
  }
  if (current_status.left == BlockType::EXIT) {
    --x;
    path[foo(x, y)] = 1;
    return Direction::LEFT;
  }
   if (current_status.down == BlockType::EXIT) {
    --y;
    path[foo(x, y)] = 1;
    return Direction::DOWN;
  }
  if ( (current_status.right == BlockType::FREE) && (!path[foo(x + 1, y)]) ) {
    ++x;
    path[foo(x, y)] = 1;
    order.push(Direction::LEFT);
    return Direction::RIGHT;
  }
  if ( (current_status.up == BlockType::FREE) && (!path[foo(x, y + 1)]) ) {
    ++y;
    path[foo(x, y)] = 1;
    order.push(Direction::DOWN);
    return Direction::UP;
  }
  if ( (current_status.left == BlockType::FREE) && (!path[foo(x - 1, y)]) ) {
    --x;
    path[foo(x, y)] = 1;
    order.push(Direction::RIGHT);
    return Direction::LEFT;
  }
  if ( (current_status.down == BlockType::FREE) && (!path[foo(x, y - 1)]) ) {
    --y;
    path[foo(x, y)] = 1;
    order.push(Direction::UP);
    return Direction::DOWN;
  }
  prev=order.top();
  order.pop();
  if (prev==Direction::UP) {
    ++y;
    return prev;
  }
  if (prev==Direction::DOWN) {
    --y;
    return prev;
  }
  if (prev==Direction::RIGHT) {
    ++x;
    return prev;
  }
  --x;
  return prev;
};
