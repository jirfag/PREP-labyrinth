#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


Runner::Runner(){
    isForwardDirection = true;
    x = 0;
    y = 0;
}

Direction Runner::step(){ ;

    // current cell must be at the top of history
    if (isForwardDirection) { ;

        // if forward direction it adds new Cell
        if (history.size()){
            Cell currCell = Cell(current_status, lastChoice);
            history.push(currCell);
        } else {
            Cell currCell = Cell(current_status);
            history.push(currCell);
        }
    } else {


        // if backward direction do nothing
        // current cell already at the top
    }


    // handling current cell
    Cell& c = history.top();


    // choose new direction
    Direction nextDirection;
    bool haveChoice = false;

    while (!haveChoice){
        if (c.isDeadlock()) {
            // if deadlock new direction is backward

            nextDirection = c.getBackDirection();
            haveChoice = true;

            history.pop();
            isForwardDirection = false;
        } else {
            // if not try to choose new forward direction

            nextDirection = c.chooseNextDirection();
            c.setDirectionState(nextDirection, true);


            haveChoice = !checkForDeadlock(nextDirection);
            isForwardDirection = true;
        }
    }

    if (c.isDeadlock()){
        addDeadlock(x, y);
    }

    // setting new state
    x = x - 2*(nextDirection == Direction::LEFT) + 2*(nextDirection == Direction::RIGHT);
    y = y - 1*(nextDirection == Direction::UP) + 1*(nextDirection == Direction::DOWN);
    lastChoice = nextDirection;


    return nextDirection;
}

bool Runner::checkForDeadlock(int x, int y) const{
    return std::find(deadlocks.crbegin(), deadlocks.crend(), std::make_pair(x, y)) != deadlocks.crend();
}

bool Runner::checkForDeadlock(const Direction& direction) const{
    int nx = x - 2*(direction == Direction::LEFT) + 2*(direction == Direction::RIGHT);
    int ny = y - (direction == Direction::UP) + (direction == Direction::DOWN);

    return checkForDeadlock(nx, ny);
}

void Runner::addDeadlock(int x, int y){
    deadlocks.push_back(std::make_pair(x, y));
}


Direction getOppositeDirection(const Direction& direction){
    switch (direction){
        case Direction::UP:    return Direction::DOWN;
        case Direction::DOWN:  return Direction::UP;
        case Direction::LEFT:  return Direction::RIGHT;
        case Direction::RIGHT: return Direction::LEFT;
    }
    return Direction::LEFT;
}


Cell::Cell(){

}

Cell::Cell(const Status& status, const Direction& prevDirection)
        : Cell(status){
    prevStep = prevDirection;
    backDirection = getOppositeDirection(prevStep);

    isStart = false;
    setDirectionState(backDirection, true);
}

Cell::Cell(const Status& status){
    state = status;

    upDone   = state.up == BlockType::WALL;
    downDone  = state.down == BlockType::WALL;
    leftDone  = state.left == BlockType::WALL;
    rightDone = state.right == BlockType::WALL;

    isStart = true;
}


bool Cell::isDeadlock() const{
    return upDone && downDone && leftDone && rightDone;
}

Direction Cell::getBackDirection() const{
    return backDirection;
}

bool Cell::getDirectionState(const Direction& direction) const{
    switch (direction){
        case Direction::UP    : return upDone;
        case Direction::DOWN  : return downDone;
        case Direction::LEFT  : return leftDone;
        case Direction::RIGHT : return rightDone;
    }
    return true;
}

void Cell::setDirectionState(const Direction& direction, bool value){
    switch (direction){
        case Direction::UP:
            upDone = value;
            break;
        case Direction::DOWN:
            downDone = value;
            break;
        case Direction::LEFT:
            leftDone = value;
            break;
        case Direction::RIGHT:
            rightDone = value;
            break;
    }
}

Direction Cell::chooseNextDirection() const{
    if (state.up    == BlockType::EXIT) return Direction::UP;
    if (state.down  == BlockType::EXIT) return Direction::DOWN;
    if (state.left  == BlockType::EXIT) return Direction::LEFT;
    if (state.right == BlockType::EXIT) return Direction::RIGHT;

    if (!rightDone) return Direction::RIGHT;
    if (!downDone)  return Direction::DOWN;
    if (!upDone)    return Direction::UP;
    if (!leftDone)  return Direction::LEFT;

    return backDirection;
}
