#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::endl;

#define MAX_SIZE 9
#define CELL_SIZE 2

bool readBoard(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int &r, int &c);
void game(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], const char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column);
int moveLeft(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column);
int moveRight(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column);
int moveUp(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column);
int moveDown(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column);
bool isProblemSolved(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], const char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column);
int intelligentMove(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], const char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE],int row, int column);
int shuffle(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], const char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column);
bool isMoveValid(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column, char move);
int solveProblem(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], const char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column);
void saveBoard(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column);
int randomMove(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column);

/*
 *draws board.
 */
void inline drawBoard(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			for (int k = 0; k < CELL_SIZE; ++k)
			{				
				cout << board[i][j][k];
			}
			cout << '\t';
		}
		cout << endl;
	}
}

/*
 *first creates the final solution.
 *then starts the game.
 */
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int row, column, n = 1;
	char board[MAX_SIZE][MAX_SIZE][CELL_SIZE];
	char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE];
	bool x = readBoard(board, row, column);
	if(x){
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				if(board[i][j][0] == '0' && board[i][j][1] == '0'){
					finalBoard[i][j][0] = '0';
					finalBoard[i][j][1] = '0';
				}
				else if(i == (row - 1) && j == (column - 1)){
					finalBoard[i][j][0] = 'b';
					finalBoard[i][j][1] = 'b';
				}
				else{
					if(n < 10){
						finalBoard[i][j][0] = '0';
						finalBoard[i][j][1] = n + 48;
						n++;
					}
					else{
						finalBoard[i][j][0] = (n / 10) + 48;
						finalBoard[i][j][1] = (n % 10) + 48;
						n++;
					}
				}
			}
		}
		game(board, finalBoard, row, column);
	}	
	return 0;
}

/*
 *created for the 'E' move
 */
void saveBoard(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	ofstream newFile;
	string fileName;
	cout << "Enter the file name: " << endl;
	cin >> fileName;
	newFile.open(fileName);
	for (auto i = 0; i < row; ++i)
	{
		for (auto j = 0; j < column; ++j)
		{
			for (auto k = 0; k < CELL_SIZE; ++k)
			{
				newFile << board[i][j][k];
			}
			if(j != column - 1){
				newFile << ' ';
			}
		}
		if(i != row - 1){
			newFile << '\n';
		}
	}
	newFile.close();
}

/*
 *reads board from file
 */
bool readBoard(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int &r, int &c)
{
	string fileName, line;
	ifstream fileStream;
	cout << "Please enter the file name: ";
	cin >> fileName;
	fileStream.open(fileName);
	if(!fileStream){
		cout << "Cannot open file." << endl;
		return false;
	}
	else{
		auto x = 0, i = 0, j = 0, k = 0;
		while(getline(fileStream, line)){
			while(line[x] != '\n' && line[x] != '\r' && line[x] != '\0'){
				if(line[x] == ' '){
					j++;
					k = 0;
				}
				else{
					board[i][j][k] = line[x];
					k++;
				}
				x++;
			}
			c = j + 1;
			i++;
			j = 0;
			x = 0;
			k = 0;
			r = i;
		}
		return true;			
	}
}

/* 
 *takes moves
 *checks if the problem is solved in every move(or input)
 */
void game(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], const char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	decltype(row) moveCount = 0;
	char move;
	cout << "Your initial board is" << endl;
	drawBoard(board, row, column);
	do{
		cout << "Your move: ";
		cin >> move;
		switch(move){
			case 'L':
				moveCount += moveLeft(board, row, column);
				drawBoard(board, row, column);
				break;
			case 'R':
				moveCount += moveRight(board, row, column);
				drawBoard(board, row, column);
				break;
			case 'U':
				moveCount += moveUp(board, row, column);
				drawBoard(board, row, column);
				break;				
			case 'D':
				moveCount += moveDown(board, row, column);
				drawBoard(board, row, column);
				break;
			case 'S':
				moveCount += shuffle(board, finalBoard, row, column);
				drawBoard(board, row, column);
				break;
			case 'I':
				moveCount += intelligentMove(board, finalBoard, row, column);
				drawBoard(board, row, column);
				break;
			case 'T':
				cout << "Move count is " << moveCount << ". Problem isn't solved." << endl;
				drawBoard(board, row, column);
				break;
			case 'E':
				saveBoard(board, row, column);
				drawBoard(board, row, column);
				break;
			case 'Y':
				if(readBoard(board, row, column)){
					drawBoard(board, row, column);
					moveCount = 0;
				}
				else{
					cout << "Cannot read file." << endl
						 << "Your board is still: " << endl;
						 drawBoard(board, row, column);
				}
				break;
			case 'V':
				solveProblem(board, finalBoard, row, column);
				drawBoard(board, row, column);
				break;
			case 'Q':
				break;
			default:
				cout << "Invalid input." << endl;
		}
	}while(move != 'Q' && !isProblemSolved(board, finalBoard, row, column));
	
	if(isProblemSolved(board, finalBoard, row, column)){
		cout << "Problem solved after " << moveCount << " moves." << endl;
	}
}

