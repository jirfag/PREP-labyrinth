//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
//#include <iostream>
#include <vector>
#include <cstdlib>
#include "utils.hpp"
#include <memory>

cell::cell(const cell& c)
{
	for (int i = 0; i < c.n; i++)
	{
        d_where.push_back(c.d_where[i]);
	}
    while (d_where.size() < 7)
    {
        Direction d;
        d_where.push_back(d);
    }
	n = c.n;
	kol = c.kol;
	kol_sv = c.kol_sv;
}
cell cell::operator =(const cell& c)
{
	for (int i = 0; i < c.n; i++)
	{
        d_where[i] = c.d_where[i];
	}
	n = c.n;
	kol = c.kol;
	kol_sv = c.kol_sv;
	return *this;
}

Direction set_where(Status st)
{

	if (st.right == BlockType::FREE)
	{
		return Direction::RIGHT;
	} 
	        if (st.up == BlockType::FREE)
            {
                return Direction::UP;
            }

    if (st.down == BlockType::FREE)
        {
            return Direction::DOWN;
	}
	    if (st.left == BlockType::FREE)
	{
		return Direction::LEFT;
	}
return Direction::DOWN;

}
Direction set_where(Status st, Direction d)
{
	if (st.right == BlockType::FREE || st.right == BlockType::ENTER)
    {
        if (d != Direction::RIGHT)
        {
            return Direction::RIGHT;
        }
    }

	if (st.up == BlockType::FREE || st.up == BlockType::ENTER)
    {
        if (d != Direction::UP)
        {
            return Direction::UP;
        }
    }

    
    if (st.left == BlockType::FREE || st.left == BlockType::ENTER)
    {
        if (d != Direction::LEFT)
        {
            return Direction::LEFT;
        }
    }
		    if (st.down == BlockType::FREE || st.down == BlockType::ENTER)
    {
        if (d != Direction::DOWN)
        {
                return Direction::DOWN;
        }
    }


return Direction::DOWN;

}
Direction set_where(Status st, std::vector<Direction> dir, int a, int n)
{
	int k = 0;
	if (st.right == BlockType::FREE || st.right == BlockType::ENTER)
	{
		k = 0;
        for (int i = a; i < n; i++)
		{
			if (dir[i] != Direction::RIGHT)
			{
				k++;
			}
		}
        if (k == n)
		{
			return Direction::RIGHT;
		}
	}
	if (st.up == BlockType::FREE || st.up == BlockType::ENTER)
	{
		k = 0;
        for (int i = a; i < n; i++)
		{
			if (dir[i] != Direction::UP)
			{
				k++;
			}
		}
        if (k == n)
		{
			return Direction::UP;
		}
	}

	if (st.down == BlockType::FREE || st.down == BlockType::ENTER)
    {
        k = 0;
        for (int i = a; i < n; i++)
        {
            if (dir[i] != Direction::DOWN)
            {
                k++;
            }
        }
        if (k == n)
        {
            return Direction::DOWN;
        }
    }
    if (st.left == BlockType::FREE || st.left == BlockType::ENTER)
    {
        k = 0;
        for (int i = a; i < n; i++)
        {
            if (dir[i] != Direction::LEFT)
            {
                k++;
            }
        }
        if (k == n)
        {
            return Direction::LEFT;
        }
    }
	    


    return Direction::DOWN;
}

int set_kol_sv(Status st)
{
	int kol = 0;
    if (st.right == BlockType::FREE || st.right == BlockType::ENTER)
	{
		kol++;
	}
    if (st.left == BlockType::FREE || st.left == BlockType::ENTER)
	{
		kol++;
	}
    if (st.up == BlockType::FREE || st.up == BlockType::ENTER)
	{
		kol++;
	}
    if (st.down == BlockType::FREE || st.down == BlockType::ENTER)
	{
		kol++;
	}
	return kol;
}



