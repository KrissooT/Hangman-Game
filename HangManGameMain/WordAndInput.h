#ifndef WORD_AND_INPUT_H
#define WORD_AND_INPUT_H

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Defines.h"

class Hangman;

std::string getRandomWord(const std::string& fileName, Difficulty difficulty);
int menuInput();
char gameInput(std::vector<char>& lettersContainer, Hangman& hangman);
void playAgain(int& userInput, Difficulty& difficulty, bool& playing);
int playAgainInput();
int randomLetters(std::string& word, std::vector<char>& lettersContainer, int& secondIndex);
int endGameScore(Difficulty& difficulty, Hangman& hangman, int& score);
#endif // !WORD_AND_INPUT_H
