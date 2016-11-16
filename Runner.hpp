//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#define DEBUG 0

#if DEBUG
#include <fstream>
#endif

#include <unordered_map>

#include "RunnerBase.hpp"

struct Point {
    int x, y;
    bool operator==(const Point& point) const;
};

struct PointHash {
    size_t operator()(const Point& point) const;
};

class Runner: public RunnerBase {
public:
#if DEBUG
    std::ofstream steps;
    ~Runner();
#endif

    Runner();
    Direction step();

private:
    void incrementCurrentPositionPassagesCount();
    Direction getNextDirection();
    Point getDirectionPoint(Direction direction);

    const Direction directions[4];
    Point currentPosition = {0, 0};
    Point previousPosition = {0, 0};
    std::unordered_map<Point, unsigned short, PointHash> labyrinthMap;
};


#endif //LABYRINTH_RUNNER_HPP
