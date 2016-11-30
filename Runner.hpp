//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include<stack>
#include<vector>
#include "RunnerBase.hpp"

/*
 Приоритет шагов:
 Вверх
 Вниз
 Влево
 Вправо

 Если можем идти в заданную сторону, идём, пока можем. Упёрлись - идём далее по приоритету
 Не можем идти - откатываемся по стеку до момента, когда можем
 */

class Runner: public RunnerBase
{
//    struct coord;
//    {
//        int x = 0, y = 0;
//    };


private:

//    coord current;
//    Direction dir;

//    std::stack<Direction> stk;
//    std::vector<coord> passed;

//    bool hasPassed(coord &pos);
    Direction getDir();

public:
    Direction step();
};


#endif //LABYRINTH_RUNNER_HPP
