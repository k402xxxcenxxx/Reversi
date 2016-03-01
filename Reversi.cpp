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
	currentChess = chess::blackChess;
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

int Checkerboard::checkRight(int PosX, int PosY){
	 InfoValue myValue, enemyValue;
	 int rowNum = PosY;
	 int colNum = PosX + 1;
	 int gainValue = 0;

	 //comfirm target chess
	 if (currentChess == chess::blackChess){
		 myValue = InfoValue::black;
		 enemyValue = InfoValue::white;
	 }
	 else if (currentChess == chess::whiteChess){
		 myValue = InfoValue::white;
		 enemyValue = InfoValue::black;
	 }

	 //beside must be enemy
	 if (checkerboardInfo[rowNum][colNum] == enemyValue){
		 gainValue++;

		 //check from left to right
		 for (colNum+=1; colNum < sideLength; colNum++){
			 if (checkerboardInfo[rowNum][colNum] == myValue){
				 //finish gain chess
				 return gainValue;
			 }
			 else if (checkerboardInfo[rowNum][colNum] == enemyValue){
				 gainValue++;
			 }
		 }

		 //there is no my chess on the other side
		 return -1;
	 }
	 else{
		 return -1;
	 }

 };

int Checkerboard::checkLeft(int PosX, int PosY){
	InfoValue myValue, enemyValue;
	int rowNum = PosY;
	int colNum = PosX - 1;
	int gainValue = 0;

	//comfirm target chess
	if (currentChess == chess::blackChess){
		myValue = InfoValue::black;
		enemyValue = InfoValue::white;
	}
	else if (currentChess == chess::whiteChess){
		myValue = InfoValue::white;
		enemyValue = InfoValue::black;
	}

	//beside must be enemy
	if (checkerboardInfo[rowNum][colNum] == enemyValue){
		gainValue++;

		//check from right to left  
		for (colNum -= 1; colNum >= 0; colNum--){
			if (checkerboardInfo[rowNum][colNum] == myValue){
				//finish gain chess
				return gainValue;
			}
			else if (checkerboardInfo[rowNum][colNum] == enemyValue){
				gainValue++;
			}
		}

		//there is no my chess on the other side
		return -1;
	}
	else{
		return -1;
	}

};

int Checkerboard::checkUp(int PosX, int PosY){
	InfoValue myValue, enemyValue;
	int rowNum = PosY - 1;
	int colNum = PosX;
	int gainValue = 0;

	//comfirm target chess
	if (currentChess == chess::blackChess){
		myValue = InfoValue::black;
		enemyValue = InfoValue::white;
	}
	else if (currentChess == chess::whiteChess){
		myValue = InfoValue::white;
		enemyValue = InfoValue::black;
	}

	//beside must be enemy
	if (checkerboardInfo[rowNum][colNum] == enemyValue){
		gainValue++;

		//check from down to up  
		for (rowNum -= 1; rowNum >= 0; rowNum--){
			if (checkerboardInfo[rowNum][colNum] == myValue){
				//finish gain chess
				return gainValue;
			}
			else if (checkerboardInfo[rowNum][colNum] == enemyValue){
				gainValue++;
			}
		}

		//there is no my chess on the other side
		return -1;
	}
	else{
		return -1;
	}

};

int Checkerboard::checkDown(int PosX, int PosY){
	InfoValue myValue, enemyValue;
	int rowNum = PosY + 1;
	int colNum = PosX;
	int gainValue = 0;

	//comfirm target chess
	if (currentChess == chess::blackChess){
		myValue = InfoValue::black;
		enemyValue = InfoValue::white;
	}
	else if (currentChess == chess::whiteChess){
		myValue = InfoValue::white;
		enemyValue = InfoValue::black;
	}

	//beside must be enemy
	if (checkerboardInfo[rowNum][colNum] == enemyValue){
		gainValue++;

		//check from up to down  
		for (rowNum += 1; rowNum < sideLength; rowNum++){
			if (checkerboardInfo[rowNum][colNum] == myValue){
				//finish gain chess
				return gainValue;
			}
			else if (checkerboardInfo[rowNum][colNum] == enemyValue){
				gainValue++;
			}
		}

		//there is no my chess on the other side
		return -1;
	}
	else{
		return -1;
	}

};

int Checkerboard::checkRightUp(int PosX, int PosY){
	InfoValue myValue, enemyValue;
	int rowNum = PosY - 1;
	int colNum = PosX + 1;
	int gainValue = 0;

	//comfirm target chess
	if (currentChess == chess::blackChess){
		myValue = InfoValue::black;
		enemyValue = InfoValue::white;
	}
	else if (currentChess == chess::whiteChess){
		myValue = InfoValue::white;
		enemyValue = InfoValue::black;
	}

	//beside must be enemy
	if (checkerboardInfo[rowNum][colNum] == enemyValue){
		gainValue++;

		//check from leftdown to rightup  
		for (rowNum -= 1, colNum += 1; rowNum >= 0 && colNum < sideLength; rowNum--, colNum++){
			if (checkerboardInfo[rowNum][colNum] == myValue){
				//finish gain chess
				return gainValue;
			}
			else if (checkerboardInfo[rowNum][colNum] == enemyValue){
				gainValue++;
			}
		}

		//there is no my chess on the other side
		return -1;
	}
	else{
		return -1;
	}

};

