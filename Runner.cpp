#include "Runner.hpp"
#include "utils.hpp"

#include <iostream>

bool Point::operator==(const Point& point) const {
  return this->x == point.x && this->y == point.y;
}

std::size_t PointHash::operator()(const Point& point) const {
  return hasher_(point.x) ^ hasher_(point.y);
}

Runner::Runner() : position_({0, 0}) { visited_.insert(position_); };

bool Runner::wasHere(Direction direction) const {
  switch (direction) {
    case Direction::DOWN:
      return visited_.find({position_.x, position_.y - 1}) != visited_.end();

    case Direction::LEFT:
      return visited_.find({position_.x - 1, position_.y}) != visited_.end();

    case Direction::RIGHT:
      return visited_.find({position_.x + 1, position_.y}) != visited_.end();

    case Direction::UP:
      return visited_.find({position_.x, position_.y + 1}) != visited_.end();
  }
  return false;
}

Direction Runner::goBack() {
  Direction last = path_.top();
  path_.pop();
  switch (last) {
    case Direction::DOWN:
      return goUp(false);

    case Direction::LEFT:
      return goRight(false);

    case Direction::RIGHT:
      return goLeft(false);

    case Direction::UP:
    default:
      return goDown(false);
  }
}

Direction Runner::goDown(bool savePath = true) {
  if (savePath) {
    path_.push(Direction::DOWN);
  }
  position_.y -= 1;
  visited_.insert(position_);
  return Direction::DOWN;
}

Direction Runner::goLeft(bool savePath = true) {
  if (savePath) {
    path_.push(Direction::LEFT);
  }
  position_.x -= 1;
  visited_.insert(position_);
  return Direction::LEFT;
}

Direction Runner::goRight(bool savePath = true) {
  if (savePath) {
    path_.push(Direction::RIGHT);
  }
  position_.x += 1;
  visited_.insert(position_);
  return Direction::RIGHT;
}

Direction Runner::goUp(bool savePath = true) {
  if (savePath) {
    path_.push(Direction::UP);
  }
  position_.y += 1;
  visited_.insert(position_);
  return Direction::UP;
}

Direction Runner::step() {
  if (current_status.right == BlockType::EXIT ||
      (current_status.right == BlockType::FREE && !wasHere(Direction::RIGHT))) {
    return goRight();
  }

  if (current_status.up == BlockType::EXIT ||
      (current_status.up == BlockType::FREE && !wasHere(Direction::UP))) {
    return goUp();
  }

  if (current_status.left == BlockType::EXIT ||
      (current_status.left == BlockType::FREE && !wasHere(Direction::LEFT))) {
    return goLeft();
  }

  if (current_status.down == BlockType::EXIT ||
      (current_status.down == BlockType::FREE && !wasHere(Direction::DOWN))) {
    return goDown();
  }

  return goBack();
};
