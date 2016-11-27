#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP


#include "RunnerBase.hpp"


class Runner: public RunnerBase {
public:
    Runner() : currDirection(3){};
    Direction step();
private:
   short int currDirection;
};

#endif //LABYRINTH_RUNNER_HPP
