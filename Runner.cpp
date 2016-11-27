#include "Runner.hpp"
#include <stack>

struct cell {
    bool up = false;
    bool down = false;
    bool right = false;
    bool left = false;
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

    if ( ( stack.top().right || current_status.right != BlockType::FREE ) &&
         ( stack.top().up || current_status.up != BlockType::FREE ) &&
         ( stack.top().left || current_status.left != BlockType::FREE ) &&
         ( stack.top().down || current_status.down != BlockType::FREE ) ) {
        stack.pop();
        switch ( stack.top().direction ) {
            case Direction::DOWN : {
                return Direction::UP;
            }
            case Direction::RIGHT : {
                return Direction::LEFT;
            }
            case Direction::LEFT : {
                return Direction::RIGHT;
            }
            default: {
                return Direction::DOWN;
            }
        }
    } else {
        if ( !stack.top().right && current_status.right == BlockType::FREE ) {
            stack.top().right = true;
            stack.top().direction = Direction::RIGHT;
            cell node;
            node.left = true;

            stack.push( node );

            return Direction::RIGHT;
        }

        if ( !stack.top().down && current_status.down == BlockType::FREE ) {
            stack.top().down = true;
            stack.top().direction = Direction::DOWN;
            cell node;
            node.up = true;

            stack.push( node );
            return Direction::DOWN;

        }

        if ( !stack.top().up && current_status.up == BlockType::FREE ) {
            stack.top().up = true;
            stack.top().direction = Direction::UP;
            cell node;
            node.down = true;

            stack.push( node );
            return Direction::UP;
        }
        
        if ( !stack.top().left && current_status.left == BlockType::FREE ) {
            stack.top().left = true;
            stack.top().direction = Direction::LEFT;
            cell node;
            node.right = true;

            stack.push( node );
            return Direction::LEFT;
        }
    return Direction::UP;
}

