#include <iostream>
using namespace std;

void displayBoard(char[][3], int);
int player1(char board[][3], int side);
int player2(char board[][3], int side);
bool overwriteCheck(int, int, char board[][3]);
bool gameOver = false;
int p = 0;
void gameOverCheck(char b[][3]);
int playerTurns(char board[][3], int side);
int playerTurnsAI(char board[][3], int side);
int compAI(char board[][3], int side);

int main(){
	int choice = 1;
	int quitchoice = 2;
	do{
		do{
			cout << "Tic Tac Toe: Please make your selection.\n";
			cout << "1. Play against a human player.\n";
			cout << "2. Play against the computer AI.\n";
			cout << "3. Quit.\n";
			if (choice < 1 || choice > 3)
				cout << "ERROR: Please enter 1, 2 or 3.\n";
			cout << ": ";
			cin >> choice;
			cin.ignore(100000, '\n');
		} while (choice < 1 || choice > 3);

		switch (choice){

		case 1: {
			const int TOP_LR = 3, SIDE_UD = 3;
			char array[TOP_LR][SIDE_UD] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', };

			int fakeVariable = playerTurns(array, SIDE_UD);
			displayBoard(array, SIDE_UD);

			if (p == 0)
				cout << "\n\nThe game has ended in a tie.\n";
			else
				cout << "\n\nPlayer " << p << " Won the game!\n\n";
			cout << "Press enter to return to the main menu...\n\n\n";
			cin.get();
			break;
		}

		case 2: {
			const int TOP_LR = 3, SIDE_UD = 3;
			char array[TOP_LR][SIDE_UD] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', };

			int fakeVariable = playerTurnsAI(array, SIDE_UD);
			displayBoard(array, SIDE_UD);

			if (p == 0)
				cout << "\n\nThe game has ended in a tie.\n";
			else
				cout << "\n\nPlayer " << p << " Won the game!\n\n";
			cout << "Press enter to return to the main menu...\n\n\n";
			cin.get();
			break;
		}
		case 3: {
	
			cout << "Are you sure you want to quit?\n";
			cout << "1. Yes\n";
			cout << "2. No\n";
			do{
				if (quitchoice < 1 || quitchoice > 2)
					cout << "ERROR: Please enter the integer 1 or 2.\n";
				cin >> quitchoice;
				cin.ignore(100000, '\n');
			} while (quitchoice < 1 || quitchoice > 2);
			switch (quitchoice){
				case 1:{
					cout << "bye!";
					break;
					}
				case 2 : {
					break;
					}
				}
			}
		}
	} while (quitchoice != 1 );
	return 0;
}

int playerTurns(char board[][3], int side){
	do{
		if (gameOver == false)
			player1(board, side);
		if (gameOver == false)
			player2(board, side);
	} while (gameOver == false);
	return 0;
}

int playerTurnsAI(char board[][3], int side){
	do{
		if (gameOver == false)
			compAI(board, side);
		if (gameOver == false)
			player2(board, side);
	} while (gameOver == false);
	return 0;
}

int player1(char board[][3], int side){
	int player = 1;
	char mark = 'O';
	//111111111111111111111111111111111111
	int a = 1, b = 1;
	bool overwrite = false;
	do{
		cout << endl << endl << "Player " << player << ", choose your square. (Your are " << mark << ")" << endl;
		displayBoard(board, side);
		cout << endl << endl << "Submit your move by typing the number for the row,\nfollowed by the column, i.e. \"1 3\" that would choose the top right spot." << endl;
		if (a < 1 || a > 3 || b < 1 || b > 3)
			cout << "ERROR: Enter either a 1,2 or 3 for each submittion,\n keep the numbers seperated by a space.\n\n";
		if (overwrite == true)
			cout << "ERROR: that spot has been taken!" << endl;
		cout << ": ";
		cin >> a >> b;
		cin.ignore(100000, '\n');
		a = a - 1;
		b = b - 1;

		overwrite = overwriteCheck(a, b, board);

	} while (overwrite == true);
	board[a][b] = mark;
	gameOverCheck(board);
	if (gameOver == true)
		return 1;
	return 0;
	//111111111111111111111111111111111111
}

