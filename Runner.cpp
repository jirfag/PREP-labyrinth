//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"

Direction Runner::step() {
//    if (current_status.left == BlockType::EXIT) {
//        // const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
//        return Direction::LEFT;
//    } else if (current_status.right == BlockType::EXIT) {
//        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
//        return Direction::RIGHT;
//    } else if (current_status.up == BlockType::EXIT) {
//        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
//        return Direction::UP;
//    } else if (current_status.down == BlockType::EXIT) {
//        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
//        return Direction::DOWN;
//    }

    switch (prev_directions) {
        case Direction::UP: {
            if (current_status.left == BlockType::WALL && (current_status.up == BlockType::FREE || current_status.up == BlockType::EXIT)) {
//                if (current_status.right == BlockType::EXIT) {
//                    return Direction::RIGHT;
//                }
                prev_directions = Direction::UP;
                return Direction::UP;
            }
            else if (current_status.left == BlockType::FREE) {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            } else if (current_status.left == BlockType::WALL && current_status.up == BlockType::WALL &&
                       current_status.right == BlockType::FREE) {
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            } else {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            }
        }
        case Direction::LEFT: {
            if (current_status.down == BlockType::WALL && (current_status.left == BlockType::FREE || current_status.left == BlockType::EXIT)) {
                prev_directions = Direction::LEFT;
//                if (current_status.up == BlockType::EXIT) {
//                    return Direction::UP;
//                } else if (current_status.right == BlockType::EXIT) {
//                    return Direction::RIGHT;
//                } else if (current_status.down == BlockType::EXIT) {
//                    return Direction::DOWN;
//                }
                return Direction::LEFT;
            } else if (current_status.down == BlockType::FREE) {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            } else if (current_status.down == BlockType::WALL && current_status.left == BlockType::WALL &&
                       current_status.up == BlockType::FREE) {
                prev_directions = Direction::UP;
                return Direction::UP;
            } else {
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            }
        }
        case Direction::DOWN: {
            if (current_status.right == BlockType::WALL && (current_status.down == BlockType::FREE || current_status.down == BlockType::EXIT)) {
//                if (current_status.up == BlockType::EXIT) {
//                    return Direction::UP;
//                } else if (current_status.right == BlockType::EXIT) {
//                    return Direction::RIGHT;
//                } else if (current_status.left == BlockType::EXIT) {
//                    return Direction::LEFT;
//                }
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            } else if (current_status.right == BlockType::FREE) {
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            } else if (current_status.right == BlockType::WALL && current_status.down == BlockType::WALL &&
                       current_status.left == BlockType::FREE) {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            } else {
                prev_directions = Direction::UP;
                return Direction::UP;
            }
        }
        case Direction::RIGHT: {
            if (current_status.up == BlockType::WALL && (current_status.right == BlockType::FREE || current_status.up == BlockType::EXIT)) {
//                if (current_status.up == BlockType::EXIT) {
//                    return Direction::UP;
//                } else if (current_status.left == BlockType::EXIT) {
//                    return Direction::LEFT;
//                } else if (current_status.down == BlockType::EXIT) {)
//                    return Direction::DOWN;
//                }
                prev_directions = Direction::RIGHT;
                return Direction::RIGHT;
            } else if (current_status.up == BlockType::FREE) {
                prev_directions = Direction::UP;
                return Direction::UP;
            } else if (current_status.up == BlockType::WALL && current_status.right == BlockType::WALL &&
                       current_status.down == BlockType::FREE) {
                prev_directions = Direction::DOWN;
                return Direction::DOWN;
            } else {
                prev_directions = Direction::LEFT;
                return Direction::LEFT;
            }
        }
    }
    return Direction::LEFT;
}
//        case 180: {
//        turn_coord.up = current_status.down;
//        turn_coord.left = current_status.right;
//        turn_coord.down = current_status.up;
//        turn_coord.right = current_status.left;
//            break;
//        }
//    }
//
//
//    switch(turn_coord.left) {
//        case BlockType::WALL: {
//            if (turn_coord.up == BlockType::FREE) {
//                if (angle == 0)
//                    return Direction::UP;
//                else if (angle == 90)
//                    return Direction::LEFT;
//                else if (angle == -90)
//                    return Direction::RIGHT;
//                else
//                    return Direction::DOWN;
//            } else if (turn_coord.up == BlockType::WALL && turn_coord.right == BlockType::FREE) {
//                angle = (angle + -90);
//                if (angle <= 180 && angle >= -90);
//                else
//                    angle = angle + (angle > 180 ? (-360) : (360));
//                if (angle == 0)
//                    return Direction::UP;
//                else if (angle == 90)
//                    return Direction::LEFT;
//                else if (angle == -90)
//                    return Direction::RIGHT;
//                else
//                    return Direction::DOWN;
//            }
//            else
//                angle = (angle + 180);
//            if (angle <= 180 && angle >= -90);
//            else
//                angle = angle + (angle > 180 ? (-360) : (360));
//            if (angle == 0)
//                return Direction::UP;
//            else if (angle == 90)
//                return Direction::LEFT;
//            else if (angle == -90)
//                return Direction::RIGHT;
//            else
//                return Direction::DOWN;
//
//        }
//        case BlockType::FREE: {
//            angle = (angle + 90);
//            if (angle <= 180 && angle >= -90);
//            else
//                angle = angle + (angle > 180 ? (-360) : (360));
//            if (angle == 0)
//                return Direction::UP;
//            else if (angle == 90)
//                return Direction::LEFT;
//            else if (angle == -90)
//                return Direction::RIGHT;
//            else
//                return Direction::DOWN;
//        }
//        case BlockType::ENTER: {
//            break;
//        }
//        case BlockType::EXIT: {
//            break;
////
//        }
//    }
//
//            return Direction::DOWN;
