//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <vector>
#include "RunnerBase.hpp"

struct node;

class Runner: public RunnerBase {
private:
    std::vector<node> v;
public:
    Direction step();
    bool turn_back();

};

struct node {
    Direction dir;
    bool Up = false;
    bool Down = false;
    bool Right = false;
    bool Left = false;

};


#endif //LABYRINTH_RUNNER_HPP