int player2(char board[][3], int side){
	int player = 2;
	char mark = 'X';
	//222222222222222222222222222222222222222222
	int a = 1, b = 1;
	bool overwrite = false;
	do{
		cout << endl << endl << "Player " << player << ", choose your square. (Your are " << mark << ")" << endl;
		displayBoard(board, side);
		cout << endl << endl << "Submit your move by typing the number for the row,\nfollowed by the column, i.e. \"1 3\" that would choose the top right spot." << endl;
		if (a < 1 || a > 3 || b < 1 || b > 3)
			cout << "ERROR: Enter either a 1,2 or 3 for each submittion,\n keep the numbers seperated by a space.\n\n";
		if (overwrite == true)
			cout << "ERROR: that spot has been taken!" << endl;
		cout << ": ";
		cin >> a >> b;
		cin.ignore(100000, '\n');
		a = a - 1;
		b = b - 1;

		overwrite = overwriteCheck(a, b, board);

	} while (overwrite == true);
	board[a][b] = mark;
	gameOverCheck(board);
	if (gameOver == true)
		return 1;
	return 0;
	//222222222222222222222222222222222222222222
}

int compAI(char board[][3], int side){
	int player = 1, a = 1, b = 1;
	char mark = 'O';
	//3333333333333333333333333333333333333333333

	cout << "\n\nPlayer 1 is being played by the computer...\n\n";

	if (board[0][0] == '*' && board[0][1] == '*' && board[0][2] == '*' && board[1][0] == '*' && board[1][1] == '*' && board[1][2] == '*' && board[2][0] == '*' && board[2][1] == '*' && board[2][2] == '*') { a = 1; b = 1; } // add center if board empty
	else if (board[0][0] == '*' && board[0][1] == 'X' && board[0][2] == 'X') { a = 0; b = 0; } // win row 1
	else if (board[0][0] == 'X' && board[0][1] == '*' && board[0][2] == 'X') { a = 0; b = 1; } // win row 1
	else if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == '*') { a = 0; b = 2; } // win row 1
	else if (board[1][0] == '*' && board[1][1] == 'X' && board[1][2] == 'X') { a = 1; b = 0; } // win row 2
	else if (board[1][0] == 'X' && board[1][1] == '*' && board[1][2] == 'X') { a = 1; b = 1; } // win row 2
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == '*') { a = 1; b = 2; } // win row 2
	else if (board[2][0] == '*' && board[2][1] == 'X' && board[2][2] == 'X') { a = 2; b = 0; } // win row 3
	else if (board[2][0] == 'X' && board[2][1] == '*' && board[2][2] == 'X') { a = 2; b = 1; } // win row 3
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == '*') { a = 2; b = 2; } // win row 3
	else if (board[0][0] == '*' && board[0][0] == 'X' && board[0][0] == 'X') { a = 0; b = 0; } // win column 1
	else if (board[1][0] == 'X' && board[1][0] == '*' && board[1][0] == 'X') { a = 1; b = 0; } // win column 1
	else if (board[2][0] == 'X' && board[2][0] == 'X' && board[2][0] == '*') { a = 2; b = 0; } // win column 1
	else if (board[0][1] == '*' && board[0][1] == 'X' && board[0][1] == 'X') { a = 0; b = 1; } // win column 2
	else if (board[1][1] == 'X' && board[1][1] == '*' && board[1][1] == 'X') { a = 1; b = 1; } // win column 2
	else if (board[2][1] == 'X' && board[2][1] == 'X' && board[2][1] == '*') { a = 2; b = 1; } // win column 2
	else if (board[0][2] == '*' && board[0][2] == 'X' && board[0][2] == 'X') { a = 0; b = 2; } // win column 3
	else if (board[1][2] == 'X' && board[1][2] == '*' && board[1][2] == 'X') { a = 1; b = 2; } // win column 3
	else if (board[2][2] == 'X' && board[2][2] == 'X' && board[2][2] == '*') { a = 2; b = 2; } // win column 3
	else if (board[0][0] == '*' && board[1][1] == 'X' && board[2][2] == 'X') { a = 0; b = 0; } // win diagonal 1
	else if (board[0][0] == 'X' && board[1][1] == '*' && board[2][2] == 'X') { a = 1; b = 1; } // win diagonal 1
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == '*') { a = 2; b = 2; } // win diagonal 1
	else if (board[2][0] == '*' && board[1][1] == 'X' && board[0][2] == 'X') { a = 2; b = 0; } // win diagonal 2
	else if (board[2][0] == 'X' && board[1][1] == '*' && board[0][2] == 'X') { a = 2; b = 2; } // win diagonal 2
	else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == '*') { a = 0; b = 2; } // win diagonal 2
	else if (board[0][0] == '*' && board[0][1] == 'O' && board[0][2] == 'O') { a = 0; b = 0; } // block row 1
	else if (board[0][0] == 'O' && board[0][1] == '*' && board[0][2] == 'O') { a = 0; b = 1; } // block row 1
	else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == '*') { a = 0; b = 2; } // block row 1
	else if (board[1][0] == '*' && board[1][1] == 'O' && board[1][2] == 'O') { a = 1; b = 0; } // block row 2
	else if (board[1][0] == 'O' && board[1][1] == '*' && board[1][2] == 'O') { a = 1; b = 1; } // block row 2
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == '*') { a = 1; b = 2; } // block row 2
	else if (board[2][0] == '*' && board[2][1] == 'O' && board[2][2] == 'O') { a = 2; b = 0; } // block row 3
	else if (board[2][0] == 'O' && board[2][1] == '*' && board[2][2] == 'O') { a = 2; b = 1; } // block row 3
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == '*') { a = 2; b = 2; } // block row 3
	else if (board[0][0] == '*' && board[0][0] == 'O' && board[0][0] == 'O') { a = 0; b = 0; } // block column 1
	else if (board[1][0] == 'O' && board[1][0] == '*' && board[1][0] == 'O') { a = 1; b = 0; } // block column 1
	else if (board[2][0] == 'O' && board[2][0] == 'O' && board[2][0] == '*') { a = 2; b = 0; } // block column 1
	else if (board[0][1] == '*' && board[0][1] == 'O' && board[0][1] == 'O') { a = 0; b = 1; } // block column 2
	else if (board[1][1] == 'O' && board[1][1] == '*' && board[1][1] == 'O') { a = 1; b = 1; } // block column 2
	else if (board[2][1] == 'O' && board[2][1] == 'O' && board[2][1] == '*') { a = 2; b = 1; } // block column 2
	else if (board[0][2] == '*' && board[0][2] == 'O' && board[0][2] == 'O') { a = 0; b = 2; } // block column 3
	else if (board[1][2] == 'O' && board[1][2] == '*' && board[1][2] == 'O') { a = 1; b = 2; } // block column 3
	else if (board[2][2] == 'O' && board[2][2] == 'O' && board[2][2] == '*') { a = 2; b = 2; } // block column 3
	else if (board[0][0] == '*' && board[1][1] == 'O' && board[2][2] == 'O') { a = 0; b = 0; } // block diagonal 1
	else if (board[0][0] == 'O' && board[1][1] == '*' && board[2][2] == 'O') { a = 1; b = 1; } // block diagonal 1
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == '*') { a = 2; b = 2; } // block diagonal 1
	else if (board[2][0] == '*' && board[1][1] == 'O' && board[0][2] == 'O') { a = 2; b = 0; } // block diagonal 2
	else if (board[2][0] == 'O' && board[1][1] == '*' && board[0][2] == 'O') { a = 2; b = 2; } // block diagonal 2
	else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == '*') { a = 0; b = 2; } // block diagonal 2
	else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == '*') { a = 0; b = 2; } // block diagonal 2
	else if (board[1][1] == '*')                                         { a = 1; b = 1; } // take center if no win available or blocks needed
	else if (board[0][0] == 'O' && board[2][2] == 'O' && board[2][0] == '*') { a = 0; b = 2; } // block three corner attack
	else if (board[0][0] == 'O' && board[2][2] == 'O' && board[0][2] == '*') { a = 0; b = 2; } // block three corner attack
	else if (board[2][0] == 'O' && board[0][2] == 'O' && board[0][0] == '*') { a = 0; b = 2; } // block three corner attack
	else if (board[2][0] == 'O' && board[0][2] == 'O' && board[2][2] == '*') { a = 0; b = 2; } // block three corner attack
	else if (board[0][0] == '*')                                         { a = 0; b = 0; } // take if nothing else has come up yet
	else if (board[0][1] == '*')                                         { a = 0; b = 1; } // take if nothing else has come up yet
	else if (board[0][2] == '*')                                         { a = 0; b = 2; } // take if nothing else has come up yet
	else if (board[1][0] == '*')                                         { a = 1; b = 0; } // take if nothing else has come up yet
	else if (board[1][2] == '*')                                         { a = 1; b = 2; } // take if nothing else has come up yet
	else if (board[2][0] == '*')                                         { a = 2; b = 0; } // take if nothing else has come up yet
	else if (board[2][1] == '*')                                         { a = 2; b = 1; } // take if nothing else has come up yet
	else if (board[2][2] == '*')                                         { a = 2; b = 2; } // take if nothing else has come up yet

	board[a][b] = mark;
	gameOverCheck(board);
	if (gameOver == true)
		return 1;
	return 0;
	//3333333333333333333333333333333333333333333
}

