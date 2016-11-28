//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP
#include <vector>
#include "RunnerBase.hpp"


class Runner: public RunnerBase {
private:
    std::vector<node> v;
public:

    bool turn_back();
    Direction step();

};

struct node {
    Direction dir;
    bool Up = false;
    bool Down = false;
    bool Right = false;
    bool Left = false;

};


#endif //LABYRINTH_RUNNER_HPP
