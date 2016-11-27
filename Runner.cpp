//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Direction Runner::step() {

   if ((course == Direction::UP) | (current_status.up == BlockType::EXIT)){
        if ( current_status.left == BlockType::FREE ) {
            return course = Direction::LEFT;
        } else if ( (current_status.up == BlockType::FREE)|(current_status.up == BlockType::EXIT)) {
            return course = Direction::UP;
        } else if ( current_status.right == BlockType::FREE ) {
            return course = Direction::RIGHT;
        } else {
            return course = Direction::DOWN;
        }
    }else  if ((course == Direction::LEFT) | (current_status.left == BlockType::EXIT)){
        if ( current_status.down == BlockType::FREE ) {
            return course = Direction::DOWN;
        } else if ( (current_status.left == BlockType::FREE)|(current_status.left == BlockType::EXIT)) {
            return course = Direction::LEFT;
        } else if ( current_status.up == BlockType::FREE ) {
            return course = Direction::UP;
        } else {
            return course = Direction::RIGHT;
        }
    }else if ((course == Direction::DOWN) | (current_status.down == BlockType::EXIT)){
        if ( current_status.right == BlockType::FREE ) {
            return course = Direction::RIGHT;
        } else if ( (current_status.down == BlockType::FREE)|(current_status.down == BlockType::EXIT) ) {
            return course = Direction::DOWN;
        } else if ( current_status.left == BlockType::FREE  ) {
            return course = Direction::LEFT;
        } else {
            return course = Direction::UP;
        }
    }else if ((course == Direction::RIGHT) | (current_status.right == BlockType::EXIT)){
        if (current_status.up == BlockType::FREE)
            return course = Direction::UP;
        else if ((current_status.right == BlockType::FREE)|(current_status.down == BlockType::EXIT))
            return course = Direction::RIGHT;
        else if (current_status.down == BlockType::FREE)
            return course = Direction::DOWN;
        else
            return course = Direction::LEFT;
    }
    return course;

}
