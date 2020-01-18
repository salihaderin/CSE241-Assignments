#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX_SIZE 9

void game();
void fillRandom(int board[MAX_SIZE][MAX_SIZE], int size);
bool isAllFalse(bool *arr, int size);
void drawBoard(int board[MAX_SIZE][MAX_SIZE], int size);
int moveLeft(int board[MAX_SIZE][MAX_SIZE], int size);
int moveRight(int board[MAX_SIZE][MAX_SIZE], int size);
int moveUp(int board[MAX_SIZE][MAX_SIZE], int size);
int moveDown(int board[MAX_SIZE][MAX_SIZE], int size);
bool isProblemSolved(int board[MAX_SIZE][MAX_SIZE], int size);
int intelligentMove(int board[MAX_SIZE][MAX_SIZE], int size);
void shuffle(int board[MAX_SIZE][MAX_SIZE], int size);
bool isMoveValid(int board[MAX_SIZE][MAX_SIZE], int size, char move);


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	game();
	return 0;
}

/*
 *takes problem size
 *creates board
 *takes moves
 *checks if the problem is solved in every move
 */
void game()
{
	int size, moveCount = 0;
	char move;
	cout << "Please enter the problem size" << endl;
	cin >> size;
	int board[MAX_SIZE][MAX_SIZE];
	fillRandom(board, size);
	cout << "Your initial random board is" << endl;
	drawBoard(board, size);
	do{
		cout << "Your move: ";
		cin >> move;
		switch(move){
			case 'R':
				moveCount += moveRight(board, size);
				drawBoard(board, size);
				break;
			case 'L':
				moveCount += moveLeft(board, size);
				drawBoard(board, size);				
				break;
			case 'U':
				moveCount += moveUp(board, size);
				drawBoard(board, size);			
				break;
			case 'D':
				moveCount += moveDown(board, size);
				drawBoard(board, size);
				break;
			case 'S':
				shuffle(board, size);
				drawBoard(board, size);
				break;
			case 'I':
				intelligentMove(board, size);
				drawBoard(board, size);
				break;
			case 'Q':
				return;
			default:
				cout << "Invalid move." << endl;
				break;
		}
	}while(move != 'Q' && !isProblemSolved(board, size));
	if(isProblemSolved(board, size)){
		cout << "Problem solved!" << endl << "Total number of moves " << moveCount << endl;
	}
}

/*
 *i created an array called unique 
 *to check every cell in the board has distinct numbers.
 *false means number is used.
 */
void fillRandom(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int num;
	bool unique[size*size];
	for (int i = 0; i < size*size; ++i)
	{
		unique[i] = true;
	}
	int k = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			do{
				num = rand() % (size*size);
			}while(unique[num] == false && !isAllFalse(unique, size*size));
			board[i][j] = num;
			unique[num] = false;
			k++;
		}
	}
}

/*
 *draws board by replacing 0 with space character.
 */
void drawBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(board[i][j] == 0){
				cout << ' ' << '\t';
			}
			else{
				cout << board[i][j] << '\t';
			}
		}
		cout << endl;
	}
}

/*
 *returns true if all is false
 */
bool isAllFalse(bool *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if(arr[i]){
			return false;
		}
	}
	return true;
}

/*
 *swaps ' '(0) with the member of its left.
 *returns 1 if move is successful.
 */
