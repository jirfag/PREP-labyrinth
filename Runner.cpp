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
	if ( (napravlenie == L)&&(current_status.left == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = D;
			i++;
			return Direction::DOWN;
		}
	if ( (napravlenie == L)&&(current_status.up == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = D;
			i++;
			return Direction::DOWN;
		}
	if ( (napravlenie == L)&&(current_status.left == BlockType::FREE)&&(current_status.up == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = D;
			i++;
			return Direction::DOWN;
		}
	if ( (napravlenie == R)&&(current_status.right == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = D;
			i++;
			return Direction::DOWN;
		}
	if ( (napravlenie == R)&&(current_status.down == BlockType::FREE)&&(current_status.up == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = D;
			i++;
			return Direction::DOWN;
		}
	if ( (napravlenie == R)&&(current_status.down == BlockType::FREE)&&(current_status.up == BlockType::FREE)&&(current_status.right == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = D;
			i++;
			return Direction::DOWN;
		}
	if ( (napravlenie == D)&&(current_status.left == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = D;
			i++;
			return Direction::DOWN;
		}
	if ( (napravlenie == D)&&(current_status.right == BlockType::FREE)&&(current_status.down == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = D;
			i++;
			return Direction::DOWN;
		}
	if ( (napravlenie == D)&&(current_status.right == BlockType::FREE)&&(current_status.down == BlockType::FREE)&&(current_status.left == BlockType::FREE) )
		if (i == 0)
		{
			napravlenie = D;
			i++;
			return Direction::DOWN;
		}
		
		
		switch (napravlenie)
		{
			case R: 
			{
				if ((current_status.up == BlockType::FREE) | (current_status.up == BlockType::EXIT))  
				{
					napravlenie = U;
					return Direction::UP;
				}
				else if ((current_status.right == BlockType::FREE) | (current_status.right == BlockType::EXIT))
				{
					napravlenie = R;
					return Direction::RIGHT;
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
					napravlenie = R;
					return Direction::RIGHT;
				}
				else if ((current_status.down == BlockType::FREE) | (current_status.down == BlockType::EXIT))
				{
					napravlenie = D;
					return Direction::DOWN;
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
					napravlenie = D;
					return Direction::DOWN;
				}
				else if ((current_status.left == BlockType::FREE) | (current_status.left == BlockType::EXIT))
				{
					napravlenie = L;
					return Direction::LEFT;
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
					napravlenie = L;
					return Direction::LEFT;
				}
				else if ((current_status.up == BlockType::FREE) | (current_status.up == BlockType::EXIT))
				{
					napravlenie = U;
					return Direction::UP;
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