bool is_enter(Status st, Direction& dir)
{
	if (st.down == BlockType::EXIT)
	{
		dir = Direction::DOWN;
		return true;
	} 
	else if (st.left == BlockType::EXIT)
	{
		dir = Direction::LEFT;
		return true;
	}
	else if (st.right == BlockType::EXIT)
	{
		dir = Direction::RIGHT;
		return true;
	}
	else if (st.up == BlockType::EXIT)
	{
		dir = Direction::UP;
		return true;
	}
	return false; 
}

Direction naob(std::vector<Direction> dir,int i)
{
    Direction d;// = new Direction;
        switch (dir[i])
		{
		case Direction::LEFT:
            d = Direction::RIGHT;
			break;
		case Direction::RIGHT:
            d = Direction::LEFT;
			break;
		case Direction::UP:
            d = Direction::DOWN;
			break;
		case Direction::DOWN:
            d = Direction::UP;
			break;
		}
	return d;
}

Direction Runner::step()
{
	Direction st;


    if (is_enter(current_status, st))
	{
		return st;
	}
	if (!way)
	{	
		return step_direct();
	}
	else
	{
		return step_back();
	}

}

Direction Runner::step_direct()
{
	kol++;
	cell ch;
	ch.kol = kol;
    if(per)
    {
        cell ch11 = know_teck();
        per = false;
        if (ch11.n == ch11.kol_sv + 1)//1
        {
            change_xy(ch11.d_where[0]);
            add_cell(x, y, ch11, false);
            way = false;
            return step_back();
        }
        else
        {
            while(!add_cell(x, y, ch11, true) && ch11.n <= ch11.kol_sv)
            {
                Direction dd = set_where(current_status, ch11.d_where, 0, ch11.n);
                ch11.d_where[ch.n] = (dd);

                ch11.n++;
                ch11.kol_sv = set_kol_sv(current_status);
            }
            if (ch11.n > ch11.kol_sv)
            {
                kol -= 2;
                Direction dd = naob(ch11.d_where, 0);
                ch11.d_where[0] = dd;
                add_cell(x, y, ch11, false);
                way = false;
                return step_back();
            }
            change_xy(ch11);
            return ch11.d_where[ch11.n-1];
        }
    }
	if (first)
	{	
		ch.kol_sv = set_kol_sv(current_status);
        ch.d_where[1] = set_where(current_status);
        ch.d_where[0] = ch.d_where[1];
		first = false;
        ch.n += 2;
		add_cell(x, y, ch, false);
		change_xy(ch);
	}
	else
	{
        cell ch11 = know_prev();
        int kol1 = set_kol_sv(current_status);
        if (kol1 == 1)//0
		{
			way = true;
            ch.kol_sv = 0;
            Direction dd = naob(ch11.d_where, ch11.n - 1);
            ch.d_where[0] = dd;
            dd = (naob(ch11.d_where, ch11.n - 1));
            ch.d_where[1] = dd;
            ch.n = 2;
            add_cell(x, y, ch, false);
            tup = true;
			return step_back();
		}
		else
		{
			ch.kol_sv = kol1;
            Direction dd = set_where(current_status, naob(ch11.d_where , ch11.n-1));
            ch.d_where[1] = dd;
            (ch.n) = 2;
            ch.d_where[0] = ch11.d_where[ch11.n - 1];
            if (!add_cell(x, y, ch, true))
			{
                if (ch.kol_sv > ch.n)
                {
                    per = true;
                    kol--;
                    dd = naob(ch.d_where, 0);
                    ch.d_where[0] = dd;
                    do
                   {
                        dd = set_where(current_status, ch.d_where,0, ch.n);
                        ch.d_where[ch.n] = dd;
                        (ch.n)++ ;
                        add_cell(x, y, ch, false);
                    }while(!add_cell(x, y, ch, true) && ch.kol_sv >= ch.n);

                    if (ch.kol_sv >= ch.n)
                    {
                            return step_direct();
                    }
                    dd = naob(ch.d_where, 0);
                    ch.d_where[0] = dd;
                    kost = true;
                }
				way = true;
                tup = true;
                dd = naob(ch.d_where, 0);
                ch.d_where[ch.n] = dd;
                ch.n++;
                add_cell(x, y, ch, false);
                return step_back();
			}
			change_xy(ch);
		}
	}
	return ch.d_where[ch.n - 1];
}

