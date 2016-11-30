//
// Created by Andrey Richter (Savosin) on 13.11.16.
//

#include "Runner.hpp"
#include <iostream>
#include "utils.hpp"

#define R 1
#define D 2
#define L 3
#define U 4

int napravlenie = R;
int i = 0;

Direction Runner::step()
{	
	
	if ( (napravlenie == R)&&(current_status.right == BlockType::FREE)&&(current_status.up == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == R)&&(current_status.right == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == R)&&(current_status.right == BlockType::FREE)&&(current_status.up == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == D)&&(current_status.right == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == D)&&(current_status.left == BlockType::FREE)&&(current_status.right == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == D)&&(current_status.down == BlockType::FREE)&&(current_status.left == BlockType::FREE)&&(current_status.right == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == U)&&(current_status.right == BlockType::FREE)&&(current_status.up == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == U)&&(current_status.right == BlockType::FREE)&&(current_status.left == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == U)&&(current_status.right == BlockType::FREE)&&(current_status.up == BlockType::FREE)&&(current_status.left == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
		

	
	
	
	
	if ( (napravlenie == R)&&(current_status.right == BlockType::FREE)&&(current_status.up == BlockType::FREE) )
		if (i == 1)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == R)&&(current_status.right == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 1)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == R)&&(current_status.right == BlockType::FREE)&&(current_status.up == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 1)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == D)&&(current_status.right == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 1)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == D)&&(current_status.left == BlockType::FREE)&&(current_status.right == BlockType::FREE) )
		if (i == 1)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == D)&&(current_status.down == BlockType::FREE)&&(current_status.left == BlockType::FREE)&&(current_status.right == BlockType::FREE) )
		if (i == 1)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == U)&&(current_status.right == BlockType::FREE)&&(current_status.up == BlockType::FREE) )
		if (i == 1)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == U)&&(current_status.right == BlockType::FREE)&&(current_status.left == BlockType::FREE) )
		if (i == 1)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	if ( (napravlenie == U)&&(current_status.right == BlockType::FREE)&&(current_status.up == BlockType::FREE)&&(current_status.left == BlockType::FREE) )
		if (i == 1)
		{
			napravlenie = R;
			i++;
			return Direction::RIGHT;
		}
	
	
	
	
	
	switch (napravlenie)
	{
		case 1: 
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
					napravlenie = 4;
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
					return Direction::RIGHT;
				}
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
					napravlenie = 1;
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
					return Direction::DOWN;
				}
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
					napravlenie = 2;
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
					return Direction::LEFT;
				}
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
					napravlenie = 3;
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
					return Direction::UP;
				}
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
