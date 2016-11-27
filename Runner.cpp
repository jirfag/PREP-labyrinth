//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"

Direction Runner::step() {
	
	static Direction look = Direction::UP;
	switch(look) {
		case(Direction::UP):
			
			if (current_status.right != BlockType::WALL) {
				if (map[i][j + 1] != 2) {
					if (map[i][j + 1] == 1)
						map[i][j + 1] = 2;
					else map[i][j + 1] = 1;
					look = Direction::RIGHT;
					++j;
					return look;
				}
			}

			if (current_status.up != BlockType::WALL) {
				if (map[i - 1][j] != 2) {
					if (map[i-1][j] == 1)
						map[i-1][j] = 2;
					else map[i-1][j] = 1;
					--i;
					return look;
				}
			}
		
			if (current_status.left != BlockType::WALL) {
				if (map[i][j - 1] != 2) {
					if (map[i][j - 1] == 1)
						map[i][j - 1] = 2;
					else map[i][j - 1] = 1;
					--j;
					look = Direction::LEFT;
					return look;
				}
			}

			if (current_status.down != BlockType::WALL) {
				if (map[i + 1][j] != 2) {
					if (map[i+1][j] == 1)
						map[i+1][j] = 2;
					else map[i+1][j] = 1;
					++i;
					look = Direction::DOWN;
					return look;
				}
			}


		case(Direction::DOWN):

			if (current_status.left != BlockType::WALL) {
				if (map[i][j - 1] != 2) {
					if (map[i][j - 1] == 1)
						map[i][j - 1] = 2;
					else map[i][j - 1] = 1;
					look = Direction::LEFT;
					--j;
					return look;
				}
			}

			if (current_status.down != BlockType::WALL) {
				if (map[i + 1][j] != 2) {
					if (map[i+1][j] == 1)
						map[i+1][j] = 2;
					else map[i+1][j] = 1;
					++i;
					return look;
				}
			}

			if (current_status.right != BlockType::WALL) {
				if (map[i][j + 1] != 2) {
					if (map[i][j + 1] == 1)
						map[i][j + 1] = 2;
					else map[i][j + 1] = 1;
					++j;
					look = Direction::RIGHT;
					return look;
				}
			}

			if (current_status.up != BlockType::WALL) {
				if (map[i - 1][j] != 2) {
					if (map[i-1][j] == 1)
						map[i-1][j] = 2;
					else map[i-1][j] = 1;
					--i;
					look = Direction::UP;
					return look;
				}
			}

		case(Direction::LEFT):

			if (current_status.up != BlockType::WALL) {
				if (map[i-1][j] != 2) {
					if (map[i-1][j] == 1)
						map[i-1][j] = 2;
					else map[i-1][j] = 1;
					look = Direction::UP;
					--i;
					return look;
				}
			}

			if (current_status.left != BlockType::WALL) {
				if (map[i][j-1] != 2) {
					if (map[i][j-1] == 1)
						map[i][j-1] = 2;
					else map[i][j-1] = 1;
					--j;
					return look;
				}
			}

			if (current_status.down != BlockType::WALL) {
				if (map[i+1][j] != 2) {
					if (map[i+1][j - 1] == 1)
						map[i+1][j - 1] = 2;
					else map[i+1][j - 1] = 1;
					++i;
					look = Direction::DOWN;
					return look;
				}
			}

			if (current_status.right != BlockType::WALL) {
				if (map[i][j+1] != 2) {
					if (map[i][j+1] == 1)
						map[i][j+1] = 2;
					else map[i][j+1] = 1;
					++j;
					look = Direction::RIGHT;
					return look;
				}
			}

		case(Direction::RIGHT):

			if (current_status.down != BlockType::WALL) {
				if (map[i+1][j] != 2) {
					if (map[i+1][j] == 1)
						map[i+1][j] = 2;
					else map[i+1][j] = 1;
					look = Direction::DOWN;
					++i;
					return look;
				}
			}

			if (current_status.right != BlockType::WALL) {
				if (map[i][j+1] != 2) {
					if (map[i][j+1] == 1)
						map[i][j+1] = 2;
					else map[i][j+1] = 1;
					++j;
					return look;
				}
			}

			if (current_status.up != BlockType::WALL) {
				if (map[i-1][j] != 2) {
					if (map[i-1][j - 1] == 1)
						map[i-1][j - 1] = 2;
					else map[i-1][j - 1] = 1;
					--i;
					look = Direction::UP;
					return look;
				}
			}

			if (current_status.left != BlockType::WALL) {
				if (map[i][j-1] != 2) {
					if (map[i][j-1] == 1)
						map[i][j-1] = 2;
					else map[i][j-1] = 1;
					--j;
					look = Direction::LEFT;
					return look;
				}
			}
	}

	return look;
} 
