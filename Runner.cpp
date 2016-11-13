//
// Created by Andrey Richter (Savosin) on 13.11.16.
//

#include "Runner.hpp"
#include "utils.hpp"


short int napravlenie = 1;

Direction Runner::step()
{	
	switch (napravlenie)
	{
		case 1: 
		{
			switch (current_status.up)  
			{
				case BlockType::FREE:
				{
					napravlenie = 4;
					return Direction::UP;
				}
				case BlockType::EXIT:
				{
					napravlenie = 4;
					return Direction::UP;
				}
				default:	
				{
					switch (current_status.right)  
					{
						case BlockType::FREE:
						{
							napravlenie = 1;
							return Direction::RIGHT;
						}
						case BlockType::EXIT:
						{
							napravlenie = 1;
							return Direction::RIGHT;
						}
						default:	
						{
							switch (current_status.down)  
							{
								case BlockType::FREE:
								{
									napravlenie = 2;
									return Direction::DOWN;
								}
								case BlockType::EXIT:
								{
									napravlenie = 2;
									return Direction::DOWN;
								}
								default:	
								{
									napravlenie = 3;
									return Direction::LEFT;
								}
							}
						}	
					}
				}
			}
		}
		case 2: 
		{
			switch (current_status.right)  
			{
				case BlockType::FREE:
				{
					napravlenie = 1;
					return Direction::RIGHT;
				}
				case BlockType::EXIT:
				{
					napravlenie = 1;
					return Direction::RIGHT;
				}
				default:	
				{
					switch (current_status.down)  
					{
						case BlockType::FREE:
						{
							napravlenie = 2;
							return Direction::DOWN;
						}
						case BlockType::EXIT:
						{
							napravlenie = 2;
							return Direction::DOWN;
						}
						default:	
						{
							switch (current_status.left)  
							{
								case BlockType::FREE:
								{
									napravlenie = 3;
									return Direction::LEFT;
								}
								case BlockType::EXIT:
								{
									napravlenie = 3;
									return Direction::LEFT;
								}
								default:	
								{
									napravlenie = 4;
									return Direction::UP;
								}
							}
						}	
					}
				}
			}
		}
		case 3: 
		{
			switch (current_status.down)  
			{
				case BlockType::FREE:
				{
					napravlenie = 2;
					return Direction::DOWN;
				}
				case BlockType::EXIT:
				{
					napravlenie = 2;
					return Direction::DOWN;
				}
				default:	
				{
					switch (current_status.left)  
					{
						case BlockType::FREE:
						{
							napravlenie = 3;
							return Direction::LEFT;
						}
						case BlockType::EXIT:
						{
							napravlenie = 3;
							return Direction::LEFT;
						}
						default:	
						{
							switch (current_status.up)  
							{
								case BlockType::FREE:
								{
									napravlenie = 4;
									return Direction::UP;
								}
								case BlockType::EXIT:
								{
									napravlenie = 4;
									return Direction::UP;
								}
								default:	
								{
									napravlenie = 1;
									return Direction::RIGHT;
								}
							}
						}	
					}
				}
			}
		}
		default: 
		{
			switch (current_status.left)  
			{
				case BlockType::FREE:
				{
					napravlenie = 3;
					return Direction::LEFT;
				}
				case BlockType::EXIT:
				{
					napravlenie = 3;
					return Direction::LEFT;
				}
				default:	
				{
					switch (current_status.up)  
					{
						case BlockType::FREE:
						{
							napravlenie = 4;
							return Direction::UP;
						}
						case BlockType::EXIT:
						{
							napravlenie = 4;
							return Direction::UP;
						}
						default:	
						{
							switch (current_status.right)  
							{
								case BlockType::FREE:
								{
									napravlenie = 1;
									return Direction::RIGHT;
								}
								case BlockType::EXIT:
								{
									napravlenie = 1;
									return Direction::RIGHT;
								}
								default:	
								{
									napravlenie = 2;
									return Direction::DOWN;
								}
							}
						}	
					}
				}
			}
		}
	}
}
