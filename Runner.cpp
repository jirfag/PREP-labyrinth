//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#define _0 49
#define _90 50
#define _m90 48
#define _180 51

Direction Runner::step()
{
    if(current_status.left != BlockType::EXIT && current_status.right != BlockType::EXIT
       && current_status.up != BlockType::EXIT && current_status.down != BlockType::EXIT);
    else if(current_status.left == BlockType::EXIT){
        const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return directions[2];
    }
    else if(current_status.right == BlockType::EXIT) {
        const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return directions[3];
    }
    else if (current_status.up == BlockType::EXIT){
        const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return directions[0];
    }
    else if (current_status.down == BlockType::EXIT){
        const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        return directions[1];
    }

    turn(angle);

    if(turn_coord.left == BlockType::WALL && turn_coord.up == BlockType::FREE)
        return turn_directions();
    else if(turn_coord.left == BlockType::WALL && turn_coord.up == BlockType::WALL && turn_coord.right == BlockType ::FREE){
        set_angle(_m90);
        turn(angle);
        return turn_directions();
    }
    else if(turn_coord.left == BlockType::FREE) {
        set_angle(_90);
        turn(angle);
        return turn_directions();
    }
    else {
        set_angle(_180);
        turn(angle);
        return turn_directions();
    }
}


inline void Runner::turn(char angle)
{
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
}


inline void Runner::set_angle(char new_angle)
{
    angle = (angle + new_angle -_0);
    if (angle <= _180 && angle >= _0);
    else
        angle = angle + (angle > _180 ? (-4) : (+4));
}
//        angle = angle - 360;
//    else
//        angle = angle + 360;
//    if(angle == 0)
//        angle = new_angle;
//    else if(angle == 90 && (new_angle == 90 || new_angle == -90))
//        angle = angle + new_angle;
//    else if(angle == 180 && new_angle == 90)
//        angle = -90;
//    else if(angle == 180 && new_angle == -90)
//        angle = 90;
//    else if(angle == -90 && (new_angle == 90))
//        angle = 0;
//    else if(angle == -90 && new_angle == -90)
//        angle = 180;
//    else if(new_angle == 180 && (angle == 90 || angle == -90))
//        angle = -angle;
//    else if(new_angle == 180 && angle == 180)
//        angle = 0;
//    else
//        std::cout << "ERROR ANGLE" << new_angle << angle << std::endl;


inline Direction Runner::turn_directions()
{
    if(angle == _0)
        return directions[0];
    else if(angle == _90)
        return directions[2];
    else if(angle == _m90)
        return directions[3];
    else
        return directions[1];
}