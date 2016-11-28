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
    Direction direction;
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

    /*
    if ( stack.empty() ) {
        cell node;
        stack.push_back( node );
    }
     */
/*
 //   int err = 0;
    for ( auto it = stack.end(); it != stack.begin(); --it ) {
 //       std::cout << it->x << it->y << std::endl;
        if ( it->x == stack.back().x && it->y == stack.back().y ) {
            std::cout << "BIG_XY: "<< stack.back().x << stack.back().y << std::endl;
            std::cout << "ШЕ: " << stack.back().x << stack.back().y << std::endl;
            stack.back().up += it.base()->up;
            stack.back().down += it.base()->down;
            stack.back().left += it.base()->left;
            stack.back().right += it.base()->right;
  //          ++err;
  //          if (err == 2)
            break;
        }
    }
    */

    cell node;
    node.x = X;
    node.y = Y;
    if ( !stack.empty() ) {
        switch ( stack.back().direction ) {
            case Direction::DOWN :
                ++node.up;
                break;

            case Direction::RIGHT :
                ++node.left;
                break;

            case Direction::LEFT :
                ++node.right;
                break;

            default:
                ++node.down;

        }
        
        for ( auto it = stack.end(); it != stack.begin(); --it ) {
       //     std::cout << it.base()->y << "__" << it.base()->x << std::endl;
            if ( it->x == X && it->y == Y ) {
       //         std::cout << "BIG_XY: " << X << Y << std::endl;
       //         std::cout << "ШЕ: " << stack.back().x << stack.back().y << std::endl;
                node.up += it.base()->up;
                node.down += it.base()->down;
                node.left += it.base()->left;
                node.right += it.base()->right;
     //           stack.erase( it-1, stack.end() );
                break;
            }
        }
        
  //      std::cout << "2: " << stack.back().x << stack.back().y << std::endl;
    }

    if ( ( node.right != 0 || current_status.right != BlockType::FREE ) &&
         ( node.up != 0 || current_status.up != BlockType::FREE ) &&
         ( node.left != 0 || current_status.left != BlockType::FREE ) &&
         ( node.down != 0 || current_status.down != BlockType::FREE ) ) {
        switch ( stack.back().direction ) {
            case Direction::DOWN : {
                ++stack.back().down;
                ++Y;
                return Direction::UP;
            }
            case Direction::RIGHT : {
                ++stack.back().right;
                --X;
                return Direction::LEFT;
            }
            case Direction::LEFT : {
                ++stack.back().left;
                ++X;
                return Direction::RIGHT;
            }
            default: {
                ++stack.back().up;
                --Y;
                return Direction::DOWN;
            }
        }
    } else {
        if ( node.right == 0 && current_status.right == BlockType::FREE ) {
            ++node.right;
            node.direction = Direction::RIGHT;
            stack.push_back( node );
            ++X;
            return Direction::RIGHT;
        }

        if ( node.down == 0 && current_status.down == BlockType::FREE ) {
            ++node.down;
            node.direction = Direction::DOWN;
            stack.push_back( node );
            --Y;
            return Direction::DOWN;

        }

        if ( node.left == 0 && current_status.left == BlockType::FREE ) {
            ++node.left;
            node.direction = Direction::LEFT;
            stack.push_back( node );
            --X;
            return Direction::LEFT;
        }

        if ( node.up == 0 && current_status.up == BlockType::FREE ) {
            ++node.up;
            node.direction = Direction::UP;
            stack.push_back( node );
            ++Y;
            return Direction::UP;

        }
        if ( node.right == 1 && current_status.right == BlockType::FREE ) {
            ++node.right;
            node.direction = Direction::RIGHT;
            stack.push_back( node );
            ++X;
            return Direction::RIGHT;
        }

        if ( node.down == 1 && current_status.down == BlockType::FREE ) {
            ++node.down;
            node.direction = Direction::DOWN;
            stack.push_back( node );
            --Y;
            return Direction::DOWN;

        }

        if ( node.left == 1 && current_status.left == BlockType::FREE ) {
            ++node.left;
            node.direction = Direction::LEFT;
            stack.push_back( node );
            --X;
            return Direction::LEFT;
        }

        if ( node.up == 1 && current_status.up == BlockType::FREE ) {
            ++node.up;
            node.direction = Direction::UP;
            stack.push_back( node );
            ++Y;
            return Direction::UP;

        }


        if ( node.right == 2 && current_status.right == BlockType::FREE ) {
            ++node.right;
            node.direction = Direction::RIGHT;
            stack.push_back( node );
            ++X;
            return Direction::RIGHT;
        }

        if ( node.down == 2 && current_status.down == BlockType::FREE ) {
            ++node.down;
            node.direction = Direction::DOWN;
            stack.push_back( node );
            --Y;
            return Direction::DOWN;

        }

        if ( node.left == 2 && current_status.left == BlockType::FREE ) {
            ++node.left;
            node.direction = Direction::LEFT;
            stack.push_back( node );
            --X;
            return Direction::LEFT;
        }

        if ( node.up == 2 && current_status.up == BlockType::FREE ) {
            ++node.up;
            node.direction = Direction::UP;
            stack.push_back( node );
            ++Y;
            return Direction::UP;

        }
        return Direction::UP;
    }
}
