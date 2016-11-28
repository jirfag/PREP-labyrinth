//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

using namespace std;

class Runner: public RunnerBase {
    public:
	Runner(): i(1), look(Direction::DOWN) {}
	int i;
	Direction look;
	Direction step();
	Direction step_right();
	Direction step_left();
};


#endif //LABYRINTH_RUNNER_HPP
