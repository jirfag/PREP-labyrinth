//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <cstdlib>
#include "utils.hpp"

	
using namespace std;

Direction Runner::step() {
	
    switch (prev) {

        case(Direction::UP):
            if (current_status.left != BlockType::WALL) {
                return (prev = Direction::LEFT);
            }
            if (current_status.up != BlockType::WALL) {
                return (prev = Direction::UP);
            }
            if (current_status.right != BlockType::WALL) {
                return (prev = Direction::RIGHT);
            }
            if (current_status.down != BlockType::WALL) {
                return (prev = Direction::DOWN);
            }

        case(Direction::DOWN):
            if (current_status.right != BlockType::WALL) {
                return (prev = Direction::RIGHT);
            }
            if (current_status.down != BlockType::WALL) {
                return (prev = Direction::DOWN);
            }
            if (current_status.left != BlockType::WALL) {
                return (prev = Direction::LEFT);
            }
            if (current_status.up != BlockType::WALL) {
                return (prev = Direction::UP);
            }

        case(Direction::RIGHT):
            if (current_status.up != BlockType::WALL) {
                return (prev = Direction::UP);
            }
            if (current_status.right != BlockType::WALL) {
                return (prev = Direction::RIGHT);
            }
            if (current_status.down != BlockType::WALL) {
                 return (prev = Direction::DOWN);
            }
            if (current_status.left != BlockType::WALL) {
                return (prev = Direction::LEFT);
            }

        case(Direction::LEFT):
            if (current_status.down != BlockType::WALL) {
                return (prev = Direction::DOWN);
            }
            if (current_status.left != BlockType::WALL) {
                return (prev = Direction::LEFT);
            }
            if (current_status.up != BlockType::WALL) {
                return (prev = Direction::UP);
            }
            if (current_status.right != BlockType::WALL) {
                return (prev = Direction::RIGHT);
            }
    }
    return Direction::DOWN;
}
