////
//Name: Franz Alarcon
//Section: A
//Program Name: Program 5 Knight's Tour
//
//Description: This program uses recursion in order to solve 
//	the knight's tour problem. A knight chess piece, which
//	can only move in a specific pattern, is tested to see
//	if it can land on all spots of a board once. The 
//	movements of the knight are stored in a 2D int array,
//	who's values correspond to the move number. Calling
//	the function moveKnight() will start the solution using
//	a brute-force algorithm. If the board successfully 
//	completes, the function will return true. Otherwise, it
//	will return false. As parameters, the starting position
//	of the knight can be changed. The default position is 
//	the top left corner of the board. The length of the board
//	can be changed by modifying const int length in the 
//	boardInfo namespace. If the function returns true, 
//	the board will be printed to the console along with 
//	totalMoves and badMoves. If returned false, a message
//	will be written to the console saying the board cannot
//	be completed. 
//
//Function:
//bool moveKnight(int row = 0, int col = 0, int movNum = 1);
//	row - starting row position of knight
//	col - starting col position of knight
//	movNumber - current move number (should not be changed
//							when function is first called)
////

#include <iostream>
#include <iomanip>

namespace boardInfo {
	const int length = 8; //Change this value to change the board size
	int board[length][length] = { 0 };
	int totalSquares = length * length;
	unsigned long totalMoves = 0, badMoves = 0;
}

bool moveKnight(int row = 0, int col = 0, int movNum = 1);
void printBoard();

int main() {
	if (moveKnight()) {
		printBoard();
		std::cout << "Total Moves: " << boardInfo::totalMoves << std::endl;
		std::cout << "Bad Moves: " << boardInfo::badMoves << std::endl;
	}
	else {
		std::cout << "Board cannot be completed" << std::endl;
	}
}

bool moveKnight(int row, int col, int movNum) {
	bool complete = false;
	if (row < 0 || row >= boardInfo::length) return false;   //check if row value is valid
	if (col < 0 || col >= boardInfo::length) return false;   //check if col value is valid
	if (boardInfo::board[row][col] != 0) return false;       //check if spot is free

	boardInfo::board[row][col] = movNum;
	boardInfo::totalMoves++;

	if (movNum == boardInfo::totalSquares) { //board complete
		return true;
	}
	else { //choose next move
		if (moveKnight(row - 2, col + 1, movNum + 1)) return true;        //1
		else if (moveKnight(row - 1, col + 2, movNum + 1)) return true;   //2
		else if (moveKnight(row + 1, col + 2, movNum + 1)) return true;   //3
		else if (moveKnight(row + 2, col + 1, movNum + 1)) return true;   //4
		else if (moveKnight(row + 2, col - 1, movNum + 1)) return true;   //5
		else if (moveKnight(row + 1, col - 2, movNum + 1)) return true;   //6
		else if (moveKnight(row - 1, col - 2, movNum + 1)) return true;   //7
		else if (moveKnight(row - 2, col - 1, movNum + 1)) return true;   //8
	}

	boardInfo::board[row][col] = 0; //bad move condition
	boardInfo::badMoves++;
	return false;
}

void printBoard() {
	for (int i = 0; i < boardInfo::length; i++) {
		for (int j = 0; j < boardInfo::length; j++) {
			std::cout << std::setw(4) << boardInfo::board[i][j];
		}
		std::cout << "\n\n";
	}
}

//Various test outputs:

/*
//boardInfo::length = 5:

 1  20  17  12   3

16  11   2   7  18

21  24  19   4  13

10  15   6  23   8

25  22   9  14   5

Total Moves : 41
Bad Moves : 16

------------------------------------------

//boardInfo::length = 8:

 1  38  55  34   3  36  19  22

54  47   2  37  20  23   4  17

39  56  33  46  35  18  21  10

48  53  40  57  24  11  16   5

59  32  45  52  41  26   9  12

44  49  58  25  62  15   6  27

31  60  51  42  29   8  13  64

50  43  30  61  14  63  28   7

Total Moves : 3242065
Bad Moves : 3242001

------------------------------------------

//boardInfo::length = 4:

Board cannot be completed

------------------------------------------

//boardInfo::length = 5, row = 4, col = 4:

  23  14  19   8  21

  12   7  22   3  18

  15  24  13  20   9

   6  11   2  17   4

  25  16   5  10   1

Total Moves: 14009
Bad Moves: 13984

*/

//I tried starting at (4, 4) on an 8x8 board, but after 10 hours I gave up