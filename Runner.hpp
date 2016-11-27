//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

class Runner: public RunnerBase {
    public:
        Direction step();
    private:
        Direction course  = Direction::UP;
};


#endif //LABYRINTH_RUNNER_HPP
