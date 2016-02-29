#include "Reversi.h"
#include <iostream>
using namespace std;

Reversi::Reversi(void)
{
}
Checkerboard::Checkerboard(void){
	blackCount = 2;
	whiteCount = 2;
	currentPosition[0] = 0;
	currentPosition[1] = 0;
	sideLength = 8;
	initializeCheckerBoard();
}
 void Checkerboard ::initializeCheckerBoard(void){
	for (int j = 0;j < sideLength;j++)
	{
		for (int i = 0;i < sideLength;i++)
		{
			if ((i == 3 && j == 3) || (i == 4 && j == 4))
			{
				checkerboardInfo[i][j] = InfoValue::black;
			} 
			else if ((i == 3 && j == 4) || (i == 4 && j == 3))
			{
				checkerboardInfo[i][j] = InfoValue::white;
			} 
			else
			{
				checkerboardInfo[i][j] = InfoValue::none;
			}

		}
	}
};

 void Checkerboard::cursorMove(int input){
	 switch(input){
	 case 0://left
		 if(currentPosition[0]-1 >= 0)
			currentPosition[0] -= 1;
		 break;
	 case 1://up
		 if(currentPosition[1]-1 >= 0)
			 currentPosition[1] -= 1;
		 break;
	 case 2://down
		 if(currentPosition[1]+1 < 8)
			 currentPosition[1] += 1;
		 break;
	 case 3://right
		 if(currentPosition[0]+1 < 8)
			 currentPosition[0] += 1;
		 break;

	 }
 };

 int Checkerboard ::checkRow(int rowNum){

 };
 int Checkerboard ::checkColumn(int columnNum){

 };

 void Checkerboard ::setCheckerboardInfo(int x,int y,InfoValue value){

 };

string Checkerboard ::toString(void){
	string result = "";
	for (int j = 0;j < sideLength;j++)
	{
		for (int i = 0;i < sideLength;i++)
		{
			if(i == currentPosition[0]&&j == currentPosition[1]){
				result +=  "⊕";
			}else{
				switch(checkerboardInfo[i][j]){
				case InfoValue::black:
					result += "●";
					break;
				case InfoValue::white:
					result += "○";
					break;
				case InfoValue::none:
					result += "—";
					break;
				case InfoValue::selected:
					result += "⊕";
					break;
				case InfoValue::hint:
					result += "⊙";
					break;
				}
			}

		}
		result += "\n";
	}
	return result;
};
Reversi::~Reversi(void)
{
}

