//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

using namespace std;

class Runner: public RunnerBase {
	public:
//	Runner() { prev = Direction::UP; }
//	Direction prev;
	Direction step();
};



#endif //LABYRINTH_RUNNER_HPP
