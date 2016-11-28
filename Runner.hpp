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
	Runner(): i(1000), j(1000) {
		map.resize(2001);
		for (auto& row : map)
			row.resize(2001);
		map[i][j] = 1;
    }
	const std::vector<Direction> directions = 
	{Direction::UP, Direction::DOWN,
	 Direction::LEFT, Direction::RIGHT};
	std::vector<std::vector<int>> map;
	int i;
	int j;
    Direction step();
};




#endif //LABYRINTH_RUNNER_HPP