Direction Runner::step_back()
{
    cell c = know_teck();
    if (first)
    {
        first = false;
        do
        {
            Direction dd = set_where(current_status, c.d_where,0, c.n);
            c.d_where[c.n] = dd;
            c.n++;
        }while (!add_cell(x, y, c, true));
        change_xy(c);
        way = false;
        return c.d_where[c.n-1];
    }
    if (tup)
    {
        tup = false;
        if (kost)
        {
            kol++;
        }
        else
        {
            kol--;
        }

        c.kol_sv = set_kol_sv(current_status);
        add_cell(x, y, c, false);
        change_xy(c);
        if (x == 0 && y == 0)
        {
            first = true;
        }
    }
    else
    if (c.kol_sv != 2 && c.n < c.kol_sv)
	{
		way = false;
        per = true;
        kol--;
        Direction dd = naob(c.d_where,0);
        if ( c.n == 2)
        {
            c.d_where[0] = dd;
        }
        do
        {
            dd = set_where(current_status, c.d_where, 0, c.n);
            c.d_where[c.n] = dd;

            c.n++;
            c.kol_sv = set_kol_sv(current_status);
        } while(!add_cell(x, y, c, true) && c.n <= c.kol_sv);
        if (c.n > c.kol_sv)
        {
            return step_back();
        }
        return step_direct();
	}
	else
	{
        Direction dd;
        per = false;
        if (c.kol_sv == 2)
        {
            dd = naob(c.d_where, 0);
            c.d_where[c.n]  = dd;
        }
        else
        {
            c.d_where[c.n] = (c.d_where[0]);
        }

		kol--;
		c.n++;
        c.kol_sv = set_kol_sv(current_status);
        add_cell(x, y, c, false);
        change_xy(c);
        if (x == 0 && y == 0)
        {
            first = true;
        }
        if (kost)
        {
            kost = false;
            kol--;
        }
	}
	return c.d_where[c.n - 1];
}

bool Runner::add_cell(int nx, int ny, cell& c, bool v)
{
    int xn = x, yn = y;
	if (nx >= 0 && ny >= 0)
	{
        unsigned int nnx = nx, nny = ny;

        while (nnx >= quarter1.size())
		{
            std::vector<std::shared_ptr<cell>> a;
			quarter1.push_back(a);
		}
        while (nny >= quarter1[nnx].size())
		{
            std::shared_ptr<cell> a(new cell);
            quarter1[nnx].push_back(a);
		}
        *quarter1[nnx][nny] = c;
	}
	else if (nx >= 0 && ny < 0)
	{
        unsigned int nnx = nx, nny = abs(ny) - 1;

        while (nnx >= quarter4.size())
		{
            std::vector<std::shared_ptr<cell>> a;
			quarter4.push_back(a);
		}
        while (nny >= quarter4[nnx].size())
		{
            std::shared_ptr<cell> a(new cell);
            quarter4[nnx].push_back(a);
		}
        *quarter4[nnx][nny] = c;

	}
	else if (nx < 0 && ny < 0)
	{
        unsigned int nnx = abs(nx) - 1, nny = abs(ny) - 1;
        while (nnx >= quarter3.size())
		{
            std::vector<std::shared_ptr<cell>> a;
			quarter3.push_back(a);
		}
        while (nny >= quarter3[nnx].size())
		{
            std::shared_ptr<cell> a(new cell);
            quarter3[nnx].push_back(a);
		}
        *quarter3[nnx][nny] = c;
	}
	else
	{
        unsigned int nnx = abs(nx) - 1, nny = ny;
        while (nnx >= quarter2.size())
		{
            std::vector<std::shared_ptr<cell>> a;
			quarter2.push_back(a);
		}
        while (nny >= quarter2[nnx].size())
		{
            std::shared_ptr<cell> a(new cell);
            quarter2[nnx].push_back(a);
		}
        *quarter2[nnx][nny] = c;
	}
    change_xy(c.d_where[c.n - 1]);
    cell c12 = know_teck();

    if (c12.kol != 0 && v)
    {
        x = xn;
        y = yn;
        return false;
    }

    x = xn;
    y = yn;
	return true;
}

