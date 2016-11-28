//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include "utils.hpp"
#include <vector>
#include <algorithm>

Direction Runner::step()
{

    status = {current_status.up, current_status.right, current_status.down, current_status.left};

    it = std::find(status.begin(), status.end(), BlockType::EXIT);
    if (it != status.end())
            return directions[std::distance(status.begin(), it)];

    int step = (last_step + 1) % 4;
    while(status[step] == BlockType::WALL){
        step = (step + 3) % 4;
    }

    return directions[last_step = step];
}

