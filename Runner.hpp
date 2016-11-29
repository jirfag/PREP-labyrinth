//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <vector>

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
public:
    Runner();
    Direction step();

    std::vector<Direction> path;
    int i = 0;
};


#endif //LABYRINTH_RUNNER_HPP
