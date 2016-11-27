//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Direction Runner::step() {

   if (current_status.up == BlockType::EXIT) {
        return Direction::UP;
    }else if (current_status.left == BlockType::EXIT) {
        return Direction::LEFT;
    }else if (current_status.right == BlockType::EXIT) {
        return Direction::RIGHT;
    }else if (current_status.down == BlockType::EXIT) {
        return Direction::DOWN;
    }

    if (course == Direction::UP){
        if ( current_status.left == BlockType::FREE ) {
            return course = Direction::LEFT;
        } else if ( current_status.up == BlockType::FREE ) {
            return course = Direction::UP;
        } else if ( current_status.right == BlockType::FREE ) {
            return course = Direction::RIGHT;
        } else {
            return course = Direction::DOWN;
        }
    }else  if (course == Direction::LEFT){
        if ( current_status.down == BlockType::FREE ) {
            return course = Direction::DOWN;
        } else if ( current_status.left == BlockType::FREE ) {
            return course = Direction::LEFT;
        } else if ( current_status.up == BlockType::FREE ) {
            return course = Direction::UP;
        } else {
            return course = Direction::RIGHT;
        }
    }else if (course == Direction::DOWN){
        if ( current_status.right == BlockType::FREE ) {
            return course = Direction::RIGHT;
        } else if ( current_status.down == BlockType::FREE ) {
            return course = Direction::DOWN;
        } else if ( current_status.left == BlockType::FREE  ) {
            return course = Direction::LEFT;
        } else {
            return course = Direction::UP;
        }
    }else if (course == Direction::RIGHT){
        if (current_status.up == BlockType::FREE)
            return course = Direction::UP;
        else if (current_status.right == BlockType::FREE)
            return course = Direction::RIGHT;
        else if (current_status.down == BlockType::FREE)
            return course = Direction::DOWN;
        else
            return course = Direction::LEFT;
    }
    return course;

}
