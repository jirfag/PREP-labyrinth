//
// Created by tsv on 09.05.16.
//

#define DEBUG 0

#include "Runner.hpp"
#include "utils.hpp"

#if DEBUG
#include <iostream>
#endif

bool PointCompare::operator() (const Point& lhs, const Point& rhs) const {
   if (lhs.x < rhs.x) {
        return 1;
    } else if (lhs.x > rhs.x) {
        return 0;
    } else if (lhs.y < rhs.y) {
        return 1;
    } else {
        return 0;
    }
}

Runner::Runner(): directions {
    Direction::UP,
    Direction::DOWN,
    Direction::LEFT,
    Direction::RIGHT
}  {
#if DEBUG
    std::cout << "Current" << "\t\t"
              << "Next"
              << std::endl;
#endif
}

Direction Runner::step() {
#if DEBUG
    char ch;
    std::cin >> std::noskipws >> ch;
#endif

    incrementCurrentPositionPassagesCount();
    Direction nextDirection = getNextDirection();

#if DEBUG
    std::cout << "(" << currentPosition.x << "; " << currentPosition.y << ")" << "\t\t"
              << "(" << getDirectionPoint(nextDirection).x << "; " << getDirectionPoint(nextDirection).y << ")"
              << std::endl;
#endif

    currentPosition = getDirectionPoint(nextDirection);
    return nextDirection;
}

// Возвращает массив возможных направлений, отсортированный по 
// количеству посещений ячейки
Direction Runner::getNextDirection() {
    std::vector<Direction> possibleDirections;

    const BlockType blocks[] = {
        Runner::current_status.up,
        Runner::current_status.down,
        Runner::current_status.left,
        Runner::current_status.right
    };


    for (int i = 0; i < 4; ++i) {
        switch (blocks[i]) {
            case BlockType::EXIT:
                return directions[i];

            case BlockType::ENTER:
            case BlockType::FREE:
                possibleDirections.push_back(directions[i]);
                break;

            case BlockType::WALL:
                break;
        }
    }

    std::sort(possibleDirections.begin(), possibleDirections.end(),
        [this](Direction &lhs, Direction &rhs) -> bool {
            unsigned int lhsPassagesCount = 0;
            if (labyrinthMap.count(getDirectionPoint(lhs)) > 0) {
                lhsPassagesCount = labyrinthMap[getDirectionPoint(lhs)];
            }

            unsigned int rhsPassagesCount = 0;
            if (labyrinthMap.count(getDirectionPoint(rhs)) > 0) {
                rhsPassagesCount = labyrinthMap[getDirectionPoint(rhs)];
            }

            return lhsPassagesCount < rhsPassagesCount;
        }
    );

    return possibleDirections[0];
}

// Вычисляет координаты точки по направлению
Point Runner::getDirectionPoint(Direction direction) {
    Point point = currentPosition;

    switch (direction) {
        case Direction::UP:
            ++point.y;
            break;

        case Direction::DOWN:
            --point.y;
            break;

        case Direction::LEFT:
            --point.x;
            break;

        case Direction::RIGHT:
            ++point.x;
            break;
    }

    return point;
}

// Инкрементируем количество посещений текущей ячейки
void Runner::incrementCurrentPositionPassagesCount() {
    if (labyrinthMap.count(currentPosition) > 0) {
        ++labyrinthMap[currentPosition];
    } else {
        labyrinthMap.insert(std::pair<Point, unsigned short>(currentPosition, 1));
    }
}
