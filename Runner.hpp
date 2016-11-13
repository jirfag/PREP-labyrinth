//
// Created by tsv on 09.05.16.
//
#include <iostream>
#include <vector>
#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
public:
    Runner() : angle(0) {}
    Direction step();
    void set_angle(char new_angle);
    void turn(char);
    Direction turn_directions();
private:
    //BlockType stat_ex = BlockType::EXIT;
    char angle;
    Status turn_coord;
    const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
};


#endif //LABYRINTH_RUNNER_HPP
