#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
class Runner: public RunnerBase {
public:
    Runner() : currDirection(Direction::RIGHT){};
    Direction step();
    bool isFreeUp();
    bool isFreeDown();
    bool isFreeLeft();
    bool isFreeRight();

    bool isExitLeft();
    bool isExitDown();
    bool isExitUp();
    bool isExitRight();

private:
    Direction currDirection;

};

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
#endif //LABYRINTH_RUNNER_HPP
