//
// Created by tsv on 09.05.16.
//

#ifndef LABYRINTH_RUNNER_HPP
#define LABYRINTH_RUNNER_HPP

#include "RunnerBase.hpp"

#include <vector>
#include <memory>

class cell
{
public:
	cell() 
	{
        for (int i = 0; i < 7; i++)
        {
            Direction d;
            d_where.push_back(d);
        }
	}
	~cell()
	{
       // if(d_where != nullptr) delete[] d_where;
	}
	cell(const cell& c);
    std::vector<Direction> d_where;

	int n = 0;
	int kol = 0;
	int kol_sv = 0;

	cell operator =(const cell& c);
};

class Runner: public RunnerBase {

    public:
   // std::shared_ptr<int> a;
        std::vector<std::vector<std::shared_ptr<cell> > > quarter1;//x>=0 y>=0
        std::vector<std::vector<std::shared_ptr<cell> > > quarter2;//x<0 y>=0
        std::vector<std::vector<std::shared_ptr<cell> > > quarter3;//x<0 y<0
        std::vector<std::vector<std::shared_ptr<cell> > > quarter4;//x>=0 y<0 0 0 âõîä
		bool way = 0;//0 - īđ˙ėî, 1 - îáđāōíî
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
};


#endif //LABYRINTH_RUNNER_HPP
