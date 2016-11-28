//
// Created by tsv on 09.05.16.
//
#include "Runner.hpp"
#include <vector>
#include "utils.hpp"

Direction Runner::step() 
{
    if (v.empty()) {
        node n;
        v.push_back(n);
    }
    if (turn_back()) {
        v.pop_back();
        if(v.back().dir == Direction::RIGHT)
            return Direction::LEFT;
        if(v.back().dir == Direction::LEFT)
            return Direction::RIGHT;
        if(v.back().dir == Direction::UP)
            return Direction::DOWN;
        if(v.back().dir == Direction::DOWN)
            return Direction::UP;
    }

    if (current_status.left == BlockType::EXIT) {
        return Direction::LEFT;
    }
    if (current_status.right == BlockType::EXIT) {
        return Direction::RIGHT;
    }
    if (current_status.down == BlockType::EXIT) {
        return Direction::DOWN;
    }
    if (current_status.up == BlockType::EXIT) {
        return Direction::UP;
    }
    if(current_status.right == BlockType::FREE && (!v.back().Right)){
        v.back().dir = Direction::RIGHT;
        v.back().Right = true;
        node n;
        n.Left = true;
        v.push_back(n);
        return Direction::RIGHT;
    }
    if (current_status.down == BlockType::FREE && (!v.back().Down)) {
        v.back().dir = Direction::DOWN;
        v.back().Down = true;
        node n;
        n.Up = true;
        v.push_back(n);
        return Direction::DOWN;
    }
    if (current_status.left == BlockType::FREE && (!v.back().Left)) {
        v.back().dir = Direction::LEFT;
        v.back().Left = true;
        node n;
        n.Right = true;
        v.push_back(n);
        return Direction::LEFT;
    }
    if (current_status.up == BlockType::FREE && (!v.back().Up)) {
        v.back().dir = Direction::UP;
        v.back().Up = true;
        node n;
        n.Down = true;
        v.push_back(n);
        return Direction::UP;        
    }
    return Direction::DOWN;
}


bool Runner::turn_back(){
    if ((current_status.right == BlockType::FREE || current_status.right == BlockType::EXIT ) && (!v.back().Right))
        return false;
    if ((current_status.down == BlockType::FREE || current_status.down == BlockType::EXIT ) && (!v.back().Down))
        return false;
    if ((current_status.up == BlockType::FREE || current_status.up == BlockType::EXIT ) && (!v.back().Up))
        return false;
    if ((current_status.left == BlockType::FREE || current_status.left == BlockType::EXIT ) && (!v.back().Left))
        return false;

    return true;
}
