//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

Direction Runner::step() {
    up = current_status.up;
    right = current_status.right;
    down = current_status.down;
    left = current_status.left;
    if (left == BlockType::EXIT) {
        // const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::LEFT;
    } else if (right == BlockType::EXIT) {
        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::RIGHT;
    } else if (up == BlockType::EXIT) {
        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::UP;
    } else if (down == BlockType::EXIT) {
        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::DOWN;
    }

    switch (prev_directions) {
        case Direction::DOWN:  {
            if (right == BlockType::FREE) {
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            }
            else if (down == BlockType::FREE) {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            } else if (left == BlockType::FREE) {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            } else {
                prev_directions = Direction::UP;
                return Direction::UP;
            }
        }
        case Direction::LEFT: {
            if (down == BlockType::FREE) {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            } else if (left == BlockType::FREE) {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            } else if (up == BlockType::FREE) {
                prev_directions = Direction::UP;
                return Direction::UP;
            } else {
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            }
        }
        case Direction::UP: {
            if (left == BlockType::FREE) {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            } else if (up == BlockType::FREE) {
                prev_directions = Direction::UP;
                return Direction::UP;
            } else if (right == BlockType::FREE) {
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            } else {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            }
        }
        default: {
            if(up == BlockType::FREE) {
                prev_directions = Direction::UP;
                return Direction::UP;
            }
            else if (right == BlockType::FREE){
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            }
            else if (down == BlockType::FREE) {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            } else {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            }
        }
    }
    return Direction::LEFT;
}

