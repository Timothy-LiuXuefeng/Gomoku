#include "Class.h"

namespace Timothy
{
	Board::Board()
	{
		num = 0;
		for (int i = 0; i < NUM; ++i)
			for (int j = 0; j < NUM; ++j)
				blank[i][j] = 0;
	}
	int Board::Blank(int x, int y) { return blank[x][y]; }
	void Board::resetBlank()
	{
		num = 0;
		for (int i = 0; i < NUM; ++i)
			for (int j = 0; j < NUM; ++j)
				blank[i][j] = 0;
	}
	bool Board::act(int x, int y, int role)
	{
		if (x < 0 || x >= NUM || y < 0 || y >= NUM) return false;
		if (blank[x][y]) return false;
		blank[x][y] = role;
		++num;
		return true;
	}
	Judge::Judge() { result = 0; }
	int Judge::Result() { return result; }
	void Judge::resetResult() { result = 0; }
	int Judge::JudgeIfOver(int x, int y, int role, Board* obj)
	{
		int sum = 1, tmpx, tmpy;
		if (obj->num == NUM * NUM) 
		{
			result = 3;
			return result;
		}
		{	//up and down
			tmpx = x - 1, tmpy = y;
			while (1)
			{	//left
				if (tmpx < 0) break;
				if (obj->blank[tmpx--][y] == role) ++sum;
				else break;
			}
			tmpx = x + 1;
			while (1) 
			{	//right
				if (tmpx > NUM - 1) break;
				if (obj->blank[tmpx++][y] == role) ++sum;
				else break;
			}
			if (sum > 4) 
			{
				result = role;
				return result;
			}
		}
		{	//left and right
			sum = 1;
			tmpx = x, tmpy = y - 1;
			while (1)
			{	//up
				if (tmpy < 0) break;
				if (obj->blank[tmpx][tmpy--] == role) ++sum;
				else break;
			}
			tmpy = y + 1;
			while (1)
			{	//down
				if (tmpy > NUM - 1) break;
				if (obj->blank[tmpx][tmpy++] == role) ++sum;
				else break;
			}
			if (sum > 4)
			{
				result = role;
				return result;
			}
		}
		{	//main diagonal
			sum = 1;
			tmpx = x - 1, tmpy = y - 1;
			while (1)
			{
				if (tmpx < 0 || tmpy < 0) break;
				if (obj->blank[tmpx--][tmpy--] == role) ++sum;
				else break;
			}
			tmpx = x + 1, tmpy = y + 1;
			while (1) 
			{
				if (tmpx > NUM - 1 || tmpy >NUM - 1) break;
				if (obj->blank[tmpx++][tmpy++] == role) ++sum;
				else break;
			}
			if (sum > 4)
			{
				result = role;
				return result;
			}
		}
		{	//the other diagonal
			sum = 1;
			tmpx = x - 1, tmpy = y + 1;
			while (1) 
			{
				if (tmpx < 0 || tmpy > NUM - 1) break;
				if (obj->blank[tmpx--][tmpy++] == role) ++sum;
				else break;
			}
			tmpx = x + 1, tmpy = y - 1;
			while (1) 
			{
				if (tmpx > NUM - 1 || tmpy < 0) break;
				if (obj->blank[tmpx++][tmpy--] == role) ++sum;
				else break;
			}
			if (sum > 4) 
			{
				result = role;
				return result;
			}
		}
		return 0;
	}
}
