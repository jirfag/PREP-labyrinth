#include "Runner.hpp"
#include <stack>
#include <vector>

struct cell {
    bool up = false;
    bool down = false;
    bool right = false;
    bool left = false;
    Direction direction;
};
std::stack<cell> stack;

struct position {
    long x = 0;
    long y = 0;
    bool up = false;
    bool down = false;
    bool right = false;
    bool left = false;

    position( long x, long y ) {
        this->x = x;
        this->y = y;
    }
};

std::vector<position> pos = {};

long X = 0;
long Y = 0;

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

    bool b = false;
    for ( auto &&temp : pos ) {
        if ( temp.x == X ) {
            if ( temp.y == Y ) {
                if ( temp.up ) {
                    stack.top().up = true;
                }
                if ( temp.left ) {
                    stack.top().left = true;
                }
                if ( temp.right ) {
                    stack.top().right = true;
                }
                if ( temp.down ) {
                    stack.top().down = true;
                }
            }
        }
    }

    position pos1( X, Y );
    pos.push_back( pos1 );

    if ( ( stack.top().right || current_status.right != BlockType::FREE ) &&
         ( stack.top().up || current_status.up != BlockType::FREE ) &&
         ( stack.top().left || current_status.left != BlockType::FREE ) &&
         ( stack.top().down || current_status.down != BlockType::FREE ) ) {
        stack.pop();
        switch ( stack.top().direction ) {
            case Direction::DOWN : {
                ++Y;
                return Direction::UP;
            }
            case Direction::RIGHT : {
                --X;
                return Direction::LEFT;
            }
            case Direction::LEFT : {
                ++X;
                return Direction::RIGHT;
            }
            default: {
                --Y;
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

            pos.back().right = true;
            ++X;
            return Direction::RIGHT;
        }

        if ( !stack.top().down && current_status.down == BlockType::FREE ) {
            stack.top().down = true;
            stack.top().direction = Direction::DOWN;
            cell node;
            node.up = true;

            stack.push( node );

            pos.back().down = true;
            --Y;
            return Direction::DOWN;

        }

        if ( !stack.top().left && current_status.left == BlockType::FREE ) {
            stack.top().left = true;
            stack.top().direction = Direction::LEFT;
            cell node;
            node.right = true;

            stack.push( node );

            pos.back().left = true;
            --X;
            return Direction::LEFT;
        }

        if ( !stack.top().up && current_status.up == BlockType::FREE ) {
            stack.top().up = true;
            stack.top().direction = Direction::UP;
            cell node;
            node.down = true;

            stack.push( node );

            pos.back().up = true;
            ++Y;
            return Direction::UP;

        }
    }
    pos.back().up = true;
    return Direction::UP;
}
