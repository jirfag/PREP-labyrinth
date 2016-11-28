//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
#include <ctime>
#include <cstdlib>

class Runner: public RunnerBase {
    public:

        Runner(){
            srand(time(0));
            last_step = Direction::UP;
        }

        Direction step();

    private:
        Direction last_step;
};


#endif //LABYRINTH_RUNNER_HPP
