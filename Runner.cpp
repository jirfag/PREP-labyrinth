#include "Runner.hpp"
#include <vector>
//#include <iostream>

struct cell { //0 - норм, 1 - был, 2 - был несколько раз
    short up = 0;
    short down = 0;
    short right = 0;
    short left = 0;
    int x = 0;
    int y = 0;
};

std::vector<cell> stack;
int X = 0;
int Y = 0;

Direction Runner::step() {
    if ( current_status.left == BlockType::EXIT ) {
        return Direction::LEFT;
    } else if ( current_status.right == BlockType::EXIT ) {
        return Direction::RIGHT;
    } else if ( current_status.up == BlockType::EXIT ) {
        return Direction::UP;
    } else if ( current_status.down == BlockType::EXIT ) {
        return Direction::DOWN;
    }

    if ( stack.empty() ) {
        cell node;
        stack.push_back( node );
    } else {
        for ( auto it = stack.end(); it != stack.begin(); --it ) {
            if ( it->x == X && it->y == Y ) {
  //              std::cout << 1;
                if ( stack.back().up != 0 ) {
                    stack.back().up++;
                }
                if ( stack.back().down != 0 ) {
                    stack.back().down++;
                }
                if ( stack.back().left != 0 ) {
                    stack.back().left++;
                }
                if ( stack.back().right != 0 ) {
                    stack.back().right++;
                }
                stack.back().up += it.base()->up;
                stack.back().down += it.base()->down;
                stack.back().left += it.base()->left;
                stack.back().right += it.base()->right;
          //      stack.erase( it, stack.end() );
                break;
            }
        }
        stack.back().x = X;
        stack.back().y = Y;

    }

    if ( stack.back().right == 0 && current_status.right == BlockType::FREE ) {
        stack.back().right = true;
        cell node;
        node.left = true;
        stack.push_back( node );

        ++X;
        return Direction::RIGHT;
    }

    if ( stack.back().down == 0 && current_status.down == BlockType::FREE ) {
        stack.back().down = true;
        cell node;
        node.up = true;
        stack.push_back( node );

        --Y;
        return Direction::DOWN;

    }

    if ( stack.back().left == 0 && current_status.left == BlockType::FREE ) {
        stack.back().left = true;
        cell node;
        node.right = true;
        stack.push_back( node );

        --X;
        return Direction::LEFT;
    }

    if ( stack.back().up == 0 && current_status.up == BlockType::FREE ) {
        stack.back().up = true;
        cell node;
        node.down = true;
        stack.push_back( node );

        ++Y;
        return Direction::UP;

    }

    if ( stack.back().right == 1 && current_status.right == BlockType::FREE ) {
        stack.back().right = true;
        cell node;
        node.left = true;
        stack.push_back( node );

        ++X;
        return Direction::RIGHT;
    }

    if ( stack.back().down == 1 && current_status.down == BlockType::FREE ) {
        stack.back().down = true;
        cell node;
        node.up = true;
        stack.push_back( node );

        --Y;
        return Direction::DOWN;

    }

    if ( stack.back().left == 1 && current_status.left == BlockType::FREE ) {
        stack.back().left = true;
        cell node;
        node.right = true;
        stack.push_back( node );

        --X;
        return Direction::LEFT;
    }

    if ( stack.back().up == 1 && current_status.up == BlockType::FREE ) {
        stack.back().up = true;
        cell node;
        node.down = true;
        stack.push_back( node );

        ++Y;
        return Direction::UP;

    }
    if ( stack.back().right == 2 && current_status.right == BlockType::FREE ) {
        stack.back().right = true;
        cell node;
        node.left = true;
        stack.push_back( node );

        ++X;
        return Direction::RIGHT;
    }

    if ( stack.back().down == 2 && current_status.down == BlockType::FREE ) {
        stack.back().down = true;
        cell node;
        node.up = true;
        stack.push_back( node );

        --Y;
        return Direction::DOWN;

    }

    if ( stack.back().left == 2 && current_status.left == BlockType::FREE ) {
        stack.back().left = true;
        cell node;
        node.right = true;
        stack.push_back( node );

        --X;
        return Direction::LEFT;
    }

    if ( stack.back().up == 2 && current_status.up == BlockType::FREE ) {
        stack.back().up = true;
        cell node;
        node.down = true;
        stack.push_back( node );

        ++Y;
        return Direction::UP;

    }
    if ( stack.back().right == 3 && current_status.right == BlockType::FREE ) {
        stack.back().right = true;
        cell node;
        node.left = true;
        stack.push_back( node );

        ++X;
        return Direction::RIGHT;
    }

    if ( stack.back().down == 3 && current_status.down == BlockType::FREE ) {
        stack.back().down = true;
        cell node;
        node.up = true;
        stack.push_back( node );

        --Y;
        return Direction::DOWN;

    }

    if ( stack.back().left == 3 && current_status.left == BlockType::FREE ) {
        stack.back().left = true;
        cell node;
        node.right = true;
        stack.push_back( node );

        --X;
        return Direction::LEFT;
    }

    if ( stack.back().up == 3 && current_status.up == BlockType::FREE ) {
        stack.back().up = true;
        cell node;
        node.down = true;
        stack.push_back( node );

        ++Y;
        return Direction::UP;

    }
 

    return Direction::UP;
}
