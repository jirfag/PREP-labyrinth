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
	/*
    if (current_status.right == BlockType::EXIT)
        return Direction::RIGHT;
	if(current_status.down == BlockType::EXIT)
        return Direction::DOWN;
    if (current_status.up == BlockType::EXIT)
        return Direction::UP;
    if (current_status.left == BlockType::EXIT)
        return Direction::LEFT;
*/
    switch(prevMove){
    	case Direction::RIGHT: {
    		if(current_status.down != BlockType::WALL){
    			prevMove = Direction::DOWN;
    			return prevMove;
    		}
    		if(current_status.right !=BlockType::WALL){
    			return prevMove;
    		}
    		if(current_status.up !=BlockType::WALL){
    			prevMove = Direction::UP;
    			return prevMove;
    		}
    		if(current_status.left != BlockType::WALL){
    			prevMove = Direction::LEFT;
    			return prevMove;
    		}
    	}
    	case Direction::DOWN: {
    		if(current_status.left != BlockType::WALL){
    			prevMove = Direction::LEFT;
    			return prevMove;
    		}
    		if(current_status.down != BlockType::WALL){
    			return prevMove;
    		}
    		if(current_status.right!=BlockType::WALL){
    			prevMove = Direction::RIGHT;
    			return prevMove;
    		}
    		if(current_status.up!=BlockType::WALL){
    			prevMove = Direction::UP;
    			return prevMove;
    		}
    	}
    	case Direction::LEFT: {
    		if(current_status.up!=BlockType::WALL){
    			prevMove = Direction::UP;
    			return prevMove;
    		}
    		if(current_status.left != BlockType::WALL){
    			return prevMove;
    		}
    		if(current_status.down != BlockType::WALL){
    			prevMove = Direction::DOWN;
    			return prevMove;
    		}
    		if(current_status.right!=BlockType::WALL){
    			prevMove = Direction::RIGHT;
    			return prevMove;
    		}
    	}
    	case Direction::UP: {
    		if(current_status.right!=BlockType::WALL){
    			prevMove = Direction::RIGHT;
    			return prevMove;
    		}
    		if(current_status.up!=BlockType::WALL){
    			return prevMove;
    		}
    		if(current_status.left != BlockType::WALL){
    			prevMove = Direction::LEFT;
    			return prevMove;
    		}
    		if(current_status.down != BlockType::WALL){
    			prevMove = Direction::DOWN;
    			return prevMove;
    		}
    	}
    }
}