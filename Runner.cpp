#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


Direction Runner::step() {
    switch (currDirection) {
        case Direction::UP: {
            if (current_status.left != BlockType::WALL)
                return currDirection = Direction::LEFT;

            else if (current_status.up != BlockType::WALL)
                return Direction::UP;

            else if (current_status.right != BlockType::WALL)
                return currDirection = Direction::RIGHT;

            else
                return currDirection = Direction::DOWN;
        }
        case Direction::DOWN: {
            if (current_status.right != BlockType::WALL)
                return currDirection = Direction::RIGHT;

            else if (current_status.down != BlockType::WALL)
                return currDirection = Direction::DOWN;

            else if (current_status.left != BlockType::WALL)
                return currDirection = Direction::LEFT;

            else
                return currDirection = Direction::UP;
        }
        case Direction::LEFT:{
            if (current_status.down != BlockType::WALL)
                return currDirection = Direction::DOWN;

            else if (current_status.left != BlockType::WALL)
                return currDirection = Direction::LEFT;

            else if (isFreeUp())
                return currDirection = Direction::UP;
            else
                return currDirection = Direction::RIGHT;
        }
        case Direction::RIGHT:{
            if (current_status.up != BlockType::WALL)
                return currDirection = Direction::UP;

            else if (current_status.right != BlockType::WALL)
                return Direction::RIGHT;

            else if (current_status.down != BlockType::WALL)
                return currDirection = Direction::DOWN;

            else
                return currDirection = Direction::LEFT;
        }
        default:
            return Direction ::RIGHT;
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

    if (current_status.left != BlockType::WALL)
        return currDirection = Direction::LEFT;
    else if (current_status.down != BlockType::WALL)
        return currDirection = Direction::DOWN;
    else if (current_status.right != BlockType::WALL)
        return currDirection = Direction::RIGHT;
    else
        return currDirection = Direction::UP;
}

Direction Runner::nowDirectionU() {
    if (isExitLeft()) {
        return Direction::LEFT;
    }
    else if (isExitUp()) {
        return Direction::UP;
    }

    if (current_status.right != BlockType::WALL)
        return currDirection = Direction::RIGHT;
    else if (current_status.up != BlockType::WALL)
        return Direction::UP;
    else if (current_status.left != BlockType::WALL)
        return currDirection = Direction::LEFT;
    else
        return currDirection = Direction::DOWN;
}

Direction Runner::nowDirectionR() {
    if (isExitUp())
        return Direction::UP;

    else if (isExitRight())
        return Direction::RIGHT;

    if (current_status.down != BlockType::WALL)
        return currDirection = Direction::DOWN;

    else if (current_status.right != BlockType::WALL)
        return Direction::RIGHT;

    else if (current_status.up != BlockType::WALL)
        return currDirection = Direction::UP;

    else
        return currDirection = Direction::LEFT;
}

Direction Runner::nowDirectionL() {
    if (isExitDown())
        return Direction::DOWN;

    else if (isExitLeft())
        return Direction::LEFT;

    if (current_status.up != BlockType::WALL)
        return currDirection = Direction::UP;

    else if (current_status.left != BlockType::WALL)
        return Direction::LEFT;

    else if (current_status.down != BlockType::WALL)
        return currDirection = Direction::DOWN;

    else
        return currDirection = Direction::RIGHT;
}



Direction Runner::nowUDirectionLEFT() {
//    if (isExitLeft())
//        return Direction::LEFT;
//
//    else if (isExitUp())
//        return Direction::UP;

    if (current_status.left != BlockType::WALL)
        return currDirection = Direction::LEFT;

    else if (current_status.up != BlockType::WALL)
        return Direction::UP;

    else if (current_status.right != BlockType::WALL)
        return currDirection = Direction::RIGHT;

    else
        return currDirection = Direction::DOWN;
}

Direction Runner::nowRDirectionLEFT() {
//    if (isExitUp())
//        return Direction::UP;
//
//    else if (isExitRight())
//        return Direction::RIGHT;
//
//    else if (isExitDown())
//        return Direction::DOWN;

    if (current_status.up != BlockType::WALL)
        return currDirection = Direction::UP;

    else if (current_status.right != BlockType::WALL)
        return Direction::RIGHT;

    else if (current_status.down != BlockType::WALL)
        return currDirection = Direction::DOWN;

    else
        return currDirection = Direction::LEFT;
}

Direction Runner::nowDDirectionLEFT() {
//    if (isExitRight())
//        return Direction::RIGHT;
//
//    else if (isExitDown())
//        return Direction::DOWN;
//
//    else if (isExitLeft())
//        return Direction::LEFT;

    if (current_status.right != BlockType::WALL)
        return currDirection = Direction::RIGHT;

    else if (current_status.down != BlockType::WALL)
        return currDirection = Direction::DOWN;

    else if (current_status.left != BlockType::WALL)
        return currDirection = Direction::LEFT;

    else
        return currDirection = Direction::UP;
}

Direction Runner::nowLDirectionLEFT() {
//    if (isExitDown())
//        return Direction::DOWN;
//
//    else if (isExitLeft())
//        return Direction::LEFT;

    if (current_status.down != BlockType::WALL)
        return currDirection = Direction::DOWN;

    else if (current_status.left != BlockType::WALL)
        return currDirection = Direction::LEFT;

    else if (isFreeUp())
        return currDirection = Direction::UP;
    else
        return currDirection = Direction::RIGHT;
}
