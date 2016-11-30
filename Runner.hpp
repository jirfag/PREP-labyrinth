//
// Created by tsv on 09.05.16.
//
#include <iostream>
#include <vector>
#include <stack>
#include "utils.hpp"

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
public:
    Runner();
    Direction step();

private:
    std::vector<Direction> dir;
    Direction prev_directions ;
    int count;
};


#endif //LABYRINTH_RUNNER_HPP
