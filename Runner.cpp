#include "Runner.hpp"


Direction PrevStep = Direction::UP;

    Direction Runner::step() {
        BlockType L = current_status.left;
        BlockType R = current_status.right;
        BlockType U = current_status.up;
        BlockType D = current_status.down;


        if ( L == BlockType::EXIT ) {
            return Direction::LEFT;
        }

        if ( R == BlockType::EXIT ) {
            return Direction::RIGHT;
        }

        if ( U == BlockType::EXIT ) {
            return Direction::UP;
        }

        if ( D == BlockType::EXIT ) {
            return Direction::DOWN;
        }

        switch ( PrevStep ) {
            case Direction::UP: {
                if ( L == BlockType::FREE ) {
                    PrevStep = Direction::LEFT;
                    return Direction::LEFT;
                } else if ( U == BlockType::FREE ) {
                    PrevStep = Direction::UP; //
                    return Direction::UP;
                } else if ( R == BlockType::FREE ) {
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                } else {
                    PrevStep = Direction::DOWN;
                    return Direction::DOWN;
                }
            }
            case Direction::LEFT: {
                if ( D == BlockType::FREE ) {
                    PrevStep = Direction::DOWN;
                    return Direction::DOWN;
                } else if ( L == BlockType::FREE ) {
                    PrevStep = Direction::LEFT;//
                    return Direction::LEFT;
                } else if ( U == BlockType::FREE ) {
                    PrevStep = Direction::UP;
                    return Direction::UP;
                } else {
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                }
            }
            case Direction::DOWN: {
                if ( R == BlockType::FREE ) {
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                } else if ( D == BlockType::FREE ) {
                    PrevStep = Direction::DOWN;//
                    return Direction::DOWN;
                } else if ( L == BlockType::FREE ) {
                    PrevStep = Direction::LEFT;
                    return Direction::LEFT;
                } else {
                    PrevStep = Direction::UP;
                    return Direction::UP;
                }
            }
            default: {
                if ( U == BlockType::FREE ) {
                    PrevStep = Direction::UP;
                    return Direction::UP;
                } else if ( R == BlockType::FREE ) {
                    PrevStep = Direction::RIGHT; //
                    return Direction::RIGHT;
                } else if ( D == BlockType::FREE ) {
                    PrevStep = Direction::DOWN;
                    return Direction::DOWN;
                } else {
                    PrevStep = Direction::LEFT;
                    return Direction::LEFT;
                }
            }
        }
    }
