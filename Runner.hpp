#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP


#include "RunnerBase.hpp"


class Runner: public RunnerBase {
public:
    Runner() : currDirection(2){};
    Direction step();
    bool isFreeUp();
    bool isFreeDown();
    bool isFreeLeft();
    bool isFreeRight();

    Direction nowDirectionU();
    Direction nowDirectionR();
    Direction nowDirectionD();
    Direction nowDirectionL();

    Direction nowUDirectionLEFT();
    Direction nowRDirectionLEFT();
    Direction nowDDirectionLEFT();
    Direction nowLDirectionLEFT();

    bool isExitLeft();
    bool isExitDown();
    bool isExitUp();
    bool isExitRight();
private:
    size_t currDirection;
};
constexpr static Direction (Runner::*v[4])()  = {
        &Runner::nowLDirectionLEFT,
        &Runner::nowDDirectionLEFT,
        &Runner::nowRDirectionLEFT,
        &Runner::nowUDirectionLEFT
};

#endif //LABYRINTH_RUNNER_HPP
