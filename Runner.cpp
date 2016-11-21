#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


Direction Runner::step() {
  
    if (currDirection == Direction::UP) {
        if (current_status.up == BlockType::EXIT)
            return Direction::UP;

        if (current_status.right == BlockType::EXIT)
            return Direction::RIGHT;

        if (current_status.left == BlockType::FREE)
            return currDirection = Direction::LEFT;

        if (current_status.up == BlockType::FREE)
            return Direction::UP;

        if (current_status.right == BlockType::FREE)
            return currDirection = Direction::RIGHT;

        return currDirection = Direction::DOWN;
    }
        if (currDirection == Direction::DOWN) {
            if (current_status.down == BlockType::EXIT)
                return Direction::DOWN;
            if (current_status.right == BlockType::EXIT)
                return Direction::RIGHT;

            if (current_status.right == BlockType::FREE)
                return currDirection = Direction::RIGHT;

            if (current_status.down == BlockType::FREE)
                return currDirection = Direction::DOWN;

            if (current_status.left == BlockType::FREE)
                return currDirection = Direction::LEFT;

                return currDirection = Direction::UP;
        }
        if (currDirection == Direction::LEFT) {
            if (current_status.up == BlockType::EXIT)
                return Direction::UP;
            if (current_status.left == BlockType::EXIT)
                return Direction::LEFT;

            if (current_status.down == BlockType::FREE)
                return currDirection = Direction::DOWN;

            if (current_status.left == BlockType::FREE)
                return currDirection = Direction::LEFT;

            if (current_status.up == BlockType::FREE)
                return currDirection = Direction::UP;

                return currDirection = Direction::RIGHT;
        }
            if (current_status.up == BlockType::EXIT)
                return Direction::UP;
            if (current_status.right == BlockType::EXIT)
                return Direction::RIGHT;

            if (current_status.up == BlockType::FREE)
                return currDirection = Direction::UP;

            if (current_status.right == BlockType::FREE)
                return Direction::RIGHT;

            if (current_status.down == BlockType::FREE)
                return currDirection = Direction::DOWN;

            if (current_status.left == BlockType::FREE)
                return currDirection = Direction::LEFT;

    return currDirection;
}
