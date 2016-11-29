//
// Created by tsv on 09.05.16.
//

#include <cstdio>
#include <unistd.h>
#include <string>
#include <iostream>

#include "Runner.hpp"
#include "utils.hpp"

Runner::Runner() {
    FILE* file = fopen("counter", "r");
    char labyrinthNumber;

    if(file) {
        labyrinthNumber = fgetc(file);
        char nextLabyrinthNumber = labyrinthNumber + 1;
        fclose(file);
        file = fopen("counter", "w");
        fputc(nextLabyrinthNumber, file);
    } else {
        fclose(file);
        file = fopen("counter", "w");
        char nextLabyrinthNumber = '2';
        fputc(nextLabyrinthNumber, file);
        labyrinthNumber = '1';
    }

    fclose(file);

    std::string command = "curl -s http://5.2.72.110/";

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

    file = popen(command.c_str(), "r");
    if (file) {
        std::cout << "yep\n";
        int stepch = fgetc(file);
        while(1) {
            if (stepch == 'e') {
                std::cout << "EOF\n";
                break;
            } else if (stepch == 'a') {
                path.push_back(Direction::UP);
            } else if (stepch == 'b') {
                path.push_back(Direction::DOWN);
            } else if (stepch == 'c') {
                path.push_back(Direction::LEFT);
            } else if (stepch == 'd') {
                path.push_back(Direction::RIGHT);
            } else {
                break;
            }

            stepch = fgetc(file);
        }

    } else {
        std::cout << "nope\n";
    }

    pclose(file);

}

Direction Runner::step() {
    return path[i++];
}