int Checkerboard::checkRightDown(int PosX, int PosY){
	InfoValue myValue, enemyValue;
	int rowNum = PosY + 1;
	int colNum = PosX + 1;
	int gainValue = 0;

	//comfirm target chess
	if (currentChess == chess::blackChess){
		myValue = InfoValue::black;
		enemyValue = InfoValue::white;
	}
	else if (currentChess == chess::whiteChess){
		myValue = InfoValue::white;
		enemyValue = InfoValue::black;
	}

	//beside must be enemy
	if (checkerboardInfo[rowNum][colNum] == enemyValue){
		gainValue++;

		//check from leftup to rightdown  
		for (rowNum += 1, colNum += 1; rowNum < sideLength && colNum < sideLength; rowNum++, colNum++){
			if (checkerboardInfo[rowNum][colNum] == myValue){
				//finish gain chess
				return gainValue;
			}
			else if (checkerboardInfo[rowNum][colNum] == enemyValue){
				gainValue++;
			}
		}

		//there is no my chess on the other side
		return -1;
	}
	else{
		return -1;
	}

};

int Checkerboard::checkLeftUp(int PosX, int PosY){
	InfoValue myValue, enemyValue;
	int rowNum = PosY - 1;
	int colNum = PosX - 1;
	int gainValue = 0;

	//comfirm target chess
	if (currentChess == chess::blackChess){
		myValue = InfoValue::black;
		enemyValue = InfoValue::white;
	}
	else if (currentChess == chess::whiteChess){
		myValue = InfoValue::white;
		enemyValue = InfoValue::black;
	}

	//beside must be enemy
	if (checkerboardInfo[rowNum][colNum] == enemyValue){
		gainValue++;

		//check from rightdown to leftup  
		for (rowNum -= 1, colNum -= 1; rowNum >= 0 && colNum >= 0; rowNum--, colNum--){
			if (checkerboardInfo[rowNum][colNum] == myValue){
				//finish gain chess
				return gainValue;
			}
			else if (checkerboardInfo[rowNum][colNum] == enemyValue){
				gainValue++;
			}
		}

		//there is no my chess on the other side
		return -1;
	}
	else{
		return -1;
	}

};

int Checkerboard::checkLeftDown(int PosX, int PosY){
	InfoValue myValue, enemyValue;
	int rowNum = PosY + 1;
	int colNum = PosX - 1;
	int gainValue = 0;

	//comfirm target chess
	if (currentChess == chess::blackChess){
		myValue = InfoValue::black;
		enemyValue = InfoValue::white;
	}
	else if (currentChess == chess::whiteChess){
		myValue = InfoValue::white;
		enemyValue = InfoValue::black;
	}

	//beside must be enemy
	if (checkerboardInfo[rowNum][colNum] == enemyValue){
		gainValue++;

		//check from rightup to leftdown  
		for (rowNum += 1, colNum -= 1; rowNum < sideLength && colNum >= 0; rowNum++, colNum--){
			if (checkerboardInfo[rowNum][colNum] == myValue){
				//finish gain chess
				return gainValue;
			}
			else if (checkerboardInfo[rowNum][colNum] == enemyValue){
				gainValue++;
			}
		}

		//there is no my chess on the other side
		return -1;
	}
	else{
		return -1;
	}

};

 bool Checkerboard::checkLegal(int PosX, int PosY){
	 if (checkRight(PosX, PosY) > 0 ||
		 checkLeft(PosX, PosY) > 0 ||
		 checkUp(PosX, PosY) > 0 ||
		 checkDown(PosX, PosY) > 0 ||
		 checkRightUp(PosX, PosY) > 0 ||
		 checkRightDown(PosX, PosY) > 0 ||
		 checkLeftUp(PosX, PosY) > 0 ||
		 checkLeftDown(PosX, PosY) > 0){

		 return true;
	 }
	 else{
		 return false;
	 }
 };//check if legal



string Checkerboard ::toString(void){
	string result = "";
	for (int rowNum = 0; rowNum < sideLength; rowNum++)
	{
		for (int colNum = 0; colNum < sideLength; colNum++)
		{
			if (colNum == currentPosition[0] && rowNum == currentPosition[1]){
				if (checkerboardInfo[colNum][rowNum] == InfoValue::black){
					result += "◆";
				}
				else if (checkerboardInfo[colNum][rowNum] == InfoValue::white){
					result +=  "◇";
				}
				else{
					result += "⊕";
				}
			}else{
				switch (checkerboardInfo[colNum][rowNum]){
				case InfoValue::black:
					result += "●";
					break;
				case InfoValue::white:
					result += "○";
					break;
				case InfoValue::none:
					if (checkLegal(colNum, rowNum)){
						result += "⊙";
					}
					else
					{
						result += "—";
					}

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

