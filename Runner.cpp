//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include "utils.hpp"

Runner::Runner(){
	prevMove = Direction::UP;
	myvec.resize(10000);
	steps = 0;
}


void Runner::fill_node(node& n){
	if(current_status.left ==BlockType::WALL){

		n.freeWays--;
	}
	if(current_status.right==BlockType::WALL){

		n.freeWays--;
	}
	if(current_status.up ==BlockType::WALL){

		n.freeWays--;
	}
	if(current_status.down==BlockType::WALL){

		n.freeWays--;
	}
}

Direction Runner::step(){
	node n;
	fill_node(n);
	if(n.freeWays==1 && goForward ==true && steps !=0){
		goForward = false;
	}
	if(goForward){
		MoveForward(prevMove, n);
	}
	else{
		MoveBack(prevMove);
	}
	steps++;
	//if(steps >55) {
	//	std::cout<<std::endl;
	//	exit(0); }
	return prevMove;
}

void Runner::MoveBack(Direction& prevMove){
	node new_n = myvec.back();
	if(new_n.freeWays <= 2){
		myvec.pop_back();
		prevMove = new_n.reverse;
		if(prevMove == Direction::RIGHT){
		}
		else if(prevMove == Direction::UP){
		}
		else if(prevMove == Direction::DOWN){
		}
		else if(prevMove == Direction::LEFT){
		}
	}
	else {
		myvec.pop_back();
		goForward = true;
		prevMove = new_n.right_dir;
	}
}


void Runner::MoveForward(Direction& prevMove, node& n){
	switch(prevMove){
			case Direction::UP: {
				if(current_status.up !=BlockType::WALL){
					n.reverse = Direction::DOWN;
					n.right_dir = Direction::LEFT;
					myvec.push_back(n);
					return;
				}
				if(current_status.right!=BlockType::WALL){
					n.reverse = Direction::LEFT;
					n.right_dir = Direction::UP;
					myvec.push_back(n);
                	prevMove = Direction::RIGHT;
                	return;
            	}
    			if(current_status.left != BlockType::WALL){
    				n.reverse = Direction::RIGHT;
    				n.right_dir = Direction::DOWN;
    				myvec.push_back(n);
    				prevMove = Direction::LEFT;
    				return;
    			}
            	if(current_status.down != BlockType::WALL){
            		n.reverse = Direction::UP;
            		n.right_dir = Direction::RIGHT;
            		myvec.push_back(n);
    				prevMove = Direction::DOWN;
    				return;
    			}
			}
			case Direction::RIGHT: {
            	if(current_status.right !=BlockType::WALL){
            		n.reverse = Direction::LEFT;
            		n.right_dir = Direction::UP;
            		myvec.push_back(n);
            		return;
                	//return prevMove;
            	}
            	if(current_status.down != BlockType::WALL){
            		n.reverse = Direction::UP;
            		n.right_dir = Direction::RIGHT;
            		myvec.push_back(n);
                	prevMove = Direction::DOWN;
                	return;
            	}
            	if(current_status.up !=BlockType::WALL){
               		prevMove = Direction::UP;
               		n.reverse = Direction::DOWN;
               		n.right_dir = Direction::LEFT;
                	myvec.push_back(n);
                	return;
            	}
            	if(current_status.left != BlockType::WALL){
                	prevMove = Direction::LEFT;
                	n.reverse = Direction::RIGHT;
                	n.right_dir = Direction::DOWN;
                	myvec.push_back(n);
                	return;
            	}
        	}
        	case Direction::DOWN: {
            	if(current_status.down != BlockType::WALL){
            		n.reverse = Direction::UP;
            		n.right_dir = Direction::RIGHT;
            		prevMove = Direction::DOWN;
            		myvec.push_back(n);
            		return;
            	}
	            if(current_status.left != BlockType::WALL){
	            	n.reverse = Direction::RIGHT;
	            	n.right_dir = Direction::DOWN;
	            	myvec.push_back(n);
	                prevMove = Direction::LEFT;
	                return;
	               // return prevMove;
	            }
            	if(current_status.right!=BlockType::WALL){
            		n.reverse = Direction::LEFT;
            		n.right_dir = Direction::UP;
            		myvec.push_back(n);
               		prevMove = Direction::RIGHT;
              		return;
               	}
	            if(current_status.up!=BlockType::WALL){
	            	n.reverse = Direction::DOWN;
	            	n.right_dir = Direction::LEFT;
	            	myvec.push_back(n);
	                prevMove = Direction::UP;
	                return;
	               // return prevMove;
            	}
        	}
        	case Direction::LEFT: {
	            if(current_status.left != BlockType::WALL){
	            	n.reverse = Direction::RIGHT;
	            	n.right_dir = Direction::DOWN;
	            	myvec.push_back(n);
	     
	            	return;
	                
	            }
	            if(current_status.up!=BlockType::WALL){
	            	n.reverse = Direction::DOWN;
	            	n.right_dir = Direction::LEFT;
	            	myvec.push_back(n);
	                prevMove = Direction::UP;
	                
	                return;
	                
	            }
	            if(current_status.down != BlockType::WALL){
	            	n.reverse = Direction::UP;
	            	n.right_dir = Direction::RIGHT;
	            	myvec.push_back(n);
	                prevMove = Direction::DOWN;
	               
	                return;
	                //return prevMove;
	            }
	            if(current_status.right!=BlockType::WALL){
	            	n.reverse = Direction::LEFT;
	            	n.right_dir = Direction::UP;
	            	myvec.push_back(n);
	                prevMove = Direction::RIGHT;
	                ;
	                return;
	                
	            }
        }
	}

}