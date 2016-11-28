//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Direction Runner::step()
{
    // TODO: you need to replace the code below with your implementation of labyrinth solver.
    // Now here is the stupid implementation with random choicing of direction.
    const std::vector<Direction> directions = {Direction::UP, Direction::LEFT, Direction::DOWN, Direction::RIGHT};

    Direction dir;
    if (last_step == Direction::UP){
        if((current_status.up != BlockType::WALL) && (current_status.up != BlockType::ENTER))
            return last_step;
    }
    else if (last_step == Direction::LEFT){
        if((current_status.left != BlockType::WALL) && (current_status.left != BlockType::ENTER))
            return last_step;
    }
    else if (last_step == Direction::DOWN){
        if((current_status.down != BlockType::WALL) && (current_status.down != BlockType::ENTER))
            return last_step;
    }
    else {
        if((current_status.right != BlockType::WALL) && (current_status.right != BlockType::ENTER))
            return last_step;
    }

    do
        dir = directions[rand() % 4];
    while (dir == last_step);
    return last_step = dir;
}
