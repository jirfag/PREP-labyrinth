#define Up current_status.up
#define Down current_status.down
#define Left current_status.left
#define Right current_status.right
#define Enter BlockType::ENTER
#define Exit BlockType::EXIT
#define Wall BlockType::WALL
#define Free BlockType::FREE
#define gol Direction::LEFT
#define gou Direction::UP
#define god Direction::DOWN
#define gor Direction::RIGHT


#include "Runner.hpp"

Direction face = gor;
int a = 1;

Direction right_hand(Status &current_status) {
    switch (face) {
        case gou: {
            if (Right == Free)
                return face = gor;
            else if (Up == Free)
                return gou;
            else if (Left == Free)
                return face = gol;
            else
                return face = god;

        }
        case gol: {
            if (Up == Free)
                return face = gou;
            else if (Left == Free)
                return gol;
            else if (Down == Free)
                return face = god;
            else
                return face = gor;

        }
        case god: {
            if (Left == Free)
                return face = gol;
            else if (Down == Free)
                return god;
            else if (Right == Free)
                return face = gor;
            else
                return face = gou;

        }
        default: {
            if (Down == Free)
                return face = god;
            else if (Right == Free)
                return gor;
            else if (Up == Free)
                return face = gou;
            else
                return face = gol;

        }
    }

}

Direction left_hand(Status &current_status) {
    switch (face) {
        case gou: {
            if (Left == Free)
                return face = gol;
            else if (Up == Free)
                return gou;
            else if (Right == Free)
                return face = gor;
            else
                return face = god;

        }
        case gol: {
            if (Down == Free)
                return face = god;
            else if (Left == Free)
                return gol;
            else if (Up == Free)
                return face = gou;
            else
                return face = gor;

        }
        case god: {
            if (Right == Free)
                return face = gor;
            else if (Down == Free)
                return god;
            else if (Left == Free)
                return face = gol;
            else
                return face = gou;

        }
        default: {
            if (Up == Free)
                return face = gou;
            else if (Right == Free)
                return gor;
            else if (Down == Free)
                return face = god;
            else
                return face = gol;

        }
    }

}

Direction Runner::step() {
    if (Left == Exit)
        return gol;
    if (Right == Exit)
        return gor;
    if (Up == Exit)
        return gou;
    if (Down == Exit)
        return god;
    a++;
    if ((a) % 24 == 0)
        return right_hand(current_status);
    else
        return left_hand(current_status);


}
