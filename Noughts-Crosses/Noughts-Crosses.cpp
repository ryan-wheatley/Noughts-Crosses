// Noughts-Crosses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <string>
#include <cstdio>
#include "Header.h"




int main() {

	while (true) {

		//initialised game paramater at the start of each new game 
		counter = 0;
		resetMatrix();
		inGame = 1;
		char input;
		usedInput.clear();

		//draw the initial grid
		draw();

		//main game loop
		while (inGame) {
			input = validIn();
			draw(input);
			scoreCheck();     //this only needs to be called after the 4th go

		}

	}
}




//Updates the game grid to include player input
void draw(char in) {

	system("CLS");


	switch (in) {
	case '1':
		matrix[0][0] = ans[counter % 2];
		break;

	case '2':
		matrix[0][1] = ans[counter % 2];
		break;
	case '3':
		matrix[0][2] = ans[counter % 2];
		break;
	case '4':
		matrix[1][0] = ans[counter % 2];
		break;
	case '5':
		matrix[1][1] = ans[counter % 2];
		break;
	case '6':
		matrix[1][2] = ans[counter % 2];
		break;
	case '7':
		matrix[2][0] = ans[counter % 2];
		break;
	case '8':
		matrix[2][1] = ans[counter % 2];
		break;
	case '9':
		matrix[2][2] = ans[counter % 2];
		break;

	}

	counter++;

	draw();

}

//draw draws blank at the start of the game 
void draw() {
	std::cout << "Naughts and Crosses!" << std::endl;;
	std::cout << "\n";
	for (int j = 0; j < 3; j++) {

		for (int i = 0; i < 3; i++) {
			std::cout << " " << matrix[j][i];
		}
		std::cout << "\n";
	}

	std::cout << "\n";
	std::cout << "Player " << ans[counter % 2] << " make selection:" << std::endl;


}

//ScoreCheck checks if a player has won
void scoreCheck() {
	for (int i = 0; i < 3; i++) {
		//Game is won 
		if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] ||          //would need find a better way to do this 
			matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] ||
			matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] ||
			matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]
			) {

			//restart begins the game again after a playe has won
			std::cout << "Player " << ans[(counter + 1) % 2] << " has won!" << std::endl;
			//std::cin.ignore();
			system("pause");
			inGame = 0;
			system("CLS");
		}

	}

}





char validIn() {
	while (true) {
		char ui;

		//vs computer 
		//if turn odd, give it to the computer

		if (counter % 2) {
			int x = rand() % 9 + 1;
			ui = '0' + x;
		}
		else {
			std::cin >> ui;   //just leave this in if you want multi player mode
		}

		//single player
		//std::cin >> ui;   

		//Checks if input is in range of: 1-9
		if (validInput.find(ui) == std::string::npos) {
			std::cout << "That's not on the grid, please select again:" << std::endl;
		}

		//checks if input has already been used
		else if (usedInput.find(ui) != std::string::npos)
		{
			std::cout << "That's already been chosen, please select again:" << std::endl;
		}
		//valid input, add to usedInput and return the users input
		else {
			usedInput += ui;
			return ui;

		}
	}
}


//Resets matrix to initial values at start of new game 
void resetMatrix() {
	int n = 0;
	for (int j = 0; j < 3; j++) {

		for (int i = 0; i < 3; i++) {
			n++;
			char m = '0' + n;

			matrix[j][i] = m;
		}

	}
}
