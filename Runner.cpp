//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#define _0 0
#define _90 1
#define _m90 -1
#define _180 2

Direction Runner::step() {
    if (current_status.left == BlockType::EXIT) {
        // const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::LEFT;
    } else if (current_status.right == BlockType::EXIT) {
        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::RIGHT;
    } else if (current_status.up == BlockType::EXIT) {
        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::UP;
    } else if (current_status.down == BlockType::EXIT) {
        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::DOWN;
    }

    switch(angle) {
        case 0: {
            turn_coord.left = current_status.left;
            turn_coord.right = current_status.right;
            turn_coord.down = current_status.down;
            turn_coord.up = current_status.up;
            break;
        }
        case 90: {
            turn_coord.up = current_status.left;
            turn_coord.left = current_status.down;
            turn_coord.down = current_status.right;
            turn_coord.right = current_status.up;
            break;
        }
        case -90: {
        turn_coord.up = current_status.right;
        turn_coord.left = current_status.up;
        turn_coord.down = current_status.left;
        turn_coord.right = current_status.down;
            break;
        }
        case 180: {
        turn_coord.up = current_status.down;
        turn_coord.left = current_status.right;
        turn_coord.down = current_status.up;
        turn_coord.right = current_status.left;
            break;
        }
    }


    switch(turn_coord.left) {
        case BlockType::WALL: {
            if (turn_coord.up == BlockType::FREE) {
                if (angle == 0)
                    return Direction::UP;
                else if (angle == 90)
                    return Direction::LEFT;
                else if (angle == -90)
                    return Direction::RIGHT;
                else
                    return Direction::DOWN;
            } else if (turn_coord.up == BlockType::WALL && turn_coord.right == BlockType::FREE) {
                angle = (angle + -90);
                if (angle <= 180 && angle >= -90);
                else
                    angle = angle + (angle > 180 ? (-360) : (360));
                if (angle == 0)
                    return Direction::UP;
                else if (angle == 90)
                    return Direction::LEFT;
                else if (angle == -90)
                    return Direction::RIGHT;
                else
                    return Direction::DOWN;
            }
            else
                angle = (angle + 180);
            if (angle <= 180 && angle >= -90);
            else
                angle = angle + (angle > 180 ? (-360) : (360));
            if (angle == 0)
                return Direction::UP;
            else if (angle == 90)
                return Direction::LEFT;
            else if (angle == -90)
                return Direction::RIGHT;
            else
                return Direction::DOWN;

        }
        case BlockType::FREE: {
            angle = (angle + 90);
            if (angle <= 180 && angle >= -90);
            else
                angle = angle + (angle > 180 ? (-360) : (360));
            if (angle == 0)
                return Direction::UP;
            else if (angle == 90)
                return Direction::LEFT;
            else if (angle == -90)
                return Direction::RIGHT;
            else
                return Direction::DOWN;
        }
        case BlockType::ENTER: {
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
//                angle = (angle - 90);
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
        }
        case BlockType::EXIT: {
            ;
//            if (angle == 0)
//                return Direction::LEFT;
//            else if (angle == 90)
//                return Direction::DOWN;
//            else if (angle == -90)
//                return Direction::UP;
//            else
//                return Direction::RIGHT;
        }
    }
//    std::cout<< "fwf"<<std::endl;
//        angle = (angle + _180);
//        if (angle <= _180 && angle >= _m90);
//        else
//            angle = angle + (angle > _180 ? (-4) : (+4));
//        if (angle == _0)
//            return Direction::UP;
//        else if (angle == _90)
//            return Direction::LEFT;
//        else if (angle == _m90)
//            return Direction::RIGHT;
//        else
            return Direction::DOWN;
}