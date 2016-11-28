//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include "utils.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

Direction Runner::step()
{

    const std::vector<BlockType> status {current_status.up, current_status.left, current_status.down, current_status.right};

    std::vector<BlockType>::const_iterator it = std::find(status.cbegin(), status.cend(), BlockType::EXIT);
    if (it != status.cend())
            return directions[std::distance(status.begin(), it)];

    while(status[(last_step + 1) % 4] == BlockType::WALL){
        last_step = (last_step + 3) % 4;
    }

    last_step =(last_step + 1) % 4;
    return directions[last_step];
}

