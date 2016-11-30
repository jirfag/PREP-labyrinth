//
// Created by Andrey Richter (Savosin) on 13.11.16.
//

#include "Runner.hpp"
#include "utils.hpp"

short int napravlenie = 1;

Direction Runner::step()
{	
	if (current_status.right == BlockType::EXIT)
	{
		return Direction::RIGHT;
	}
	if (current_status.left == BlockType::EXIT)
	{
		return Direction::LEFT;
	}
	if (current_status.down == BlockType::EXIT)
	{
		return Direction::DOWN;
	}
	if (current_status.up == BlockType::EXIT)
	{
		return Direction::UP;
	}
	
	switch (napravlenie)
	{
		case 1: 
		{
			if (current_status.up == BlockType::FREE) 
			{
					napravlenie = 4;
					return Direction::UP;
			}
			else if (current_status.right == BlockType::FREE)
			{
					return Direction::RIGHT;
			}
			else if (current_status.down == BlockType::FREE)
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
			if (current_status.right == BlockType::FREE)
			{
					napravlenie = 1;
					return Direction::RIGHT;
			}
			else if (current_status.down == BlockType::FREE)
			{
					return Direction::DOWN;
			}
			else if (current_status.left == BlockType::FREE)
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
			if (current_status.down == BlockType::FREE)
			{
					napravlenie = 2;
					return Direction::DOWN;
			}
			else if (current_status.left == BlockType::FREE)
			{
					return Direction::LEFT;
			}
			else if (current_status.up == BlockType::FREE)
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
			if (current_status.left == BlockType::FREE)
			{
					napravlenie = 3;
					return Direction::LEFT;
			}
			else if (current_status.up == BlockType::FREE)
			{
					return Direction::UP;
			}
			else if (current_status.right == BlockType::FREE)
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
