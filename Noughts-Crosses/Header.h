#pragma once

//to draw and update the matrix
void draw();
void draw(char in);

void scoreCheck();

//Peramaters
char matrix[3][3] = { '1','2','3','4','5','6','7','8','9' };
char ans[2] = { 'o', 'x' };
int counter = 0;
bool inGame = 1;
void resetMatrix();

//to check if the inputs are valid 
char validIn();
std::string validInput = "123456789";
std::string usedInput;
