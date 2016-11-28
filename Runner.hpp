#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
#include "utils.hpp"

#include <stack>
#include <unordered_set>

struct Point {
  int x;
  int y;

  bool operator==(const Point&) const;
};

class PointHash {
 public:
  std::size_t operator()(const Point&) const;

 private:
  std::hash<int> hasher_;
};

using Path = std::stack<Direction>;
using PointSet = std::unordered_set<Point, PointHash>;

class Runner : public RunnerBase {
 public:
  Runner();

  Direction step();

 private:
  Path path_;
  Point position_;
  PointSet visited_;

  bool wasHere(Direction) const;

  Direction goBack();

  Direction goDown(bool);

  Direction goLeft(bool);

  Direction goRight(bool);

  Direction goUp(bool);
};

#endif
