#include "Hangman.h"
#include "Menus.h"

#include <algorithm>
#include <iostream>

Hangman::Hangman(const std::string& word, int firstIndex, int secondIndex)
:word(word), lives(6), firstIndex(firstIndex), secondIndex(secondIndex), state(GameState::RUNNING)
{
    guessedWord = word;
    guessedLetters.push_back(word[firstIndex]), guessedLetters.push_back(word[secondIndex]);
    for (size_t i = 0; i < guessedWord.size(); i++) {
        if (i == firstIndex || i == secondIndex) {
            continue;
        }
        guessedWord[i] = '_';
    }
}

std::string Hangman::getGuessedWord()const {
    return this->guessedWord;
}

int Hangman::getLives()const {
    return this->lives;
}

std::vector<char> Hangman::getGuessedLetters()const {
    return this->guessedLetters;
}

void Hangman::displayWord() const {
    clearScreen();
    HangmanDrawing(this->lives);
    for (const char& c : guessedWord) {
        std::cout << c << ' ';
    }
    std::cout << " Letters: " << word.length() << "\n\n";
}

void Hangman::guessLetter(char letter, std::vector<char>& lettersContainer) {
    while (std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {

        clearScreen();
        HangmanDrawing(this->lives);
        for (const char& c : guessedWord) {
            std::cout << c << ' ';
        }
        std::cout << " Letters: " << word.length() << "\n\n";
        Letters(lettersContainer);
        std::cout << "\nAlready Guessed, try one of the available letters!" << '\n';
        std::cout << "\nEnter letter: ";
        letter = gameInput(lettersContainer, *this);
        for (char& c : lettersContainer) {
            if (c == letter) {
                c = ' ';
                break;
            }
        }
    }

    guessedLetters.push_back(letter);

    bool found = false;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            guessedWord[i] = letter;
            found = true;
        }
    }

    if (!found) {
        lives--;
    }

    if (guessedWord == word) state = GameState::WON;
    else if(lives == 0) state = GameState::LOST;
}

GameState Hangman::getState()const {
	return this->state;
}