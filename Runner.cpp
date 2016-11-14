#include "Runner.hpp"

Direction PrevStep = Direction::UP;

Direction Runner::step() {
    if ( current_status.left == BlockType::EXIT ) {
        return Direction::LEFT;
    }

    if ( current_status.right == BlockType::EXIT ) {
        return Direction::RIGHT;
    }

    if ( current_status.up == BlockType::EXIT ) {
        return Direction::UP;
    }

    if ( current_status.down == BlockType::EXIT ) {
        return Direction::DOWN;
    }

    switch ( PrevStep ) {
        case Direction::UP: {
            if ( current_status.left == BlockType::FREE ) {
                PrevStep = Direction::LEFT;
                return Direction::LEFT;
            } else if ( current_status.up == BlockType::FREE ) {
                PrevStep = Direction::UP; //
                return Direction::UP;
            } else if ( current_status.right == BlockType::FREE ) {
                PrevStep = Direction::RIGHT;
                return Direction::RIGHT;
            } else {
                PrevStep = Direction::DOWN;
                return Direction::DOWN;
            }
        }
        case Direction::LEFT: {
            if ( current_status.down == BlockType::FREE ) {
                PrevStep = Direction::DOWN;
                return Direction::DOWN;
            } else if ( current_status.left == BlockType::FREE ) {
                PrevStep = Direction::LEFT;//
                return Direction::LEFT;
            } else if ( current_status.up == BlockType::FREE ) {
                PrevStep = Direction::UP;
                return Direction::UP;
            } else {
                PrevStep = Direction::RIGHT;
                return Direction::RIGHT;
            }
        }
        case Direction::DOWN: {
            if ( current_status.right == BlockType::FREE ) {
                PrevStep = Direction::RIGHT;
                return Direction::RIGHT;
            } else if ( current_status.down == BlockType::FREE ) {
                PrevStep = Direction::DOWN;//
                return Direction::DOWN;
            } else if ( current_status.left == BlockType::FREE  ) {
                PrevStep = Direction::LEFT;
                return Direction::LEFT;
            } else {
                PrevStep = Direction::UP;
                return Direction::UP;
            }
        }
        default: {
            if ( current_status.up == BlockType::FREE ) {
                PrevStep = Direction::UP;
                return Direction::UP;
            } else if ( current_status.right == BlockType::FREE ) {
                PrevStep = Direction::RIGHT; //
                return Direction::RIGHT;
            } else if ( current_status.down == BlockType::FREE ) {
                PrevStep = Direction::DOWN;
                return Direction::DOWN;
            } else {
                PrevStep = Direction::LEFT;
                return Direction::LEFT;
            }
        }
    }

}
