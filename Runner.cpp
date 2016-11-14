//
// Created by Andrey Richter (Savosin) on 13.11.16.
//

#include "Runner.hpp"
#include "utils.hpp"

#define R 1
#define D 2
#define L 3
#define U 4

int napravlenie = R;

Direction Runner::step()
{	
	switch (napravlenie)
	{
		case R: 
		{
			if ((current_status.up == BlockType::FREE) | (current_status.up == BlockType::EXIT))  
			{
				if (current_status.right == BlockType::EXIT)
				{
					return Direction::RIGHT;
				}
				else if (current_status.down == BlockType::EXIT)
				{
					return Direction::DOWN;
				}
				else
				{
					napravlenie = U;
					return Direction::UP;
				}
			}
			else if ((current_status.right == BlockType::FREE) | (current_status.right == BlockType::EXIT))
			{
				if (current_status.down == BlockType::EXIT)
				{
					return Direction::DOWN;
				}
				else
				{
					napravlenie = R;
					return Direction::RIGHT;
				}
			}
			else if ((current_status.down == BlockType::FREE) | (current_status.down == BlockType::EXIT))
			{
				napravlenie = D;
				return Direction::DOWN;
			}
			else
			{
				napravlenie = L;
				return Direction::LEFT;
			}
		}
		case D: 
		{
			if ((current_status.right == BlockType::FREE) | (current_status.right == BlockType::EXIT))
			{
				if (current_status.down == BlockType::EXIT)
				{
					return Direction::DOWN;
				}
				else if (current_status.left == BlockType::EXIT)
				{
					return Direction::LEFT;
				}
				else
				{	
					napravlenie = R;
					return Direction::RIGHT;
				}
			}
			else if ((current_status.down == BlockType::FREE) | (current_status.down == BlockType::EXIT))
			{
				if (current_status.left == BlockType::EXIT)
				{
					return Direction::LEFT;
				}
				else
				{
					napravlenie = D;
					return Direction::DOWN;
				}
			}
			else if ((current_status.left == BlockType::FREE) | (current_status.left == BlockType::EXIT))
			{
				napravlenie = L;
				return Direction::LEFT;
			}
			else
			{
				napravlenie = U;
				return Direction::UP;
			}
		}
		case L: 
		{
			if ((current_status.down == BlockType::FREE) | (current_status.down == BlockType::EXIT))
			{
				if (current_status.left == BlockType::EXIT)
				{
					return Direction::LEFT;
				}
				else if (current_status.up == BlockType::EXIT)
				{
					return Direction::UP;
				}
				else
				{
					napravlenie = D;
					return Direction::DOWN;
				}
			}
			else if ((current_status.left == BlockType::FREE) | (current_status.left == BlockType::EXIT))
			{
				if (current_status.up == BlockType::EXIT)
				{
					return Direction::UP;
				}
				else
				{
					napravlenie = L;
					return Direction::LEFT;
				}
			}
			else if ((current_status.up == BlockType::FREE) | (current_status.up == BlockType::EXIT))
			{
				napravlenie = U;
				return Direction::UP;
			}
			else
			{
				napravlenie = R;
				return Direction::RIGHT;
			}
		}
		default: 
		{
			if ((current_status.left == BlockType::FREE) | (current_status.left == BlockType::EXIT))
			{
				if (current_status.up == BlockType::EXIT)
				{
					return Direction::UP;
				}
				else if (current_status.right == BlockType::EXIT)
				{
					return Direction::RIGHT;
				}
				else
				{
					napravlenie = L;
					return Direction::LEFT;
				}
			}
			else if ((current_status.up == BlockType::FREE) | (current_status.up == BlockType::EXIT))
			{
				if (current_status.right == BlockType::EXIT)
				{
					return Direction::RIGHT;
				}
				else
				{
					napravlenie = U;
					return Direction::UP;
				}
			}
			else if ((current_status.right == BlockType::FREE) | (current_status.right == BlockType::EXIT))
			{
				napravlenie = R;
				return Direction::RIGHT;
			}
			else
			{
				napravlenie = D;
				return Direction::DOWN;
			}
		}
	}
}

