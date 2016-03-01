#pragma once
#include <iostream>
using namespace std;
class Reversi
{
public:
	Reversi(void);
	~Reversi(void);

};

class Checkerboard : public Reversi{
public:
	Checkerboard(void);

	enum chess{
		blackChess = 0,
		whiteChess = 1
	};
	enum InfoValue{
		none = 0,
		black = -1,
		white = 1,
		hint = 4,
		error = 99
	};

	int sideLength;
	chess currentChess;
	int blackCount;
	int whiteCount;

	int currentPosition[2];//[0] is x,[1] is y

	InfoValue checkerboardInfo[8][8];

	void initializeCheckerBoard(void);

	void setCheckerboardInfo(int PosX,int PosY,InfoValue value);

	void cursorMove(int input);//0 = left,1 = up,2 = down,3 = right

	void undo(void);
	void redo(void);

	int checkRight(int PosX, int PosY);//return gain chesss. if it returns less than 0, means it's not legal
	int checkLeft(int PosX, int PosY);//return gain chesss. if it returns less than 0, means it's not legal
	int checkUp(int PosX, int PosY);//return gain chesss. if it returns less than 0, means it's not legal
	int checkDown(int PosX, int PosY);//return gain chesss. if it returns less than 0, means it's not legal
	int checkRightUp(int PosX, int PosY);//return gain chesss. if it returns less than 0, means it's not legal
	int checkRightDown(int PosX, int PosY);//return gain chesss. if it returns less than 0, means it's not legal
	int checkLeftUp(int PosX, int PosY);//return gain chesss. if it returns less than 0, means it's not legal
	int checkLeftDown(int PosX, int PosY);//return gain chesss. if it returns less than 0, means it's not legal

	bool checkLegal(int PosX,int PosY);//check if legal

	bool checkFinished(void);
	std::string toString(void);
};

class Direction : Reversi{
public:
	Direction();
};
