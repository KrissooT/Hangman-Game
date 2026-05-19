#ifndef MENUS_H
#define MENUS_H

#include "Hangman.h"

#include <iostream>
#include <vector>

void clearScreen();

void MainMenu();

void Letters(std::vector<char>& lettersContainer);

void HangmanDrawing(int lives);

void Victory();

void Defeat(int lives);

void PlayAgainMenu();

#endif // MENUS_H