void displayBoard(char board[][3], int side){
	cout << "The current board is displayed below..." << endl;
	char display;
	char totalz;
	int starting = 0;
	for (int i = 0; i < side; i++){
		cout << endl;
		if (starting == 0){
			cout << "  1 2 3" << endl;
			starting = 1;
		}
		cout << (i + 1) << " ";
		for (int ii = 0; ii < 3; ii++){
			totalz = board[i][ii];
			if (totalz == '*')
				cout << "* ";
			if (totalz == 'O')
				cout << "O ";
			if (totalz == 'X')
				cout << "X ";
		}
	}
}

bool overwriteCheck(int x, int y, char b[][3]){
	if (x < 0 || x > 2 || y < 0 || y > 2){
		return true;
	}
	char check = b[x][y];
	if (b[x][y] == '*'){
		return false;
	}
	else{
		return true;
	}
}

void gameOverCheck(char b[][3]){

	//Player 1 'O'
	char x = 'O';
	if (b[0][0] == x && b[0][1] == x && b[0][2] == x)
		gameOver = true, p = 1;
	else if (b[1][0] == x && b[1][1] == x && b[1][2] == x)
		gameOver = true, p = 1;
	else if (b[2][0] == x && b[2][1] == x && b[2][2] == x)
		gameOver = true, p = 1;
	else if (b[0][0] == x && b[1][0] == x && b[2][0] == x)
		gameOver = true, p = 1;
	else if (b[0][1] == x && b[1][1] == x && b[2][1] == x)
		gameOver = true, p = 1;
	else if (b[0][2] == x && b[1][2] == x && b[2][2] == x)
		gameOver = true, p = 1;
	else if (b[0][0] == x && b[1][1] == x && b[2][2] == x)
		gameOver = true, p = 1;
	else if (b[0][2] == x && b[1][1] == x && b[2][0] == x)
		gameOver = true, p = 1;

	//Player 2 'X'
	x = 'X';
	if (b[0][0] == x && b[0][1] == x && b[0][2] == x)
		gameOver = true, p = 2;
	else if (b[1][0] == x && b[1][1] == x && b[1][2] == x)
		gameOver = true, p = 2;
	else if (b[2][0] == x && b[2][1] == x && b[2][2] == x)
		gameOver = true, p = 2;
	else if (b[0][0] == x && b[1][0] == x && b[2][0] == x)
		gameOver = true, p = 2;
	else if (b[0][1] == x && b[1][1] == x && b[2][1] == x)
		gameOver = true, p = 2;
	else if (b[0][2] == x && b[1][2] == x && b[2][2] == x)
		gameOver = true, p = 2;
	else if (b[0][0] == x && b[1][1] == x && b[2][2] == x)
		gameOver = true, p = 2;
	else if (b[0][2] == x && b[1][1] == x && b[2][0] == x)
		gameOver = true, p = 2;

	int blanksFound = 0;
	if (gameOver == false) {
		for (int x = 0; x<3; x++) {
			for (int y = 0; y<3; y++) {
				if (b[x][y] == '*') {
					blanksFound++;
				}
			}
		}
	}
	if (blanksFound == 0)
		gameOver = true;

}
