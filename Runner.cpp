//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include "utils.hpp"
#include <algorithm>

bool Point::operator==(const Point& point) const {
    return (point.x == this->x) && (point.y == this->y);
}

size_t PointHash::operator()(const Point &point) const {
    // Формула Кантора
    return (point.x + point.y) * (point.x + point.y + 1) / 2 + point.y;
}

Runner::Runner(): directions {
    Direction::UP,
    Direction::DOWN,
    Direction::LEFT,
    Direction::RIGHT
}  {
#if DEBUG
    steps.open("steps.txt", std::ofstream::out);
    std::cout << "Current" << "\t\t"
              << "Next"
              << std::endl;
#endif
}

#if DEBUG

Runner::~Runner() {
    steps.close();
}
#endif

Direction Runner::step() {

    incrementCurrentPositionPassagesCount();
    Direction nextDirection = getNextDirection();

#if DEBUG
    
    steps << currentPosition.x << ' ' << currentPosition.y << ' ' << labyrinthMap[Point({currentPosition.x, currentPosition.y})] << std::endl;
    std::cout << "(" << currentPosition.x << "; " << currentPosition.y << ")" << "\t\t"
              << "(" << getDirectionPoint(nextDirection).x << "; " << getDirectionPoint(nextDirection).y << ")"
              << std::endl;
#endif
    previousPosition = currentPosition;
    currentPosition = getDirectionPoint(nextDirection);
    return nextDirection;
}

// Возвращает массив возможных направлений, отсортированный по 
// количеству посещений ячейки
Direction Runner::getNextDirection() {
    Direction possibleDirections[4];
    unsigned short size = 0;

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
                possibleDirections[size] = directions[i];
                ++size;
                break;

            case BlockType::WALL:
                break;
        }
    }

    return *std::min_element(possibleDirections, possibleDirections + size, 
        [this](Direction lhs, Direction rhs) -> bool {
            if (getDirectionPoint(rhs) == previousPosition) {
                return 1;
            }

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
