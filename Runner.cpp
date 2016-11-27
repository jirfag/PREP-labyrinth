//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include "utils.hpp"

short int direction = 0;

Direction Runner::step()
{
    if (current_status.up == BlockType::EXIT)
        return Direction::UP;

    if (current_status.down == BlockType::EXIT)
        return Direction::DOWN;

    if (current_status.left == BlockType::EXIT)
        return Direction::LEFT;

    if (current_status.right == BlockType::EXIT)
        return Direction::RIGHT;

    switch(direction) {
        case 0: {
            if (current_status.left == BlockType::FREE) {
            	direction = 1;
                return Direction::LEFT;
            }
            else if (current_status.up == BlockType::FREE) {
            	direction = 1;
                return Direction::UP;
            }
            else if (current_status.right == BlockType::FREE) {
            	direction = 1;
                return Direction::RIGHT;
            }
            else {
            	direction = 1;
                return Direction::DOWN;
            }
        }
        case 1: {
            if (current_status.right == BlockType::FREE) {
            	direction = 4;
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
        case 2: {
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
            	direction = 4;
                return Direction::RIGHT;
            }
        }
        default: {
            if (current_status.up == BlockType::FREE) {
            	direction = 0;
                return Direction::UP;
            }
            else if (current_status.right == BlockType::FREE) {
            	direction = 4;
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
    }
}
