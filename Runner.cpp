#include "Runner.hpp"

Direction PrevPrevStep = Direction::UP;
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
            if ( PrevPrevStep == Direction::DOWN ) {
                if ( current_status.left == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::LEFT;
                    return Direction::LEFT;
                } else if ( current_status.up == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::UP; //
                    return Direction::UP;
                } else if ( current_status.right == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                } else {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::DOWN;
                    return Direction::DOWN;
                }
            } else {
                if ( current_status.up == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::UP;
                    return Direction::UP;
                } else if ( current_status.left == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::LEFT; //
                    return Direction::LEFT;
                } else if ( current_status.right == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                } else {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::DOWN;
                    return Direction::DOWN;
                }
            }
        }
        case Direction::LEFT: {
            if ( PrevPrevStep == Direction::RIGHT ) {
                if ( current_status.down == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::DOWN;
                    return Direction::DOWN;
                } else if ( current_status.left == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::LEFT;//
                    return Direction::LEFT;
                } else if ( current_status.up == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::UP;
                    return Direction::UP;
                } else {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                }
            } else {
                if ( current_status.left == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::LEFT;
                    return Direction::LEFT;
                } else if ( current_status.down == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::DOWN;//
                    return Direction::DOWN;
                } else if ( current_status.up == BlockType::FREE ) {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::UP;
                    return Direction::UP;
                } else {
                    PrevPrevStep = PrevStep;
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                }
            }
            case Direction::DOWN: {
                if ( PrevPrevStep == Direction::UP ) {
                    if ( current_status.right == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::RIGHT;
                        return Direction::RIGHT;
                    } else if ( current_status.down == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::DOWN;//
                        return Direction::DOWN;
                    } else if ( current_status.left == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::LEFT;
                        return Direction::LEFT;
                    } else {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::UP;
                        return Direction::UP;
                    }
                } else {
                    if ( current_status.down == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::DOWN;
                        return Direction::DOWN;
                    } else if ( current_status.right == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::RIGHT;//
                        return Direction::RIGHT;
                    } else if ( current_status.left == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::LEFT;
                        return Direction::LEFT;
                    } else {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::UP;
                        return Direction::UP;
                    }
                }
            }
            default: {
                if ( PrevPrevStep == Direction::LEFT ) {
                    if ( current_status.up == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::UP;
                        return Direction::UP;
                    } else if ( current_status.right == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::RIGHT; //
                        return Direction::RIGHT;
                    } else if ( current_status.down == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::DOWN;
                        return Direction::DOWN;
                    } else {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::LEFT;
                        return Direction::LEFT;
                    }
                } else {
                    if ( current_status.right == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::RIGHT;
                        return Direction::RIGHT;
                    } else if ( current_status.up == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::UP; //
                        return Direction::UP;
                    } else if ( current_status.down == BlockType::FREE ) {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::DOWN;
                        return Direction::DOWN;
                    } else {
                        PrevPrevStep = PrevStep;
                        PrevStep = Direction::LEFT;
                        return Direction::LEFT;
                    }
                }
            }
        }
    }
}
