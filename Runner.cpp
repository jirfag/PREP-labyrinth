#include "Runner.hpp"
#include <stack>

struct cell { //0 - норм, 1 - был, 2 - был несколько раз
    short up = 0;
    short down = 0;
    short right = 0;
    short left = 0;
    Direction direction;
};

std::stack<cell> stack;

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
        stack.push( node );
    }

    if ( ( stack.top().right != 0 || current_status.right != BlockType::FREE ) &&
         ( stack.top().up != 0 || current_status.up != BlockType::FREE ) &&
         ( stack.top().left != 0 || current_status.left != BlockType::FREE ) &&
         ( stack.top().down != 0 || current_status.down != BlockType::FREE ) ) {
        stack.pop();
        switch ( stack.top().direction ) {
            case Direction::DOWN : {
                ++stack.top().down;
                return Direction::UP;
            }
            case Direction::RIGHT : {
                ++stack.top().right;
                return Direction::LEFT;
            }
            case Direction::LEFT : {
                ++stack.top().left;
                return Direction::RIGHT;
            }
            default: {
                ++stack.top().up;
                return Direction::DOWN;
            }
        }
    } else {
        if ( stack.top().right == 0 && current_status.right == BlockType::FREE ) {
            ++stack.top().right;
            stack.top().direction = Direction::RIGHT;
            cell node;
            ++node.left;

            stack.push( node );

            return Direction::RIGHT;
        }

        if ( stack.top().down == 0 && current_status.down == BlockType::FREE ) {
            ++stack.top().down;
            stack.top().direction = Direction::DOWN;
            cell node;
            ++node.up;

            stack.push( node );
            return Direction::DOWN;

        }

        if ( stack.top().left == 0 && current_status.left == BlockType::FREE ) {
            ++stack.top().left;
            stack.top().direction = Direction::LEFT;
            cell node;
            ++node.right;

            stack.push( node );
            return Direction::LEFT;
        }

        if ( stack.top().up == 0 && current_status.up == BlockType::FREE ) {
            ++stack.top().up;
            stack.top().direction = Direction::UP;
            cell node;
            ++node.down;

            stack.push( node );
            return Direction::UP;

        }
        if ( stack.top().right == 1 && current_status.right == BlockType::FREE ) {
            ++stack.top().right;
            stack.top().direction = Direction::RIGHT;
            cell node;
            ++node.left;

            stack.push( node );

            return Direction::RIGHT;
        }

        if ( stack.top().down == 1 && current_status.down == BlockType::FREE ) {
            ++stack.top().down;
            stack.top().direction = Direction::DOWN;
            cell node;
            ++node.up;

            stack.push( node );
            return Direction::DOWN;

        }

        if ( stack.top().left == 1 && current_status.left == BlockType::FREE ) {
            ++stack.top().left;
            stack.top().direction = Direction::LEFT;
            cell node;
            ++node.right;

            stack.push( node );
            return Direction::LEFT;
        }

        if ( stack.top().up == 1 && current_status.up == BlockType::FREE ) {
            ++stack.top().up;
            stack.top().direction = Direction::UP;
            cell node;
            ++node.down;

            stack.push( node );
            return Direction::UP;

        }
    }
    return Direction::UP;
}

