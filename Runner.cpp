//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#define _0 0
#define _90 1
#define _m90 -1
#define _180 2

Direction Runner::step()
{
    if(current_status.left != BlockType::EXIT && current_status.right != BlockType::EXIT
       && current_status.up != BlockType::EXIT && current_status.down != BlockType::EXIT);
    else if(current_status.left == BlockType::EXIT){
       // const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::LEFT;
    }
    else if(current_status.right == BlockType::EXIT) {
        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::RIGHT;
    }
    else if (current_status.up == BlockType::EXIT){
        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::UP;
    }
    else if (current_status.down == BlockType::EXIT){
        //const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return Direction::DOWN;
    }

    if(angle == _0)
    {
        turn_coord.left = current_status.left;
        turn_coord.right = current_status.right;
        turn_coord.down = current_status.down;
        turn_coord.up = current_status.up;
    }
    else if(angle == _90){
        turn_coord.up = current_status.left;
        turn_coord.left = current_status.down;
        turn_coord.down = current_status.right;
        turn_coord.right= current_status.up;
    }
    else if(angle == _m90){
        turn_coord.up = current_status.right;
        turn_coord.left = current_status.up;
        turn_coord.down  = current_status.left;
        turn_coord.right = current_status.down;
    }
    else if(angle == _180){
        turn_coord.up  = current_status.down;
        turn_coord.left = current_status.right;
        turn_coord.down = current_status.up;
        turn_coord.right = current_status.left;
    }

    if(turn_coord.left == BlockType::WALL && turn_coord.up == BlockType::FREE) {
        if(angle == _0)
            return Direction::UP;
        else if(angle == _90)
            return Direction::LEFT;
        else if(angle == _m90)
            return Direction::RIGHT;
        else
            return Direction::DOWN;
    }
    else if(turn_coord.left == BlockType::WALL && turn_coord.up == BlockType::WALL && turn_coord.right == BlockType ::FREE){
        angle = (angle + _m90);
        if (angle <= _180 && angle >= _m90);
        else
            angle = angle + (angle > _180 ? (-4) : (+4));

        if(angle == _0)
            return Direction::UP;
        else if(angle == _90)
            return Direction::LEFT;
        else if(angle == _m90)
            return Direction::RIGHT;
        else
            return Direction::DOWN;
    }
    else if(turn_coord.left == BlockType::FREE) {
        angle = (angle + _90);
        if (angle <= _180 && angle >= _m90);
        else
            angle = angle + (angle > _180 ? (-4) : (+4));
        if(angle == _0)
            return Direction::UP;
        else if(angle == _90)
            return Direction::LEFT;
        else if(angle == _m90)
            return Direction::RIGHT;
        else
            return Direction::DOWN;
    }
    else {
        angle = (angle + _180);
        if (angle <= _180 && angle >= _m90);
        else
            angle = angle + (angle > _180 ? (-4) : (+4));

        if(angle == _0)
            return Direction::UP;
        else if(angle == _90)
            return Direction::LEFT;
        else if(angle == _m90)
            return Direction::RIGHT;
        else
            return Direction::DOWN;
    }
}