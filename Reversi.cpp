#include "Reversi.h"
#include <iostream>
#include <string>
using namespace std;

Reversi::Reversi(void)
{
}
Checkerboard::Checkerboard(void){
	isFinished = false;
	blackCount = 2;
	whiteCount = 2;
	currentPosition[0] = 0;
	currentPosition[1] = 0;
	sideLength = 8;
	Log = "";
	showedLog = "";
	
	chessManualIndex = -1;
	step = -1;
	initializeCheckerBoard();
}
 void Checkerboard ::initializeCheckerBoard(void){
	 Log = "";
	 showedLog = "";
	 chessManualIndex = -1;
	 step = -1;
	 currentChess = chess::whiteChess;
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

	saveCurrentChessManual();
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
 };//0 = left,1 = up,2 = down,3 = right

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
			 else if (checkerboardInfo[rowNum][colNum] == InfoValue::none){
				 return -1;
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
			else if (checkerboardInfo[rowNum][colNum] == InfoValue::none){
				return -1;
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
			else if (checkerboardInfo[rowNum][colNum] == InfoValue::none){
				return -1;
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
			else if (checkerboardInfo[rowNum][colNum] == InfoValue::none){
				return -1;
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
			else if (checkerboardInfo[rowNum][colNum] == InfoValue::none){
				return -1;
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
			else if (checkerboardInfo[rowNum][colNum] == InfoValue::none){
				return -1;
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
			else if (checkerboardInfo[rowNum][colNum] == InfoValue::none){
				return -1;
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
			else if (checkerboardInfo[rowNum][colNum] == InfoValue::none){
				return -1;
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
	 if (checkerboardInfo[PosY][PosX] != InfoValue::none){
		 return false;
	 }

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

 void Checkerboard::setCheckerboardInfo(int PosX, int PosY, InfoValue value){
	 int gainChess = 0;

	 //if gain chess greater than 0,mean it is legal
	 if ((gainChess = checkRight(PosX, PosY)) > 0){
		 for (int i = PosX + 1; i <= PosX + gainChess; i++)
		 {
			 checkerboardInfo[PosY][i] = value;
		 }
	 }

	 if ((gainChess = checkLeft(PosX, PosY)) > 0){
		 for (int i = PosX - 1; i >= PosX - gainChess; i--)
		 {
			 checkerboardInfo[PosY][i] = value;
		 }
	 }

	 if ((gainChess = checkUp(PosX, PosY)) > 0){
		 for (int i = PosY - 1; i >= PosY - gainChess; i--)
		 {
			 checkerboardInfo[i][PosX] = value;
		 }
	 }

	 if ((gainChess = checkDown(PosX, PosY)) > 0){
		 for (int i = PosY + 1; i <= PosY + gainChess; i++)
		 {
			 checkerboardInfo[i][PosX] = value;
		 }
	 }

	 if ((gainChess = checkRightUp(PosX, PosY)) > 0){
		 for (int i = PosX + 1, j = PosY - 1; i <= PosX + gainChess && j >= PosY - gainChess; i++,j--)
		 {
			 checkerboardInfo[j][i] = value;
		 }
	 }

	 if ((gainChess = checkRightDown(PosX, PosY)) > 0){
		 for (int i = PosX + 1, j = PosY + 1; i <= PosX + gainChess && j <= PosY + gainChess; i++, j++)
		 {
			 checkerboardInfo[j][i] = value;
		 }
	 }

	 if ((gainChess = checkLeftUp(PosX, PosY)) > 0){
		 for (int i = PosX - 1, j = PosY - 1; i >= PosX - gainChess && j >= PosY - gainChess; i--, j--)
		 {
			 checkerboardInfo[j][i] = value;
		 }
	 }

	 if ((gainChess = checkLeftDown(PosX, PosY)) > 0){
		 for (int i = PosX - 1, j = PosY + 1; i >= PosX - gainChess && j <= PosY + gainChess; i--, j++)
		 {
			 checkerboardInfo[j][i] = value;
		 }
	 }

	 checkerboardInfo[PosY][PosX] = value;
 };

 void Checkerboard::setChess(int PosX, int PosY){
	 if (checkLegal(PosX, PosY)){
		 if (currentChess == chess::blackChess){
			 // set value
			 setCheckerboardInfo(PosX, PosY, InfoValue::black);

			 //recode chess info
			 saveCurrentChessManual();

		 }
		 else if (currentChess == chess::whiteChess){
			 // set value
			 setCheckerboardInfo(PosX, PosY, InfoValue::white);

			 //recode chess info
			 saveCurrentChessManual();

		 }
		 else{
			 return;
		 }
	 }
	 else{
		 Log = "你不能下這裡";
	 }
 };

 void Checkerboard::saveCurrentChessManual(void){
	 blackCount = 0;
	 whiteCount = 0;

	 step++;
	 chessManualIndex++;
	 //rewrite step count
	 if (chessManualIndex <= step){
		 step = chessManualIndex;
	 }

	 for (int rowNum = 0; rowNum < sideLength; rowNum++)
	 {
		 for (int colNum = 0; colNum < sideLength; colNum++)
		 {
			chessManual[chessManualIndex][rowNum][colNum] = checkerboardInfo[rowNum][colNum];

			switch (checkerboardInfo[rowNum][colNum]){
				case InfoValue::black:
					blackCount ++;
					break;
				case InfoValue::white:
					whiteCount ++;
					break;
			}
		 }
	 }

	 if (currentChess == chess::whiteChess){
		 currentChess = chess::blackChess;
	 }
	 else if (currentChess == chess::blackChess){
		 currentChess = chess::whiteChess;
	 }

	 //if no pass,exchange chess
	 if (checkPass()){
		 if (currentChess == chess::whiteChess){
			 currentChess = chess::blackChess;
		 }
		 else if (currentChess == chess::blackChess){
			 currentChess = chess::whiteChess;
		 }
	 }

	 chessRecord[chessManualIndex] = currentChess;

 };

 void Checkerboard::undo(void){
	 if (chessManualIndex - 1 >= 0){
		 chessManualIndex -= 1;
	 }

	 //overwrite info
	 for (int rowNum = 0; rowNum < sideLength; rowNum++)
	 {
		 for (int colNum = 0; colNum < sideLength; colNum++)
		 {
			checkerboardInfo[rowNum][colNum] = chessManual[chessManualIndex][rowNum][colNum];
		 }
	 }

	 currentChess = chessRecord[chessManualIndex];

 };

 void Checkerboard::redo(void){
	 if (chessManualIndex + 1 <= step){
		 chessManualIndex += 1;
	 }


	 //overwrite info
	 for (int rowNum = 0; rowNum < sideLength; rowNum++)
	 {
		 for (int colNum = 0; colNum < sideLength; colNum++)
		 {
			 checkerboardInfo[rowNum][colNum] = chessManual[chessManualIndex][rowNum][colNum];
		 }
	 }
	 currentChess = chessRecord[chessManualIndex];
 };

 bool Checkerboard::checkPass(void){
	 //check no hint
	 for (int rowNum = 0; rowNum < sideLength; rowNum++)
	 {
		 for (int colNum = 0; colNum < sideLength; colNum++)
		 {
			 if (checkerboardInfo[rowNum][colNum] == InfoValue::none){
				 if (checkLegal(colNum, rowNum)){
					 return false;
				 }
			}
		 }
	 }
	 return true;
 };

string Checkerboard ::toString(void){
	if (checkFinished()){
		if (whiteCount > blackCount){
			logHandler("○ WIN !!!!!!!!!!!");
		}
		else if (whiteCount < blackCount){
			logHandler("● WIN !!!!!!!!!!!");
		}
		else{
			logHandler("平手");
		}
	}

	string result = "";

	result += "╔════════╗\n";
	for (int rowNum = 0; rowNum < sideLength; rowNum++)
	{
		result += "║";
		for (int colNum = 0; colNum < sideLength; colNum++)
		{
			if (colNum == currentPosition[0] && rowNum == currentPosition[1]){
				if (checkerboardInfo[rowNum][colNum] == InfoValue::black){
					result += "◆";
				}
				else if (checkerboardInfo[rowNum][colNum] == InfoValue::white){
					result +=  "◇";
				}
				else{
					if (checkLegal(colNum, rowNum)){
						result += "⊙";
					}
					else{
						result += "⊕";
					}
				}
			}else{
				switch (checkerboardInfo[rowNum][colNum]){
				case InfoValue::black:
					result += "●";
					break;
				case InfoValue::white:
					result += "○";
					break;
				case InfoValue::none:
					if (checkLegal(colNum, rowNum)){
						result += "．";
					}
					else
					{
						result += "—";
					}

					break;
				}
			}

		}
		result += "║\n";
	}
	result += "╚════════╝\n";
	result += "\n";
	result += "Current chess : ";
	if (currentChess == chess::blackChess){
		result += "●";
	}
	else if (currentChess == chess::whiteChess){
		result += "○";
	}
	result += "\n";
	result += "step : "+std::to_string(step) +"\n";
	result += "chessManualIndex : " + std::to_string(chessManualIndex) + "\n";
	result += "● : " + std::to_string(blackCount) + "\n";
	result += "○ : " + std::to_string(whiteCount) + "\n";
	
	result += showLog();
	result += "\n";
	return result;
};

void Checkerboard::clearLog(void){
	Log = "";
};

bool Checkerboard::checkFinished(void){
	if (step >= 60){
		return true;
	}else{
		return false;
	}
};

void Checkerboard::logHandler(std::string log){
	Log += log;
};
std::string Checkerboard::showLog(){
	if (Log != showedLog && Log != ""){
		showedLog = Log;
	}

	clearLog();

	if (showedLog != ""){
		return "Message : \n" + showedLog;
	}
	else {
		return  "";
	}
};

Reversi::~Reversi(void)
{
}


