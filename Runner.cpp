//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Runner::Runner() : prevMove(Direction::RIGHT){}

Direction Runner::step()
{


    if (current_status.up == BlockType::EXIT) {
        return Direction::UP;
    }else if (current_status.left == BlockType::EXIT) {
        return Direction::LEFT;
    }else if (current_status.right == BlockType::EXIT) {
        return Direction::RIGHT;
    }else if (current_status.down == BlockType::EXIT) {
        return Direction::DOWN;
    }
    switch(prevMove){
    	case Direction::UP: {
    		if(current_status.left == BlockType::FREE){
    			prevMove = Direction::LEFT;
    			return Direction::LEFT;
    		}
            if(current_status.up==BlockType::FREE){
                return Direction::UP;
            }
            if(current_status.right ==BlockType::FREE){
                prevMove = Direction::RIGHT;
                return Direction::RIGHT;
            }
    		if(current_status.down == BlockType::FREE){
    			prevMove = Direction::DOWN;
    			return Direction::DOWN;
    		}
        }
        case Direction::LEFT: {
            if(current_status.down == BlockType::FREE){
                prevMove = Direction::DOWN;
                return Direction::DOWN;
            }
            if(current_status.left == BlockType::FREE){
                return Direction::LEFT;
            }
            if(current_status.up==BlockType::FREE){
                prevMove = Direction::UP;
                return Direction::UP;
            }
            if(current_status.right==BlockType::FREE){
                prevMove = Direction::RIGHT;
                return Direction::RIGHT;
            }
        }
        case Direction::DOWN: {
            if(current_status.right ==BlockType::FREE){
                prevMove = Direction::RIGHT;
                return Direction::RIGHT;
            }
            if(current_status.down == BlockType::FREE){
                return Direction::DOWN;
            }
            if(current_status.left == BlockType::FREE){
                prevMove = Direction::LEFT;
                return Direction::LEFT;
            }
            if(current_status.up ==BlockType::FREE){
                prevMove = Direction::UP;
                return Direction::UP;
            }
        }
        case Direction::RIGHT: {
            if(current_status.up ==BlockType::FREE){
                prevMove = Direction::UP;
                return Direction::UP;
            }
            if(current_status.right ==BlockType::FREE){
                return Direction::RIGHT;
            }
            if(current_status.down == BlockType::FREE){
                prevMove = Direction::DOWN;
                return Direction::DOWN;
            }
            if(current_status.left == BlockType::FREE){
                prevMove = Direction::LEFT;
                return Direction::LEFT;
            }
        }
    }
    return prevMove;
}
