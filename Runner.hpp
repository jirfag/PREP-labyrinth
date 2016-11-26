//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"
#include <unordered_map>
#include <string>

class Runner: public RunnerBase {
    public:
        Direction step();
        Runner() : x(0),y(0) {
          path[foo(0,0)]=1;
        }
        std::string foo(int a,int b){
          return(std::to_string(a)+";"+std::to_string(b));
        }
        int x,y;
        std::unordered_map<std::string,bool> path;
};


#endif //LABYRINTH_RUNNER_HPP
