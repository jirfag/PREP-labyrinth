//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#define DEBUG 1

#if DEBUG
#include <iostream>
#include <fstream>
#endif

#include <map>

#include "RunnerBase.hpp"

struct Point {
    int x, y;
};

struct PointCompare {
    bool operator() (const Point& lhs, const Point& rhs) const;
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
    std::map<Point, unsigned short, PointCompare> labyrinthMap;
};


#endif //LABYRINTH_RUNNER_HPP
