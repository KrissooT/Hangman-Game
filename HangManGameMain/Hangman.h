#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

#include "Defines.h"
#include "WordAndInput.h"

class Hangman {

private:
	std::string word;
	std::string guessedWord;
	std::vector<char> guessedLetters;
	int lives;
	int firstIndex, secondIndex;
	GameState state;

public:
	Hangman(const std::string& word, int firstIndex, int secondIndex);

	std::string getGuessedWord()const;
	int getLives()const;
	std::vector<char> getGuessedLetters()const;
	void displayWord() const;
	void guessLetter(char letter, std::vector<char>& lettersContainer);

	GameState getState()const;
};

#endif // !HANGMAN_H
