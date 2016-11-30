//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include<iostream>
#include "utils.hpp"

struct coord
{
    int x = 0, y = 0;
};

coord current;
Direction dir = Direction::UP;

std::stack<Direction> stk;
std::vector<coord> passed;



bool hasPassed(coord &pos)
{

    for(auto i : passed)
    {
        if( (i.x == pos.x) && (i.y == pos.y))
        {
            return true;
        }
    }

    return false;
}

Direction Runner::getDir()
{

    passed.push_back(current);

    int count = 0;
    while(count < 4)
    {
        switch(dir)
        {

            case Direction::UP:
            {
                coord c_up = current;
                c_up.y++;
                if(current_status.up != BlockType::WALL && !hasPassed(c_up))
                {
                    stk.push(Direction::UP);
                    current.y++;
                    return Direction::UP;
                }
                else
                {
                    dir = Direction::DOWN;
                    count++;
                }
                break;
            }


            case Direction::DOWN:
            {
                coord c_down = current;
                c_down.y--;
                if(current_status.down != BlockType::WALL && !hasPassed(c_down))
                {
                    stk.push(Direction::UP);
                    current.y--;
                    return Direction::DOWN;
                }
                else
                {
                    dir = Direction::LEFT;
                    count++;
                }
                break;
            }

            case Direction::LEFT:
            {
                coord c_left = current;
                c_left.x--;
                if(current_status.left != BlockType::WALL && !hasPassed(c_left))
                {
                    stk.push(Direction::LEFT);
                    current.x--;
                    return Direction::LEFT;
                }
                else
                {
                    dir = Direction::RIGHT;
                    count++;
                }
                break;
            }

            case Direction::RIGHT:
            {
                coord c_right = current;
                c_right.x++;
                if(current_status.right != BlockType::WALL && !hasPassed(c_right))
                {
                    stk.push(Direction::RIGHT);
                    current.x++;
                    return Direction::RIGHT;
                }
                else
                {
                    dir = Direction::UP;
                    count++;
                }
                break;
            }
        }
    }

    Direction top = stk.top();
    stk.pop();

    switch(top)
    {
    case Direction::UP:
        current.y--;
        return Direction::DOWN;
    case Direction::DOWN:
        current.y++;
        return Direction::UP;
    case Direction::LEFT:
        current.x++;
        return Direction::RIGHT;
    case Direction::RIGHT:
        current.x--;
        return Direction::LEFT;
    }

    return Direction::UP;
}

Direction Runner::step()
{
    // TODO: you need to replace the code below with your implementation of labyrinth solver.
    // Now here is the stupid implementation with random choicing of direction.


    if(current_status.up == BlockType::EXIT)
        return Direction::UP;
    if(current_status.down == BlockType::EXIT)
        return Direction::DOWN;
    if(current_status.left == BlockType::EXIT)
        return Direction::LEFT;
    if(current_status.right == BlockType::EXIT)
        return Direction::RIGHT;


//    std::cout<<"x: "<<current.x<<std::endl;
//    std::cout<<"y: "<<current.y<<std::endl;
//    std::cout<<passed.size()<<std::endl;

    return getDir();
}