/*
 *takes the board to the final solution
 *generates row * column random integer values for moves to be random
 *0: R
 *1: L
 *2: U
 *3: D
 *checks if the generated move is invalid, then performs it
 */
int shuffle(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], const char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	decltype(row) n = 0;
	decltype(n) moveNum, moveStatus;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			for (int k = 0; k < CELL_SIZE; ++k)
			{
				board[i][j][k] = finalBoard[i][j][k];
			}
		}
	}
	//random moves
	do{
		do{
			moveNum = rand() % 4;
			switch(moveNum){
				case 0:
					if(isMoveValid(board, row, column, 'R')){
						moveStatus = moveRight(board, row, column);
					}
					break;
				case 1: 
					if(isMoveValid(board, row, column, 'L')){
						moveStatus = moveLeft(board, row, column);
					}
					break;
				case 2:
					if(isMoveValid(board, row, column, 'U')){
						moveStatus = moveUp(board, row, column);
					}
					break;
				case 3: 
					if(isMoveValid(board, row, column, 'D')){
						moveStatus = moveDown(board, row, column);
					}
					break;
				default:
					cout << "Something went wrong." << endl;
			}
		}while(moveStatus != 1);
		n++;
	}while(n < row * column);
	return n;
}

/*
 *checks if the moves are intelligent or not by comparing final board and current board.
 *if there is no intelligent move on the current move, generates random move and perfoms it.
 */
int intelligentMove(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], const char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE],int row, int column)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if(board[i][j][0] == 'b'){
				if(isMoveValid(board, row, column, 'L') && board[i][j - 1][0] == finalBoard[i][j][0]
						&& board[i][j - 1][01] == finalBoard[i][j][1]){
						return moveLeft(board, row, column);
				}
				else if(isMoveValid(board, row, column, 'R') && board[i][j + 1][0] == finalBoard[i][j][0]
						&& board[i][j + 1][1] == finalBoard[i][j][1]){
						return moveRight(board, row, column);
				}
				else if(isMoveValid(board, row, column, 'U') && board[i - 1][j][0] == finalBoard[i][j][0]
						&& board[i - 1][j][1] == finalBoard[i - 1][j][1]){
						return moveUp(board, row, column);
				}
				else if(isMoveValid(board, row, column, 'D') && board[i + 1][j][0] == finalBoard[i][j][0]
						&& board[i + 1][j][1] == finalBoard[i][j][1]){
						 return moveDown(board, row, column);
				}
				else{
					return randomMove(board, row, column);	
				}				
			}
		}
	}
	cout << "Something went wrong." << endl;
	return 0;
}

/*
 *performs random move
 */
int randomMove(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	int moveNum;
	do{
		moveNum = rand() % 4;
		switch(moveNum){
			case 0:
				if(isMoveValid(board, row, column, 'R')){
					return moveRight(board, row, column);
				}
				break;
			case 1: 
				if(isMoveValid(board, row, column, 'L')){
					return moveLeft(board, row, column);
				}
				break;
			case 2:
				if(isMoveValid(board, row, column, 'U')){
					return moveUp(board, row, column);
				}
				break;
			case 3: 
				if(isMoveValid(board, row, column, 'D')){
					return moveDown(board, row, column);								
				}
				break;
			default:
				cout << "Something went wrong." << endl;
				return 0;
		}
	}while(1);
}

/*
 *swaps 'bb' with the member of its left
 *returns 1 if the move is successful.
 */
int moveLeft(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	int temp;
	if(isMoveValid(board, row, column, 'L')){
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				if(board[i][j][0] == 'b'){
					temp = board[i][j - 1][0];
					board[i][j - 1][0] = board[i][j][0];
					board[i][j][0] = temp;
					temp = board[i][j - 1][1];
					board[i][j - 1][1] = board[i][j][1];
					board[i][j][1] = temp;
					return 1;
				}
			}
		}
	}
	else{
		cout << "Left move is invalid." << endl;
		return 0;
	}

	cout << "Something went wrong." << endl;
	return 0;
}
/*
 *swaps 'bb' with the member of its right
 *returns 1 if the move is successful. 
 */
