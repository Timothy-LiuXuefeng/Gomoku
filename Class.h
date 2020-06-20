
#ifndef CLASS_H

#define CLASS_H

namespace Timothy
{
	const int NUM = 19;
	class Judge;
	class Board
	{
	private:
		int blank[NUM][NUM];
		int num;	//Total number.
	public:
		Board();
		int Blank(int x, int y);
		void resetBlank();
		bool act(int x, int y, int role);	//1 for black, 2 for white
		friend class Judge;
	};
	class Judge //The system judging if one win or one lose or the board is full.
	{
	private:
		int result;	//0 For normal, 1 for black win, 2 for white win,3 for full.
	public:
		Judge();
		int Result();
		void resetResult();
		int JudgeIfOver(int x, int y, int role, Board* obj);	//0 For normal, 1 for black win, 2 for white win,3 for full.
	};
}

#endif
