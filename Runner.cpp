#include "Runner.hpp"
#include <vector>
#include <iostream>
//#include <iostream>

struct cell { //0 - норм, 1 - был, 2 - был несколько раз
    short up = 0;
    short down = 0;
    short right = 0;
    short left = 0;
    double x = 0;
    double y = 0;
};

std::vector<cell> stack;
double X = 0;
double Y = 0;

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

                // stack.back().up *= stack.back().up;
                // stack.back().down *= stack.back().down;
                // stack.back().left *= stack.back().left;
                // stack.back().right *= stack.back().right;
                stack.back().up += it.base()->up;
                stack.back().down += it.base()->down;
                stack.back().left += it.base()->left;
                stack.back().right += it.base()->right;
                //          if (it-1 != stack.begin()) {
                //              stack.erase( it, stack.end() );
                //          }
                break;
            }
        }
        stack.back().x = X;
        stack.back().y = Y;

    }


    /*  if ( stack.back().left<0 ) {
          int x =1;
      } */
    std::cout << "coord: " << stack.back().right << stack.back().left << stack.back().down << std::endl;


    for (int i = 0; ;i++) {
        if ( stack.back().right == i && current_status.right == BlockType::FREE ) {
            ++stack.back().right;
            cell node;
            node.left = 1;
            stack.push_back( node );

            ++X;
            return Direction::RIGHT;
        }

        if ( stack.back().down == i && current_status.down == BlockType::FREE ) {
            ++stack.back().down;
            cell node;
            node.up = 1;
            stack.push_back( node );

            --Y;
            return Direction::DOWN;

        }

        if ( stack.back().left == i && current_status.left == BlockType::FREE ) {
            ++stack.back().left;
            cell node;
            node.right = 1;
            stack.push_back( node );

            --X;
            return Direction::LEFT;
        }

        if ( stack.back().up == i && current_status.up == BlockType::FREE ) {
            ++stack.back().up;
            cell node;
            node.down = 1;
            stack.push_back( node );

            ++Y;
            return Direction::UP;

        }
    }
    return Direction::UP;
}