void Runner::change_xy(Direction& c)
{
    switch (c)
    {
    case Direction::DOWN:
        y--;
        break;
    case Direction::LEFT:
        x--;
        break;
    case Direction::RIGHT:
        x++;
        break;
    case Direction::UP:
        y++;
        break;
    }
}

void Runner::change_xy(cell& c)
{
	switch (c.d_where[c.n-1])
	{
	case Direction::DOWN:
		y--;
		break;
	case Direction::LEFT:
		x--;
		break;
	case Direction::RIGHT:
		x++;
		break;
	case Direction::UP:
		y++;
		break;
	}
}

cell Runner::know_prev()
{
	if (x >= 0 && y >= 0)
	{
		return know_prev_q1();
	}
	else if (x >= 0 && y < 0)
	{
		return know_prev_q4();
	}
	else if (x < 0 && y < 0)
	{
		return know_prev_q3();
	}
	else
	{
		return know_prev_q2();
	}
}
cell Runner::know_teck()
{
	if (x >= 0 && y >= 0)
	{
        unsigned int nx = x, ny = y;
        if(quarter1.size() > nx && quarter1[x].size() > ny)
        return *quarter1[x][y];
	}
	if (x >= 0 && y < 0)
	{
        unsigned int nx = x, ny = abs(y) - 1;
        if (quarter4.size() > nx && quarter4[x].size() > ny)
        return *quarter4[x][abs(y) - 1];
	}
	if (x < 0 && y < 0)
	{
        unsigned int nx = abs(x) - 1, ny = abs(y) - 1;
        if (quarter3.size() > nx && quarter3[abs(x) - 1].size() > ny)
        return *quarter3[abs(x) - 1][abs(y) - 1];
	}
	if (x < 0 && y >= 0)
	{
        unsigned int nx = abs(x) - 1, ny = y;
        if (quarter2.size() > nx && quarter2[abs(x) - 1].size() > ny)
        return *quarter2[abs(x) - 1][y];
	}
    cell asd;
    return asd;
}


