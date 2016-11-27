#include "Runner.hpp"
#include "utils.hpp"

short int direction = 0;

Direction Runner::step()
{

    if(direction == 0) {
            if (current_status.left == BlockType::FREE) {
            	direction = 2;
                return Direction::LEFT;
            }
            else if (current_status.up == BlockType::FREE) {
            	direction = 0;
                return Direction::UP;
            }
            else if (current_status.right == BlockType::FREE) {
            	direction = 3;
                return Direction::RIGHT;
            }
            else {
            	direction = 1;
                return Direction::DOWN;
            }
        }
        if(direction == 1) {
            if (current_status.right == BlockType::FREE) {
            	direction = 3;
                return Direction::RIGHT;
            }
            else if (current_status.down == BlockType::FREE) {
            	direction = 1;
                return Direction::DOWN;
            }
            else if (current_status.left == BlockType::FREE) {
            	direction = 2;
                return Direction::LEFT;
            }
            else {
            	direction = 0;
                return Direction::UP;
            }
        }
        if(direction == 2) {
            if (current_status.down == BlockType::FREE) {
            	direction = 1;
                return Direction::DOWN;
            }
            else if (current_status.left == BlockType::FREE) {
            	direction = 2;
                return Direction::LEFT;
            }
            else if (current_status.up == BlockType::FREE) {
            	direction = 0;
                return Direction::UP;
            }
            else {
            	direction = 3;
                return Direction::RIGHT;
            }
        }
        if(direction == 3) {
            if (current_status.up == BlockType::FREE) {
            	direction = 0;
                return Direction::UP;
            }
            else if (current_status.right == BlockType::FREE) {
            	direction = 3;
                return Direction::RIGHT;
            }
            else if (current_status.down == BlockType::FREE) {
            	direction = 1;
                return Direction::DOWN;
            }
            else {
            	direction = 2;
                return Direction::LEFT;
            }
        }
    if (current_status.up == BlockType::EXIT)
        return Direction::UP;

    if (current_status.down == BlockType::EXIT)
        return Direction::DOWN;

    if (current_status.left == BlockType::EXIT)
        return Direction::LEFT;

    if (current_status.right == BlockType::EXIT)
        return Direction::RIGHT;
}
