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
    Runner(){prev_directions = Direction::RIGHT;}
    Direction step();
//    void set_angle(signed char new_angle);
//    void turn(char);
//    Direction turn_directions();
private:
//    short int angle;
//    Status turn_coord;
BlockType up;
    BlockType right;
    BlockType down;
    BlockType left;
    Direction prev_directions ;
};


#endif //LABYRINTH_RUNNER_HPP
