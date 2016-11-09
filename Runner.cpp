//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


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
