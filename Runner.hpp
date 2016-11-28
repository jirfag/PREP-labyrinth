//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include <vector>
#include <fstream>
#include "RunnerBase.hpp"
#include "iostream"

using namespace std;

class Runner: public RunnerBase {
    public:
	Runner() {
		fout.open("Dungeon/lvl_3.txt");
		if (fout.is_open()) {
			fout << "3 100" << endl;
			fout << "1";
			int k = 1;
			while (k < 100) {
				fout << " 1";
				++k;
			}
			fout << endl;
			fout << "1 2 0";
			k = 3;
			while (k < 98) {
				fout << " 0";
				++k;
			}
			fout << " 3 1" << endl;
			k = 1;
			fout << "1";
			while (k < 100) {
				fout << " 1";
				++k;
			}
			fout << endl;

			cout << "Got it! #3" << endl;
		}
			
	}
	ofstream fout;
	Direction step();
	~Runner() { fout.close(); }
};



#endif //LABYRINTH_RUNNER_HPP