cell Runner::know_prev_q1()
{
	if (x == 0 && y == 0)
	{
        if (quarter1.size() > 1 && quarter1[1].size() > 0 && quarter1[1][0]->kol == kol - 1)
		{
            return *quarter1[1][0];
		}
        if (quarter1.size() > 0 && quarter1[0].size() > 1 && quarter1[0][1]->kol == kol - 1)
		{
            return *quarter1[0][1];
		}
        if (quarter2.size() > 0 && quarter2[0].size() > 0 && quarter2[0][0]->kol == kol - 1)
		{
            return *quarter2[0][0];
		}
        if (quarter4.size() > 0 && quarter4[0].size() > 0 && quarter4[0][0]->kol == kol - 1)
		{
            return *quarter4[0][0];
		}
	} 
	if (x == 0)
	{
        unsigned int ny = y;
        if (quarter1.size() > 1 && quarter1[1].size() > ny && quarter1[1][y]->kol == kol - 1)
		{
            return *quarter1[1][y];
		}
        if (quarter1.size() > 0 && quarter1[0].size() > ny + 1 && quarter1[0][y + 1]->kol == kol - 1)
		{
            return *quarter1[0][y + 1];
		}
        if (quarter2.size() > 0 && quarter2[0].size() > ny && quarter2[0][y]->kol == kol - 1)
		{
            return *quarter2[0][y];
		}
        if (quarter1.size() > 0 && quarter1[0].size() > ny - 1 && quarter1[0][y - 1]->kol == kol - 1)
		{
            return *quarter1[0][y - 1];
		}
	}
	if (y == 0)
	{
        unsigned int nx = x;
        if (quarter1.size() > nx + 1 && quarter1[x + 1].size() > 0 && quarter1[x + 1][0]->kol == kol - 1)
		{
            return *quarter1[x + 1][0];
		}
        if (quarter1.size() > nx && quarter1[x].size() > 1 && quarter1[x][1]->kol == kol - 1)
		{
            return *quarter1[x][1];
		}

        if (quarter1.size() > nx - 1 && quarter1[x - 1].size() > 0 && quarter1[x - 1][0]->kol == kol - 1)
		{
            return *quarter1[x - 1][0];
		}
        if (quarter4.size() > nx && quarter4[x].size() > 0 && quarter4[x][0]->kol == kol - 1)
		{
            return *quarter4[x][0];
		}
	}
    unsigned int ny = y;
    unsigned int nx = x;
    if (quarter1.size() > nx + 1 && quarter1[x + 1].size() > (ny) && quarter1[x + 1][y]->kol == kol - 1)
	{
        return *quarter1[x + 1][y];
	}
    if (quarter1.size() > nx && quarter1[x].size() > (ny + 1) && quarter1[x][y + 1]->kol == kol - 1)
	{
        return *quarter1[x][y + 1];
	}
    if (quarter1.size() > nx - 1 && quarter1[x - 1].size() > (ny) && quarter1[x - 1][y]->kol == kol - 1)
	{
        return *quarter1[x - 1][y];
	}
    if (quarter1.size() > nx && quarter1[x].size() > (ny - 1) && quarter1[x][y - 1]->kol == kol - 1)
	{
        return *quarter1[x][y - 1];
	}
    cell asd;
    return asd;
}
cell Runner::know_prev_q2()
{
    unsigned int nx = abs(x) - 1, ny = y;
	if (nx == 0 && ny == 0)
	{
        if (quarter1.size() > 0 && quarter1[0].size() > 0 && quarter1[0][0]->kol == kol - 1)
		{
            return *quarter1[0][0];
		}
        if (quarter2.size() > 0 && quarter2[0].size() > 1 && quarter2[0][1]->kol == kol - 1)
		{
            return *quarter2[0][1];
		}
        if (quarter2.size() > 1 && quarter2[1].size() > 0 && quarter2[1][0]->kol == kol - 1)
		{
            return *quarter2[1][0];
		}
        if (quarter3.size() > 0 && quarter3[0].size() > 0 && quarter3[0][0]->kol == kol - 1)
		{
            return *quarter3[0][0];
		}
	}
	if (nx == 0)
	{
        if (quarter1.size() > 0 && quarter1[0].size() > ny && quarter1[0][ny]->kol == kol - 1)
		{
            return *quarter1[0][ny];
		}
        if (quarter2.size() > 0 && quarter2[0].size() > ny + 1 && quarter2[0][ny + 1]->kol == kol - 1)
		{
            return *quarter2[0][ny + 1];
		}
        if (quarter2.size() > 1 && quarter2[1].size() > ny && quarter2[1][ny]->kol == kol - 1)
		{
            return *quarter2[1][ny];
		}
        if (quarter2.size() > 0 && quarter2[0].size() > ny - 1 && quarter2[0][ny - 1]->kol == kol - 1)
		{
            return *quarter2[0][ny - 1];
		}
	}
	if (y == 0)
	{
        if (quarter2.size() > nx - 1 && quarter2[nx - 1].size() > 0 && quarter2[nx - 1][0]->kol == kol - 1)
		{
            return *quarter2[nx - 1][0];
		}
        if (quarter2.size() > nx && quarter2[nx].size() > 1 && quarter2[nx][1]->kol == kol - 1)
		{
            return *quarter2[nx][1];
		}
        if (quarter2.size() > nx + 1 && quarter2[nx + 1].size() > 0 && quarter2[nx + 1][0]->kol == kol - 1)
		{
            return *quarter2[nx + 1][0];
		}
        if (quarter3.size() > nx && quarter3[nx].size() > 0 && quarter3[nx][0]->kol == kol - 1)
		{
            return *quarter3[nx][0];
		}
	}
    if (quarter2.size() > nx - 1 && quarter2[nx - 1].size() > ny && quarter2[nx - 1][ny]->kol == kol - 1)
	{
        return *quarter2[nx - 1][ny];
	}
    if (quarter2.size() > nx && quarter2[nx].size() > (ny + 1) && quarter2[nx][ny + 1]->kol == kol - 1)
	{
        return *quarter2[nx][ny + 1];
	}
    if (quarter2.size() > nx + 1 && quarter2[nx + 1].size() > (ny) && quarter2[nx + 1][ny]->kol == kol - 1)
	{
        return *quarter2[nx + 1][ny];
	}
    if (quarter2.size() > nx && quarter2[nx].size() > (ny - 1) && quarter2[nx][ny - 1]->kol == kol - 1)
	{
        return *quarter2[nx][ny - 1];
	}
    cell asd;
    return asd;
}
cell Runner::know_prev_q3()
{
    unsigned int nx = abs(x) - 1, ny = abs(y) - 1;
	if(nx == 0 && ny == 0)
	{
        if (quarter4.size() > 0 && quarter4[0].size() > 0 && quarter4[0][0]->kol == kol - 1)
		{
            return *quarter4[0][0];
		}
        if (quarter2.size() > 0 && quarter2[0].size() > 0 && quarter2[0][0]->kol == kol - 1)
		{
            return *quarter2[0][0];
		}
        if (quarter3.size() > 1 && quarter3[1].size() > 0 && quarter3[1][0]->kol == kol - 1)
		{
            return *quarter3[1][0];
		}
        if (quarter3.size() > 0 && quarter3[0].size() > 1 && quarter3[0][1]->kol == kol - 1)
		{
            return *quarter3[0][1];
		}
	}
	if (nx == 0)
	{
        if (quarter4.size() > 0 && quarter4[0].size() > ny && quarter4[0][ny]->kol == kol - 1)
		{
            return *quarter4[0][ny];
		}
        if (quarter3.size() > 0 && quarter3[0].size() > ny - 1 && quarter3[0][ny - 1]->kol == kol - 1)
		{
            return *quarter3[0][ny - 1];
		}
        if (quarter3.size() > 1 && quarter3[1].size() > ny && quarter3[1][ny]->kol == kol - 1)
		{
            return *quarter3[1][ny];
		}
        if (quarter3.size() > 0 && quarter3[0].size() > ny + 1 && quarter3[0][ny + 1]->kol == kol - 1)
		{
            return *quarter3[0][ny + 1];
		}
	}
	if (ny == 0) 
	{
        if (quarter3.size() > nx - 1 && quarter3[nx - 1].size() > 0 && quarter3[nx - 1][0]->kol == kol - 1)
		{
            return *quarter3[nx - 1][0];
		}
        if (quarter2.size() > nx && quarter2[nx].size() > 0 && quarter2[nx][0]->kol == kol - 1)
		{
            return *quarter2[nx][0];
		}
        if (quarter3.size() > nx + 1 && quarter3[nx + 1].size() > 0 && quarter3[nx + 1][0]->kol == kol - 1)
		{
            return *quarter3[nx + 1][0];
		}
        if (quarter3.size() > nx && quarter3[nx].size() > 1 && quarter3[nx][1]->kol == kol - 1)
		{
            return *quarter3[nx][1];
		}
	}
    if (quarter3.size() > nx - 1 && quarter3[nx - 1].size() > ny && quarter3[nx - 1][ny]->kol == kol - 1)
	{
        return *quarter3[nx - 1][ny];
	}
    if (quarter3.size() > nx && quarter3[nx].size() > (ny - 1) && quarter3[nx][ny - 1]->kol == kol - 1)
	{
        return *quarter3[nx][ny - 1];
	}
    if (quarter3.size() > nx + 1 && quarter3[nx + 1].size() > ny && quarter3[nx + 1][ny]->kol == kol - 1)
	{
        return *quarter3[nx + 1][ny];
	}
    if (quarter3.size() > nx && quarter3[nx].size() > (ny + 1) && quarter3[nx][ny + 1]->kol == kol - 1)
	{
        return *quarter3[nx][ny + 1];
	}
    cell asd;
    return asd;
}
cell Runner::know_prev_q4()
{
    unsigned int nx = x;
    unsigned int ny = abs(y) - 1;
	if (nx == 0 && ny == 0)
	{
        if (quarter4.size() > 1 && quarter4[1].size() > 0 && quarter4[1][0]->kol == kol - 1)
		{
            return *quarter4[1][0];
		}
        if (quarter1.size() > 0 && quarter1[0].size() > 0 && quarter1[0][0]->kol == kol - 1)
		{
            return *quarter1[0][0];
		}
        if (quarter3.size() > 0 && quarter3[0].size() > 0 && quarter3[0][0]->kol == kol - 1)
		{
            return *quarter3[0][0];
		}
        if (quarter4.size() > 0 && quarter4[0].size() > 1 && quarter4[0][1]->kol == kol - 1)
		{
            return *quarter4[0][1];
		}
	}
	if (nx == 0)
	{
        if (quarter4.size() > 1 && quarter4[1].size() > ny && quarter4[1][ny]->kol == kol - 1)
		{
            return *quarter4[1][ny];
		}
        if (quarter4.size() > 0 && quarter4[0].size() > (ny - 1) && quarter4[0][ny - 1]->kol == kol - 1)
		{
            return *quarter4[0][ny - 1];
		}
        if (quarter3.size() > 0 && quarter3[0].size() > ny && quarter3[0][ny]->kol == kol - 1)
		{
            return *quarter3[0][ny];
		}
        if (quarter4.size() > 0 && quarter4[0].size() > (ny + 1) && quarter4[0][ny + 1]->kol == kol - 1)
		{
            return *quarter4[0][ny + 1];
		}
	}
	if (ny == 0)
	{
        if (quarter4.size() > (nx + 1) && quarter4[nx+1].size() > 0 && quarter4[nx + 1][0]->kol == kol - 1)
		{
            return *quarter4[nx + 1][0];
		}
        if (quarter1.size() > nx && quarter1[nx].size() > 0 && quarter1[nx][0]->kol == kol - 1)
		{
            return *quarter1[nx][0];
		}
        if (quarter4.size() > (nx - 1) && quarter4[nx - 1].size() > 0 && quarter4[nx - 1][0]->kol == kol - 1)
		{
            return *quarter4[nx - 1][0];
		}
        if (quarter4.size() > nx && quarter4[nx].size() > 1 && quarter4[nx][1]->kol == kol - 1)
		{
            return *quarter4[nx][1];
		}
	}
    if (quarter4.size() > nx + 1 && quarter4[nx + 1].size() > ny && quarter4[nx + 1][ny]->kol == kol - 1)
	{
        return *quarter4[nx + 1][ny];
	}
    if (quarter4.size() > nx && quarter4[nx].size() > (ny - 1) && quarter4[nx][ny - 1]->kol == kol - 1)
	{
        return *quarter4[nx][ny - 1];
	}
    if (quarter4.size() > nx - 1 && quarter4[nx - 1].size() > ny && quarter4[nx - 1][ny]->kol == kol - 1)
	{
        return *quarter4[nx - 1][ny];
	}
    if (quarter4.size() > nx && quarter4[nx].size() > (ny + 1) && quarter4[nx][ny + 1]->kol == kol - 1)
	{
        return *quarter4[nx][ny + 1];
	}
    cell ad;
    return ad;
}
