//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Direction Runner::step()
{
    // TODO: you need to replace the code below with your implementation of labyrinth solver.
    // Now here is the stupid implementation with random choicing of direction.
    const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
    std::system("cat Dungeon/lvl_1.txt");
    std::system("cat Dungeon/lvl_2.txt");
    std::system("cat Dungeon/lvl_3.txt");
    return directions[std::rand() % directions.size()];
}
