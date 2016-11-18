#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


Direction Runner::step() {
    switch (currDirection) {
        case Direction::UP:
            return nowUDirectionLEFT();
        case Direction::DOWN:
            return nowDDirectionLEFT();
        case Direction::LEFT:
            return nowLDirectionLEFT();
        case Direction::RIGHT:
            return nowRDirectionLEFT();
        default:
            return Direction::RIGHT;
    }
}

bool Runner::isFreeUp() {
    return current_status.up != BlockType::WALL;
}

bool Runner::isFreeDown() {
    return current_status.down != BlockType::WALL;
}

bool Runner::isFreeLeft() {
    return current_status.left != BlockType::WALL;
}

bool Runner::isFreeRight() {
    return current_status.right != BlockType::WALL;
}

bool Runner::isExitLeft() {
    return current_status.left == BlockType::EXIT;
}

bool Runner::isExitDown() {
    return current_status.down == BlockType::EXIT;
}

bool Runner::isExitUp() {
    return current_status.up == BlockType::EXIT;
}

bool Runner::isExitRight() {
    return current_status.right == BlockType::EXIT;
}

Direction Runner::nowDirectionD() {
    if (isExitRight()) {
        return Direction::RIGHT;
    }
    else if (isExitDown()) {
        return Direction::DOWN;
    }
    else if (isExitLeft())
        return Direction::LEFT;

    if (isFreeLeft()) {
        currDirection = Direction::LEFT;
        return Direction::LEFT;
    }
    else if (isFreeDown()) {
        currDirection = Direction::DOWN;
        return Direction::DOWN;
    }
    else if (isFreeRight()) {
        currDirection = Direction::RIGHT;
        return Direction::RIGHT;
    }
    else {
        currDirection = Direction::UP;
        return Direction::UP;
    }
}

Direction Runner::nowDirectionU() {
    if (isExitLeft()) {
        return Direction::LEFT;
    }
    else if (isExitUp()) {
        return Direction::UP;
    }

    if (isFreeRight()) {
        currDirection = Direction::RIGHT;
        return Direction::RIGHT;
    }
    else if (isFreeUp()) {
        return Direction::UP;
    }
    else if (isFreeLeft()) {
        currDirection = Direction::LEFT;
        return Direction::LEFT;
    }
    else {
        currDirection = Direction::DOWN;
        return Direction::DOWN;
    }
}

Direction Runner::nowDirectionR() {
    if (isExitUp()) {
        currDirection = Direction::UP;
        return Direction::UP;
    }
    else if (isExitRight()) {
        currDirection = Direction::RIGHT;
        return Direction::RIGHT;
    }
    //
    if (isFreeDown()) {
        currDirection = Direction::DOWN;
        return Direction::DOWN;
    }
    else if (isFreeRight()) {
        return Direction::RIGHT;
    }
    else if (isFreeUp()) {
        currDirection = Direction::UP;
        return Direction::UP;
    }
    else {
        currDirection = Direction::LEFT;
        return Direction::LEFT;
    }
}

Direction Runner::nowDirectionL() {
    if (isExitDown()) {
        currDirection = Direction::DOWN;
        return Direction::DOWN;
    }
    else if (isExitLeft()) {
        return Direction::LEFT;
    }
    if (isFreeUp()) {
        currDirection = Direction::UP;
        return Direction::UP;
    }
    else if (isFreeLeft()) {
        return Direction::LEFT;
    }
    else if (isFreeDown()) {
        currDirection = Direction::DOWN;
        return Direction::DOWN;
    }
    else {
        currDirection = Direction::RIGHT;
        return Direction::RIGHT;
    }
}



Direction Runner::nowUDirectionLEFT() {
    
//     if (isExitUp())
//         return Direction::LEFT;
//     else if (isExitLeft())
//         return Direction::UP;
    if (isFreeLeft())
        return currDirection = Direction::LEFT;
    else if (isFreeUp())
        return Direction::UP;
    else if (isFreeRight())
        return currDirection = Direction::RIGHT;
    else 
        return currDirection = Direction::DOWN;
}

Direction Runner::nowRDirectionLEFT() {
//     if (isExitUp())
//         return Direction::UP;
//     else if (isExitRight())
//         return Direction::RIGHT;
//     else if (isExitDown())
//         return Direction::RIGHT;
//     else if (isExitLeft())
//         return Direction::DOWN;
    //
    if (isFreeUp())
        return currDirection = Direction::UP;
    else if (isFreeRight())
        return Direction::RIGHT;
    else if (isFreeDown())
        return currDirection = Direction::DOWN;
    else 
        return currDirection = Direction::LEFT;
}

Direction Runner::nowDDirectionLEFT() {
//     if (isExitRight())
//         return Direction::RIGHT;
//     else if (isExitDown())
//         return Direction::DOWN;
//     else if (isExitLeft())
//         return Direction::LEFT;
    if (isFreeRight())
        return currDirection = Direction::RIGHT;
    else if (isFreeDown())
        return currDirection = Direction::DOWN;
    else if (isFreeLeft())
        return currDirection = Direction::LEFT;
    else 
        return currDirection = Direction::UP;
}

Direction Runner::nowLDirectionLEFT() {
//     if (isExitDown())
//         return Direction::DOWN;
//     if (isExitUp())
//         return Direction::UP;
//     else if (isExitLeft())
//         return Direction::LEFT;
    if (isFreeDown())
        return currDirection = Direction::DOWN;
    else if (isFreeLeft())
        return Direction::LEFT;
    else if (isFreeUp())
        return currDirection = Direction::UP;
    else
        return currDirection = Direction::RIGHT;
}

