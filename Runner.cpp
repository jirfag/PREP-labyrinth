//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include "utils.hpp"
#include <vector>
#include <algorithm>

Direction Runner::step()
{

    status = {current_status.up, current_status.left, current_status.down, current_status.right};

    it = std::find(status.begin(), status.end(), BlockType::EXIT);
    if (it != status.end())
            return directions[std::distance(status.begin(), it)];

    while(status[(last_step + 1) % 4] == BlockType::WALL){
        last_step = (last_step + 3) % 4;
    }

    last_step =(last_step + 1) % 4;

    return directions[last_step];
}

