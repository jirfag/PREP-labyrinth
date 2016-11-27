#include "Runner.hpp"

bool RETURN = false;
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
            if ( RETURN ) {
                if ( current_status.left == BlockType::FREE ) {
                    if ( current_status.up == BlockType::FREE || current_status.right == BlockType::FREE ) {
                        RETURN = false;
                    }
                    PrevStep = Direction::LEFT;
                    return Direction::LEFT;
                } else if ( current_status.up == BlockType::FREE ) {
                    if ( current_status.right == BlockType::FREE ) {
                        RETURN = false;
                    }
                    PrevStep = Direction::UP; //
                    return Direction::UP;
                } else if ( current_status.right == BlockType::FREE ) {
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                } else {
                    PrevStep = Direction::DOWN;
                    return Direction::DOWN;
                }
            } else {
                if ( current_status.up == BlockType::FREE ) {
                    PrevStep = Direction::UP;
                    return Direction::UP;
                } else if ( current_status.left == BlockType::FREE ) {
                    PrevStep = Direction::LEFT; //
                    return Direction::LEFT;
                } else if ( current_status.right == BlockType::FREE ) {
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                } else {
                    RETURN = true;
                    PrevStep = Direction::DOWN;
                    return Direction::DOWN;
                }
            }
        }
        case Direction::LEFT: {
            if ( RETURN ) {
                if ( current_status.down == BlockType::FREE ) {
                    if ( current_status.left == BlockType::FREE || current_status.up == BlockType::FREE ) {
                        RETURN = false;
                    }
                    PrevStep = Direction::DOWN;
                    return Direction::DOWN;
                } else if ( current_status.left == BlockType::FREE ) {
                    if ( current_status.up == BlockType::FREE ) {
                        RETURN = false;
                    }
                    PrevStep = Direction::LEFT;//
                    return Direction::LEFT;
                } else if ( current_status.up == BlockType::FREE ) {
                    PrevStep = Direction::UP;
                    return Direction::UP;
                } else {
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                }
            } else {
                if ( current_status.left == BlockType::FREE ) {
                    PrevStep = Direction::LEFT;
                    return Direction::LEFT;
                } else if ( current_status.down == BlockType::FREE ) {
                    PrevStep = Direction::DOWN;//
                    return Direction::DOWN;
                } else if ( current_status.up == BlockType::FREE ) {
                    PrevStep = Direction::UP;
                    return Direction::UP;
                } else {
                    RETURN = true;
                    PrevStep = Direction::RIGHT;
                    return Direction::RIGHT;
                }
            }
            case Direction::DOWN: {
                if ( RETURN ) {
                    if ( current_status.right == BlockType::FREE ) {
                        if ( current_status.left == BlockType::FREE || current_status.down == BlockType::FREE ) {
                            RETURN = false;
                        }
                        PrevStep = Direction::RIGHT;
                        return Direction::RIGHT;
                    } else if ( current_status.down == BlockType::FREE ) {
                        if ( current_status.left == BlockType::FREE ) {
                            RETURN = false;
                        }
                        PrevStep = Direction::DOWN;//
                        return Direction::DOWN;
                    } else if ( current_status.left == BlockType::FREE ) {
                        PrevStep = Direction::LEFT;
                        return Direction::LEFT;
                    } else {
                        PrevStep = Direction::UP;
                        return Direction::UP;
                    }
                } else {
                    if ( current_status.down == BlockType::FREE ) {
                        PrevStep = Direction::DOWN;
                        return Direction::DOWN;
                    } else if ( current_status.right == BlockType::FREE ) {
                        PrevStep = Direction::RIGHT;//
                        return Direction::RIGHT;
                    } else if ( current_status.left == BlockType::FREE ) {
                        PrevStep = Direction::LEFT;
                        return Direction::LEFT;
                    } else {
                        RETURN = true;
                        PrevStep = Direction::UP;
                        return Direction::UP;
                    }
                }
            }
            default: {
                if ( RETURN ) {
                    if ( current_status.up == BlockType::FREE ) {
                        if ( current_status.right == BlockType::FREE || current_status.down == BlockType::FREE ) {
                            RETURN = false;
                        }
                        PrevStep = Direction::UP;
                        return Direction::UP;
                    } else if ( current_status.right == BlockType::FREE ) {
                        if ( current_status.down == BlockType::FREE ) {
                            RETURN = false;
                        }
                        PrevStep = Direction::RIGHT; //
                        return Direction::RIGHT;
                    } else if ( current_status.down == BlockType::FREE ) {
                        PrevStep = Direction::DOWN;
                        return Direction::DOWN;
                    } else {
                        PrevStep = Direction::LEFT;
                        return Direction::LEFT;
                    }
                } else {
                    if ( current_status.right == BlockType::FREE ) {
                        PrevStep = Direction::RIGHT;
                        return Direction::RIGHT;
                    } else if ( current_status.up == BlockType::FREE ) {
                        PrevStep = Direction::UP; //
                        return Direction::UP;
                    } else if ( current_status.down == BlockType::FREE ) {
                        PrevStep = Direction::DOWN;
                        return Direction::DOWN;
                    } else {
                        RETURN = true;
                        PrevStep = Direction::LEFT;
                        return Direction::LEFT;
                    }
                }
            }
        }
    }
}
