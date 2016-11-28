//
// Created by tsv on 09.05.16.
//


#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

#include "vector"

struct node {
    Direction dir;
    bool Up = false;
    bool Down = false;
    bool Right = false;
    bool Left = false;

};

class Runner: public RunnerBase {
private:
    std::vector<node> v;
public:

    bool turn_back();
    Direction step();

};

#endif //LABYRINTH_RUNNER_HPP
