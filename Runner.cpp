//
// Created by Andrey Richter (Savosin) on 13.11.16.
//

#include "Runner.hpp"
#include "utils.hpp"


int napravlenie = 1;

Direction Runner::step()
{	
	switch (napravlenie)
	{
		case 1: 
		{
			if ((current_status.up == BlockType::FREE) | (current_status.up == BlockType::EXIT))  
			{
				napravlenie = 4;
				return Direction::UP;
			}
			else if ((current_status.right == BlockType::FREE) | (current_status.right == BlockType::EXIT))
			{
				napravlenie = 1;
				return Direction::RIGHT;
			}
			else if ((current_status.down == BlockType::FREE) | (current_status.down == BlockType::EXIT))
			{
				napravlenie = 2;
				return Direction::DOWN;
			}
			else
			{
				napravlenie = 3;
				return Direction::LEFT;
			}
		}
		case 2: 
		{
			if ((current_status.right == BlockType::FREE) | (current_status.right == BlockType::EXIT))
			{
				napravlenie = 1;
				return Direction::RIGHT;
			}
			else if ((current_status.down == BlockType::FREE) | (current_status.down == BlockType::EXIT))
			{
				napravlenie = 2;
				return Direction::DOWN;
			}
			else if ((current_status.left == BlockType::FREE) | (current_status.left == BlockType::EXIT))
			{
				napravlenie = 3;
				return Direction::LEFT;
			}
			else
			{
				napravlenie = 4;
				return Direction::UP;
			}
		}
		case 3: 
		{
			if ((current_status.down == BlockType::FREE) | (current_status.down == BlockType::EXIT))
			{
				napravlenie = 2;
				return Direction::DOWN;
			}
			else if ((current_status.left == BlockType::FREE) | (current_status.left == BlockType::EXIT))
			{
				napravlenie = 3;
				return Direction::LEFT;
			}
			else if ((current_status.up == BlockType::FREE) | (current_status.up == BlockType::EXIT))
			{
				napravlenie = 4;
				return Direction::UP;
			}
			else
			{
				napravlenie = 1;
				return Direction::RIGHT;
			}
		}
		default: 
		{
			if ((current_status.left == BlockType::FREE) | (current_status.left == BlockType::EXIT))
			{
				napravlenie = 3;
				return Direction::LEFT;
			}
			else if ((current_status.up == BlockType::FREE) | (current_status.up == BlockType::EXIT))
			{
				napravlenie = 4;
				return Direction::UP;
			}
			else if ((current_status.right == BlockType::FREE) | (current_status.right == BlockType::EXIT))
			{
				napravlenie = 1;
				return Direction::RIGHT;
			}
			else
			{
				napravlenie = 2;
				return Direction::DOWN;
			}
		}
	}
}