int moveLeft(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int temp;
	if(isMoveValid(board, size, 'L')){
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if(board[i][j] == 0){
					temp = board[i][j-1];
					board[i][j-1] = board[i][j];
					board[i][j] = temp;
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
 *swaps ' '(0) with the member of its right.
 *returns 1 if move is successful.
 */
int moveRight(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int temp;
	if(isMoveValid(board, size, 'R')){
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if(board[i][j] == 0){
					temp = board[i][j+1];
					board[i][j+1] = board[i][j];
					board[i][j] = temp;
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
 *swaps ' '(0) with the above member.
 *returns 1 if move is successful.
 */
int moveUp(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int temp;
	if(isMoveValid(board, size, 'U')){
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if(board[i][j] == 0){
					temp = board[i-1][j];
					board[i-1][j] = board[i][j];
					board[i][j] = temp;
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
 *swaps ' '(0) with the below member.
 */
int moveDown(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int temp;
	if(isMoveValid(board, size, 'D')){
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if(board[i][j] == 0){
					temp = board[i+1][j];
					board[i+1][j] = board[i][j];
					board[i][j] = temp;
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
 *checks if the current board is solved.
 */
bool isProblemSolved(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int n = 1;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			//board[size-1][size-1] should be 0(' ')
			if(board[i][j] != board[size-1][size-1] && board[i][j] != n){
				return false;
			}
			if(board[size-1][size-1] != 0){
				return false;
			}
			n++;
		}
	}
	return true;
}

/*
 *takes the board to the final solution
 *generates size * size random integer values for moves to be random
 *0: R
 *1: L
 *2: U
 *3: D
 *checks if the generated move is invalid, then performs it
 */
void shuffle(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int n = 1;
	int moveNum, moveStatus;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(n ==  size * size){
				board[i][j] = 0;
			}
			else{
				board[i][j] = n;
				n++;
			}
		}
	}
	//random moves
	do{
		do{
			moveNum = rand() % 4;
			switch(moveNum){
				case 0:
					if(isMoveValid(board, size, 'R')){
						moveStatus = moveRight(board, size);				
					}
					break;
				case 1:
					if(isMoveValid(board, size, 'L')){
						moveStatus = moveLeft(board, size);
					}
					break;
				case 2: 
					if(isMoveValid(board, size, 'U')){
						moveStatus = moveUp(board, size);
					}
					break;
				case 3: 
					if(isMoveValid(board, size, 'D')){
						moveStatus = moveDown(board, size);
					}
					break;
				default:
					cout << "Something went wrong." << endl;
			}
		}while(moveStatus != 1);
		n--;
	}while(n > 0);
}

/*
 *checks is the move is valid
 */
bool isMoveValid(int board[MAX_SIZE][MAX_SIZE], int size, char move)
{
	if(move == 'R'){
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if(board[i][j] == 0){
					if(j == size - 1){
						return false;
					}				
				}
			}
		}
	}

	if(move == 'L'){
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if(board[i][j] == 0){
					if(j == 0){
						return false;
					}				
				}
			}
		}
	}	

	if(move == 'U'){
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if(board[i][j] == 0){
					if(i == 0){
						return false;
					}				
				}
			}
		}
	}

	if(move == 'D'){
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if(board[i][j] == 0){
					if(i == size - 1){
						return false;
					}				
				}
			}
		}
	}
	return true;
}

/*
 *first, generates final board to compare with current board.
 *then, checks if the moves are intelligent or not by comparing final board and current board.
 *if there is no intelligent move on the current move, generates random move and perfoms it.
 */
int intelligentMove(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int n = 1, moveNum;
	int finalBoard[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(n ==  size * size){
				finalBoard[i][j] = 0;
			}
			else{
				finalBoard[i][j] = n;
				n++;
			}
		}
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(board[i][j] == 0){
				if(isMoveValid(board, size, 'L')){
					if(board[i][j-1] == finalBoard[i][j]){
						return moveLeft(board, size);
					}
				}
				else if(isMoveValid(board, size, 'R')){
					if(board[i][j+1] == finalBoard[i][j]){
						return moveRight(board, size);
					}
				}
				else if(isMoveValid(board, size, 'U')){
					if(board[i-1][j] == finalBoard[i][j]){
						return moveUp(board, size);
					}
				}
				else if(isMoveValid(board, size, 'D')){
					if(board[i+1][j] == finalBoard[i][j]){
						return moveDown(board, size);
					}
				}
				else{
					break;
				}
				do{
						moveNum = rand() % 4;
						switch(moveNum){
							case 0:
								if(isMoveValid(board, size, 'R')){
									return moveRight(board, size);				
								}
								break;
							case 1:
								if(isMoveValid(board, size, 'L')){
									return moveLeft(board, size);
								}
								break;
							case 2: 
								if(isMoveValid(board, size, 'U')){
									return moveUp(board, size);
								}
								break;
							case 3: 
								if(isMoveValid(board, size, 'D')){
									return moveDown(board, size);
								}
								break;
							default:
								cout << "Something went wrong.1" << endl;
								return 0;
						}
					}while(1);				
			}
		}
	}
	cout << "Something went wrong." << endl;
	return 0;
}