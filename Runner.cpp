#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"


using namespace std;


Direction Runner::step_left() {
	

	switch(look) {
		
		case(Direction::UP):

			if (current_status.left != BlockType::WALL) {
				look = Direction::LEFT;
				return look;

			} else {
				if(current_status.up != BlockType::WALL)
					return look;

				else {
					if(current_status.left != BlockType::WALL) {
						look = Direction::LEFT;
						return look;
					}

					else {
						look = Direction::DOWN;
						return look;
					}
				}
			}

		case(Direction::DOWN):

			if (current_status.right != BlockType::WALL) {
				look = Direction::RIGHT;
				return look;

			} else {
				if(current_status.down != BlockType::WALL)
					return look;

				else {
					if(current_status.left != BlockType::WALL) {
						look = Direction::LEFT;
						return look;
					}

					else {
						look = Direction::UP;
						return look;
					}
				}
			}
	
		case(Direction::LEFT):

			if (current_status.down != BlockType::WALL) {
				look = Direction::DOWN;
				return look;

			} else {
				if(current_status.left != BlockType::WALL)
					return look;

				else {
					if(current_status.up != BlockType::WALL) {
						look = Direction::UP;
						return look;
					}

					else {
						look = Direction::RIGHT;
						return look;
					}
				}
			}
	
		case(Direction::RIGHT):

			if (current_status.up != BlockType::WALL) {
				look = Direction::UP;
				return look;

			} else {
				if(current_status.right != BlockType::WALL)
					return look;

				else {
					if(current_status.down != BlockType::WALL) {
						look = Direction::DOWN;
						return look;
					}

					else {
						look = Direction::LEFT;
						return look;
					}
				}
			}

	}
	return Direction::DOWN;

}

Direction Runner::step() {
	
	if ((current_status.up == BlockType::EXIT))
                 return Direction::UP;
        if (current_status.right == BlockType::EXIT)
                 return Direction::RIGHT;
	if ((current_status.down == BlockType::EXIT))
                 return Direction::DOWN;
        if (current_status.left == BlockType::EXIT)
                 return Direction::LEFT;
 
	if (i < 15000000) {
		++i;
		return step_left();
	}
	++i;
	if (i == 18000000) i = 0;
	const std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
	return directions[std::rand() % directions.size()];
}


Direction Runner::step_right() {
	

	switch(look) {
		
		case(Direction::UP):

			if (current_status.right != BlockType::WALL) {
				look = Direction::RIGHT;
				return look;

			} else {
				if(current_status.up != BlockType::WALL)
					return look;

				else {
					if(current_status.left != BlockType::WALL) {
						look = Direction::LEFT;
						return look;
					}

					else {
						look = Direction::DOWN;
						return look;
					}
				}
			}

		case(Direction::DOWN):

			if (current_status.left != BlockType::WALL) {
				look = Direction::LEFT;
				return look;

			} else {
				if(current_status.down != BlockType::WALL)
					return look;

				else {
					if(current_status.right != BlockType::WALL) {
						look = Direction::RIGHT;
						return look;
					}

					else {
						look = Direction::UP;
						return look;
					}
				}
			}
	
		case(Direction::LEFT):

			if (current_status.up != BlockType::WALL) {
				look = Direction::UP;
				return look;

			} else {
				if(current_status.left != BlockType::WALL)
					return look;

				else {
					if(current_status.down != BlockType::WALL) {
						look = Direction::DOWN;
						return look;
					}

					else {
						look = Direction::RIGHT;
						return look;
					}
				}
			}
	
		case(Direction::RIGHT):

			if (current_status.down != BlockType::WALL) {
				look = Direction::DOWN;
				return look;

			} else {
				if(current_status.right != BlockType::WALL)
					return look;

				else {
					if(current_status.up != BlockType::WALL) {
						look = Direction::UP;
						return look;
					}

					else {
						look = Direction::LEFT;
						return look;
					}
				}
			}

	}
	return Direction::UP;

}
