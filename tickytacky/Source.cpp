#include <iostream>
#include <string>
#include "clearScreen.h"

using namespace std;

string board[9] = { " "," "," "," "," "," " ," "," "," " };
int player = 1;
int position = 0;
int turn = 0;

void welcome() {
	cout << "\t\t==============================================" << endl;
	cout << "\t\t\tWelcome to Tick Tack Toe!" << endl;
	cout << "\t\t==============================================" << endl;
	std::cout << "\t\t\t     |     |      \n";
	std::cout << "\t\t\t  1  |  2  |  3   \n";
	std::cout << "\t\t\t_____|_____|_____ \n";
	std::cout << "\t\t\t     |     |      \n";
	std::cout << "\t\t\t  4  |  5  |  6   \n";
	std::cout << "\t\t\t_____|_____|_____ \n";
	std::cout << "\t\t\t     |     |      \n";
	std::cout << "\t\t\t  7  |  8  |  9   \n";
	std::cout << "\t\t\t     |     |      \n\n";
	cout << "\t\t-------This is a game where two players-------" << endl;
	cout << "\t\t-----Compete againts each other to place------" << endl;
	cout << "\t\t--thier marker on a board with nine squares,--" << endl;
	cout << "\t\tand try to get three in a row in a straight or" << endl;
	cout << "\t\t\t\tdiagonal line." << endl;
	cout << "\n\t\t--Press enter to start--" << endl;

	cin.ignore();
	
}

bool isWinner() {
	bool result = false;

	//horizontal Line Check
	if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ")result = true;
	else if ((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ")result = true;
	else if ((board[6] == board[7]) && (board[8] == board[6]) && board[6] != " ")result = true;

	//Vertical Line Check
	else if ((board[0] == board[3]) && (board[6] == board[0]) && board[0] != " ")result = true;
	else if ((board[1] == board[4]) && (board[7] == board[1]) && board[1] != " ")result = true;
	else if ((board[2] == board[5]) && (board[8] == board[2]) && board[2] != " ")result = true;

	//Diagonal Line Check
	else if ((board[0] == board[4]) && (board[8] == board[0]) && board[0] != " ")result = true;
	else if ((board[2] == board[4]) && (board[6] == board[2]) && board[2] != " ")result = true;

	return result;
}

bool isFilled() {
	bool result = true;

	for (int i = 0; i < 9; i++) {
		if (board[i] == " ")result = false;
	}

	return result;
}

void getInput() {
	cout << "\tPlayer " << player << " please enter a number between 1 - 9: ";

	while (!(cin >> position)) {
		cout << "\tPlease enter a number between 1 and 9! ";
		cin.clear();
		cin.ignore();
	}

	while (board[position - 1] != " ") {
		cout << "\tOpps it looks like there is already something in that position!" << endl;
		cout << "\tPlease enter a number between 1 - 9: ";
		cin >> position;
		cout << "\n";
	}
	if (turn == 0) {
		clearScreen();
	}
	else {
		turn += 1;
	}
}

void updateBoard() {
	if (player == 1) {
		board[position - 1] = "X";
	}
	else {
		board[position - 1] = "O";
	}
}

void changePlayer() {
	if (player == 1) {
		player += 1;
	}
	else {
		player = 1;
	}
}

void draw() {
	clearScreen();

	cout << "\n\n\n";
	cout << "\t\t     |     |      \n";
	cout << "\t\t  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
	cout << "\t\t_____|_____|_____ \n";
	cout << "\t\t     |     |      \n";
	cout << "\t\t  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
	cout << "\t\t_____|_____|_____ \n";
	cout << "\t\t     |     |      \n";
	cout << "\t\t  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
	cout << "\t\t     |     |      \n";
	cout << "\t\n";
}

void takeTurn() {

	while (!isWinner() && !isFilled()) {

		getInput();
		updateBoard();
		draw();
		if (!isWinner() && !isFilled()) {
			changePlayer();
		}
	}

}

bool end() {
	bool winner = true;
	if (isFilled()) {
		cout << "\t\tWow it was a tie!\n";
		winner = false;
	}
	else if (isWinner()) {
		cout << "\t\tPlayer " << player << " WON!!!" << endl;
		winner = false;
	}

	return winner;
}