int moveRight(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	int temp;
	if(isMoveValid(board, row, column, 'R')){
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				if(board[i][j][0] == 'b'){
					temp = board[i][j + 1][0];
					board[i][j + 1][0] = board[i][j][0];
					board[i][j][0] = temp;
					temp = board[i][j + 1][1];
					board[i][j + 1][1] = board[i][j][1];
					board[i][j][1] = temp;
					return 1;	
				}
			}
		}
	}
	else{
		cout << "Right move is invalid." << endl;
		return 0;
	}

	cout << "Something went wrong." << endl;
	return 0;
}

/*
 *swaps 'bb' with the above member.
 *returns 1 if the move is successful.
 */
int moveUp(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	int temp;
	if(isMoveValid(board, row, column, 'U')){
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				if(board[i][j][0] == 'b'){
					temp = board[i - 1][j][0];
					board[i - 1][j][0] = board[i][j][0];
					board[i][j][0] = temp;
					temp = board[i - 1][j][1];
					board[i - 1][j][1] = board[i][j][1];
					board[i][j][1] = temp;
					return 1;
				}
			}
		}
	}
	else{
		cout << "Up move is invalid." << endl;
		return 0;
	}

	cout << "Something went wrong." << endl;
	return 0;
}

/*
 *swaps 'bb' with the below member.
 *returns 1 if the move is successful.
 */
int moveDown(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	int temp;
	if(isMoveValid(board, row, column, 'D')){
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				if(board[i][j][0] == 'b'){
					temp = board[i + 1][j][0];
					board[i + 1][j][0] = board[i][j][0];
					board[i][j][0] = temp;
					temp = board[i + 1][j][1];
					board[i + 1][j][1] = board[i][j][1];
					board[i][j][1] = temp;
					return 1;						
				}
			}
		}
	}
	else{
		cout << "Down move is invalid." << endl;
		return 0;
	}

	cout << "Something went wrong." << endl;
	return 0;
}
/*
 *checks if the move is valid
 *for example, if bb is on the first column, left move is invalid
 */
bool isMoveValid(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column, char move)
{
	int i, j, k;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < column; ++j)
		{
			if(board[i][j][0] == 'b'){
				if(move == 'R'){
					if(j == (column - 1)){
						return false;
					}
					if(board[i][j + 1][0] == '0' && board[i][j + 1][1] == '0'){
						return false;
					}
				}

				if(move == 'L'){
					if(j == 0){
						return false;
					}
					if(board[i][j - 1][0] == '0' && board[i][j - 1][1] == '0'){
						return false;
					}
				}
				
				if(move == 'U'){
					if(i == 0){
						return false;
					}
					if(board[i - 1][j][0] == '0' && board[i - 1][j][1] == '0'){
						return false;
					}
				}
				
				if(move == 'D'){
					if(i == (row - 1)){
						return false;
					}
					if(board[i + 1][j][0] == '0' && board[i + 1][j][1] == '0'){
						return false;
					}
				}
			}
		}
	}
	return true;
}

/*
 *first, checks if the last cell is 'bb'
 *then, checks every cell except impossible positions if numbers are true.
 */
bool isProblemSolved(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], const char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	int n = 1;
	for (int i = 0; i < row; ++i)
	{	
		for (int j = 0; j < column; ++j)
		{
			for (int k = 0; k < CELL_SIZE; ++k)
			{
				if(board[i][j][k] != finalBoard[i][j][k]){
					return false;
				}
			}
		}
	}
	return true;
}

/*
 *performs 3 random, 1 intelligent move until the problem is solved.
 */
int solveProblem(char board[MAX_SIZE][MAX_SIZE][CELL_SIZE], const char finalBoard[MAX_SIZE][MAX_SIZE][CELL_SIZE], int row, int column)
{
	int moveCount = 0, i = 3;
	while(!isProblemSolved(board, finalBoard, row, column)){
		while(i > 0 && !isProblemSolved(board, finalBoard, row, column)){
			moveCount += randomMove(board, row, column);
			drawBoard(board, row, column);
			cout << endl;
			i--;
		}
		i = 3;
		moveCount += intelligentMove(board, finalBoard, row, column);
		drawBoard(board, row, column);
	 	cout << endl;
	}
	return moveCount;
}