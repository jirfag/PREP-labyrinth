#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


Direction Runner::step() {
        if (current_status.up == BlockType::EXIT)
            return Direction::UP;
        if (current_status.down == BlockType::EXIT)
            return Direction::DOWN;
        if (current_status.right == BlockType::EXIT)
            return Direction::RIGHT;
        if (current_status.left == BlockType::EXIT)
            return Direction::LEFT;

        if (currDirection == Direction::UP) {
            if (current_status.left != BlockType::WALL)
                return currDirection = Direction::LEFT;

            if (current_status.up != BlockType::WALL)
                return Direction::UP;

            if (current_status.right != BlockType::WALL)
                return currDirection = Direction::RIGHT;

                return currDirection = Direction::DOWN;
        }
        if (currDirection == Direction::DOWN) {
            if (current_status.right != BlockType::WALL)
                return currDirection = Direction::RIGHT;

            if (current_status.down != BlockType::WALL)
                return currDirection = Direction::DOWN;

            if (current_status.left != BlockType::WALL)
                return currDirection = Direction::LEFT;

                return currDirection = Direction::UP;
        }
        if (currDirection == Direction::LEFT) {
            if (current_status.down != BlockType::WALL)
                return currDirection = Direction::DOWN;

            if (current_status.left != BlockType::WALL)
                return currDirection = Direction::LEFT;

            if (current_status.up != BlockType::WALL)
                return currDirection = Direction::UP;

                return currDirection = Direction::RIGHT;
        }

            if (current_status.up != BlockType::WALL)
                return currDirection = Direction::UP;

            if (current_status.right != BlockType::WALL)
                return Direction::RIGHT;

            if (current_status.down != BlockType::WALL)
                return currDirection = Direction::DOWN;

            if (current_status.left != BlockType::WALL)
                return currDirection = Direction::LEFT;

    return currDirection;
}
