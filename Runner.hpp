#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
#include <vector>

struct node{

	Direction reverse;
	Direction right_dir;
	int freeWays = 4;
};



class Runner: public RunnerBase {
private:
	Direction prevMove;
	std::vector <node> myvec;
	bool goForward = true;
	int steps;
public:
   	Runner();
   	void fill_node(node& n);
   	void MoveForward(Direction& prevMove, node&  n);
   	void MoveBack(Direction& prevMove);

    Direction step();

};

#endif
