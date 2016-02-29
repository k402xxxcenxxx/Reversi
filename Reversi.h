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

	enum piece{
		blackPiece = 0,
		whitePiece = 1
	};
	enum InfoValue{
		none = 0,
		black = -1,
		white = 1,
		selected = 2,
		selectedOnBlack = -3,
		selectedOnWhite = 3,
		hint = 4,
		error = 99
	};

	int sideLength;
	piece currentPiece;
	int blackCount;
	int whiteCount;

	int currentPosition[2];//[0] is x,[1] is y

	InfoValue checkerboardInfo[8][8];

	void initializeCheckerBoard(void);

	InfoValue getCheckerboardInfo(int x,int y);
	void setCheckerboardInfo(int x,int y,InfoValue value);

	void cursorMove(int input);//0 = left,1 = up,2 = down,3 = right

	void undo(void);
	void redo(void);

	int checkRow(int rowNum);//return the position
	int checkColumn(int columnNum);
	bool checkFinished(void);
	std::string toString(void);
};

class Direction : Reversi{
public:
	Direction();
};
