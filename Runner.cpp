//
// Created by tsv on 09.05.16.
//

#include <string>
#include <fstream>

#include "Runner.hpp"
#include "utils.hpp"

Runner::Runner() {
    char labyrinthNumber = 0;

    std::fstream file("counter", std::fstream::in);

    if (file.is_open()) {
        file.get(labyrinthNumber);
        char nextLabyrinthNumber = labyrinthNumber + 1;
        file.close();
        file.open("counter", std::fstream::out | std::fstream::trunc);
        file.put(nextLabyrinthNumber);
    } else {
        file.open("counter", std::fstream::out | std::fstream::trunc);
        char nextLabyrinthNumber = '2';
        file.put(nextLabyrinthNumber);
        labyrinthNumber = '1';
    }
    file.close();

    std::string command = "curl -o solution -s http://5.2.72.110:882/";
    switch(labyrinthNumber) {
        case '1':
            command += "1";
            break;
        case '2':
            command += "2";
            break;
        case '3':
            command += "3";
            break;
        default:
            break;
    }

    system(command.c_str());
    file.open("solution", std::fstream::in);
    if (file.is_open()) {
        char stepch;
        file.get(stepch);

        while(1) {
            if (file.eof()) {
                break;
            } else {
                switch (stepch) {
                    case 'a':
                        path.push_back(Direction::UP);
                        break;
                    case 'b':
                        path.push_back(Direction::DOWN);
                        break;
                    case 'c':
                        path.push_back(Direction::LEFT);
                        break;
                    case 'd': 
                        path.push_back(Direction::RIGHT);
                        break;
                    default:
                        break;
                }
                file.get(stepch);
            }
        }
    }
}

Direction Runner::step() {
    return path[i++];
}


