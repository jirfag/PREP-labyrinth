#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <stack>
#include <list>
#include <algorithm>

#include "RunnerBase.hpp"

class Cell{
public:
    // Constructors & Destructors
    Cell();
    Cell(const Status& state, const Direction& prevStep);
    Cell(const Status& state);

    bool isDeadlock() const;
    Direction getBackDirection() const;

    Direction chooseNextDirection() const;

    bool getDirectionState(const Direction&) const;
    void setDirectionState(const Direction&, bool value);

private:
    bool leftDone;
    bool rightDone;
    bool upDone;
    bool downDone;

    Status state;

    bool isStart;

    Direction prevStep;
    Direction backDirection;
};

Direction getOppositeDirection(const Direction& direction);

class Runner: public RunnerBase {
public:
    // Constructors
    Runner();

    Direction step();

private:
    std::stack<Cell> history;
    std::list<std::pair<int, int>> deadlocks;

    Direction lastChoice;
    bool isForwardDirection;

    int x;
    int y;

    bool checkForDeadlock(int x, int y) const;
    bool checkForDeadlock(const Direction&) const;

    void addDeadlock(int x, int y);
};


#endif //LABYRINTH_RUNNER_HPP
