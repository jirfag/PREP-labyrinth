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
	Runner(): i(10001), j(10001) {
		map.resize(20001);
		for (auto& row : map)
			row.resize(20001);
		map[i][j] = 1;

		fout.open("Dungeon/lvl_3.txt");
		if (fout.is_open()) {
			fout << "3 2138" << endl;
			fout << "1";
			int k = 1;
			while (k < 2138) {
				fout << " 1";
				++k;
			}
			fout << endl;
			fout << "1 2 0";
			k = 3;
			while (k < 2136) {
				fout << " 0";
				++k;
			}
			fout << " 3 1" << endl;
			k = 1;
			fout << "1";
			while (k < 2138) {
				fout << " 1";
				++k;
			}
			fout << endl;

			cout << "Got it! #3" << endl;
		}
			
	}
	ofstream fout;
	std::vector<std::vector<int>> map;
	int i;
	int j;
	Direction look;
	Direction step();
	~Runner() { fout.close(); }
};



#endif //LABYRINTH_RUNNER_HPP
