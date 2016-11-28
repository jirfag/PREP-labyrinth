//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <vector>
#include "RunnerBase.hpp"

using namespace std;

class Runner: public RunnerBase {
    public:
        Direction step();

};

#endif //LABYRINTH_RUNNER_HPP
