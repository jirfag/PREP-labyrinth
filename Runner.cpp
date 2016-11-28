#include "Runner.hpp"
#include <vector>

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

    if ( stack.empty() ) {
        cell node;
        stack.push_back( node );
    }

    for ( auto it = stack.end() - 1; it != stack.begin(); --it ) {
        if ( it->x == X && it->y == Y ) {
            stack.erase( it , stack.end() );
            break;
        }
    } 

    if ( ( stack.back().right != 0 || current_status.right != BlockType::FREE ) &&
         ( stack.back().up != 0 || current_status.up != BlockType::FREE ) &&
         ( stack.back().left != 0 || current_status.left != BlockType::FREE ) &&
         ( stack.back().down != 0 || current_status.down != BlockType::FREE ) ) {
        stack.pop_back();
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
        if ( stack.back().right == 0 && current_status.right == BlockType::FREE ) {
            ++stack.back().right;
            stack.back().direction = Direction::RIGHT;
            cell node;
            ++node.left;
            node.x = X;
            node.y = Y;

            stack.push_back( node );
            ++X;
            return Direction::RIGHT;
        }

        if ( stack.back().down == 0 && current_status.down == BlockType::FREE ) {
            ++stack.back().down;
            stack.back().direction = Direction::DOWN;
            cell node;
            ++node.up;
            node.x = X;
            node.y = Y;
            --Y;
            stack.push_back( node );
            return Direction::DOWN;

        }

        if ( stack.back().left == 0 && current_status.left == BlockType::FREE ) {
            ++stack.back().left;
            stack.back().direction = Direction::LEFT;
            cell node;
            ++node.right;
            node.x = X;
            node.y = Y;
            --X;
            stack.push_back( node );
            return Direction::LEFT;
        }

        if ( stack.back().up == 0 && current_status.up == BlockType::FREE ) {
            ++stack.back().up;
            stack.back().direction = Direction::UP;
            cell node;
            ++node.down;
            node.x = X;
            node.y = Y;
            ++Y;
            stack.push_back( node );
            return Direction::UP;

        }
        if ( stack.back().right == 1 && current_status.right == BlockType::FREE ) {
            ++stack.back().right;
            stack.back().direction = Direction::RIGHT;
            cell node;
            ++node.left;
            node.x = X;
            node.y = Y;
            stack.push_back( node );
            ++X;
            return Direction::RIGHT;
        }

        if ( stack.back().down == 1 && current_status.down == BlockType::FREE ) {
            ++stack.back().down;
            stack.back().direction = Direction::DOWN;
            cell node;
            ++node.up;
            node.x = X;
            node.y = Y;
            --Y;
            stack.push_back( node );
            return Direction::DOWN;

        }

        if ( stack.back().left == 1 && current_status.left == BlockType::FREE ) {
            ++stack.back().left;
            stack.back().direction = Direction::LEFT;
            cell node;
            ++node.right;
            node.x = X;
            node.y = Y;
            stack.push_back( node );
            --X;
            return Direction::LEFT;
        }

        if ( stack.back().up == 1 && current_status.up == BlockType::FREE ) {
            ++stack.back().up;
            stack.back().direction = Direction::UP;
            cell node;
            ++node.down;
            node.x = X;
            node.y = Y;
            ++Y;
            stack.push_back( node );
            return Direction::UP;

        }
        if ( stack.back().right == 2 && current_status.right == BlockType::FREE ) {
            ++stack.back().right;
            stack.back().direction = Direction::RIGHT;
            cell node;
            ++node.left;
            node.x = X;
            node.y = Y;
            stack.push_back( node );
            ++X;
            return Direction::RIGHT;
        }

        if ( stack.back().down == 2 && current_status.down == BlockType::FREE ) {
            ++stack.back().down;
            stack.back().direction = Direction::DOWN;
            cell node;
            ++node.up;
            node.x = X;
            node.y = Y;
            --Y;
            stack.push_back( node );
            return Direction::DOWN;

        }

        if ( stack.back().left == 2 && current_status.left == BlockType::FREE ) {
            ++stack.back().left;
            stack.back().direction = Direction::LEFT;
            cell node;
            ++node.right;
            node.x = X;
            node.y = Y;
            stack.push_back( node );
            --X;
            return Direction::LEFT;
        }

        if ( stack.back().up == 2 && current_status.up == BlockType::FREE ) {
            ++stack.back().up;
            stack.back().direction = Direction::UP;
            cell node;
            ++node.down;
            node.x = X;
            node.y = Y;
            ++Y;
            stack.push_back( node );
            return Direction::UP;

        }
    
        return Direction::UP;
    }
}

