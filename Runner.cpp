#include "Runner.hpp"

Direction PrevStep = Direction::UP;

Direction Runner::step() {
    switch ( PrevStep ) {
        case Direction::UP: {
            if ( ( current_status.left == BlockType::FREE ) | ( current_status.left == BlockType::EXIT ) ) {
                return PrevStep = Direction::LEFT;
            } else if ( ( current_status.up == BlockType::FREE ) | ( current_status.up == BlockType::EXIT ) ) {
                return PrevStep = Direction::UP;
            } else if ( ( current_status.right == BlockType::FREE ) | ( current_status.right == BlockType::EXIT ) ) {
                return PrevStep = Direction::RIGHT;
            } else {
                return PrevStep = Direction::DOWN;
            }
        }
        case Direction::LEFT: {
            if ( ( current_status.down == BlockType::FREE ) | ( current_status.down == BlockType::EXIT ) ) {
                return PrevStep = Direction::DOWN;
            } else if ( ( current_status.left == BlockType::FREE ) | ( current_status.left == BlockType::EXIT ) ) {
                return PrevStep = Direction::LEFT;
            } else if ( ( current_status.up == BlockType::FREE ) | ( current_status.up == BlockType::EXIT ) ) {
                return PrevStep = Direction::UP;
            } else {
                return PrevStep = Direction::RIGHT;
            }
        }
        case Direction::DOWN: {
            if ( ( current_status.right == BlockType::FREE ) | ( current_status.right == BlockType::EXIT ) ) {
                return PrevStep = Direction::RIGHT;
            } else if ( ( current_status.down == BlockType::FREE ) | ( current_status.down == BlockType::EXIT ) ) {
                return PrevStep = Direction::DOWN;
            } else if ( ( current_status.left == BlockType::FREE ) | ( current_status.left == BlockType::EXIT ) ) {
                return PrevStep = Direction::LEFT;
            } else {
                return PrevStep = Direction::UP;
            }
        }
        default: {
            if ( ( current_status.up == BlockType::FREE ) | ( current_status.up == BlockType::EXIT ) ) {
                return PrevStep = Direction::UP;
            } else if ( ( current_status.right == BlockType::FREE ) | ( current_status.right == BlockType::EXIT ) ) {
                return PrevStep = Direction::RIGHT;
            } else if ( ( current_status.down == BlockType::FREE ) | ( current_status.down == BlockType::EXIT ) ) {
                return PrevStep = Direction::DOWN;
            } else {
                return PrevStep = Direction::LEFT;
            }
        }
    }

}
