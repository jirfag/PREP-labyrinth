//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

#include <vector>

class cell
{
public:
	cell() 
	{
        d_where = new Direction[12];
	}
	~cell()
	{
        if(d_where != nullptr) delete[] d_where;
	}
	cell(const cell& c);
	Direction* d_where;

	int n = 0;
	int kol = 0;
	int kol_sv = 0;

	cell operator =(const cell& c);
};

class Runner: public RunnerBase {

    public:

		std::vector<std::vector<cell> > quarter1;//x>=0 y>=0
		std::vector<std::vector<cell> > quarter2;//x<0 y>=0
		std::vector<std::vector<cell> > quarter3;//x<0 y<0
		std::vector<std::vector<cell> > quarter4;//x>=0 y<0 0 0 âőîä
		bool way = 0;//0 - ďđ˙ěî, 1 - îáđŕňíî
		bool first = true;
        bool per = false;
        bool tup = false;
        bool kost = false;
		int kol = 0;
		int x = 0, y = 0;

        Direction step();
		Direction step_direct();
		Direction step_back();
        bool add_cell(int nx, int ny, cell& c, bool v);
        void change_xy(cell& c);
        void change_xy(Direction& c);
		cell know_prev();
		cell know_teck();
		cell know_prev_q1();
		cell know_prev_q2();
		cell know_prev_q3();
		cell know_prev_q4();


#endif //LABYRINTH_RUNNER_HPP
