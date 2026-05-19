#include "WordAndInput.h"
#include "Menus.h"
#include <algorithm>
#include <cctype>
#include <unordered_map>

int menuInput() {
	std::string fill;
	int result = 1;

	while (true) {
		std::cout << "Choice: ";
		std::cin >> fill;
		if (fill.size() == 1 && isdigit(fill[0])) {
			result = std::stoi(fill);
			if (result > 0 && result < 5) {
				return result;
			}
			else if (result == 0) {
				std::cout << "\nThank you for playing :)\n";
				exit(0);
			}
		}

		std::cin.clear();
		clearScreen();
		MainMenu();
		std::cout << "Error, wrong input! Please choose a difficulty from 1 - 4!\n";
	}
}

char gameInput(std::vector<char>& lettersContainer, Hangman& hangman) {

	std::string fill;
	char letter = ' ';

	while (std::cin >> fill) {

		if (fill.size() == 1 && isalpha(fill[0])) {
			letter = fill[0];
			letter = toupper(letter);
			return letter;
		}
		std::cin.clear();
		clearScreen();
		HangmanDrawing(hangman.getLives());
		hangman.displayWord();
		Letters(lettersContainer);
		std::cout << "\nError, wrong input! Please choose one of the avaible letters!\n";
		std::cout << "\nEnter letter: ";
	}
}

void playAgain(int& userInput, Difficulty& difficulty, bool& playing) {

	PlayAgainMenu();

	int choice = playAgainInput();

	switch (choice) {
	case 1:
		break;
	case 2:
		clearScreen();
		MainMenu();
		userInput = menuInput();
		difficulty = Difficulty(userInput);
		break;
	case 0:
		playing = false;
		std::cout << "\nThank you for playing :)\n";
		break;
	}
}

int playAgainInput() {

	std::string fill;
	int result = 0;

	while (true) {
		std::cin >> fill;
		if (fill.size() == 1 && isdigit(fill[0])) {
			result = std::stoi(fill);
			if (result == 0 || result < 3) {
				return result;
			}
		}
		std::cin.clear();
		clearScreen();
		std::cout << "Error, wrong input! Please choose 1 or 2!\n";
		PlayAgainMenu();
	}
}

std::string getRandomWord(const std::string & fileName, Difficulty difficulty) {

	std::ifstream file(fileName);
	std::vector<std::string> words;

	std::string line;
	std::string prefix;

	switch (difficulty) {
	case Difficulty::VERYEASY: prefix = "veryeasy:";
		break;
	case Difficulty::EASY: prefix = "easy:";
		break;
	case Difficulty::MEDIUM: prefix = "medium:";
		break;
	case Difficulty::HARD: prefix = "hard:";
		break;
	}
	while (std::getline(file, line)) {
		if (line.find(prefix) == 0) {
			words.push_back(line.substr(prefix.length()));
		}
	}

	if (words.empty()) {
		return "Error";
	}

	int index = std::rand() % words.size();

	
	transform(words[index].begin(), words[index].end(), words[index].begin(), ::toupper);

	return words[index];
}

int randomLetters(std::string& word, std::vector<char>& lettersContainer, int& secondIndex){

	std::vector<int> validIndexes;
	std::set<char> invalidLetters;
	char firstLetter, secondLetter;
	int firstIndex = 0;
	bool isSame = false;

	if (word.size() == 3) {
		for (size_t i = 0; i < word.size(); i++) {
			for (size_t k = i + 1; k < word.size(); k++) {
				if (word[i] == word[k]) {
					isSame = true;
					firstIndex = i;
					secondIndex = k;
					firstLetter = word[firstIndex];
					secondLetter = word[secondIndex];
					break;
				}
			}
			if (isSame)break;
		}
	}

	if (!isSame || word.size() > 3) {

		std::unordered_map<char, int> letters;

		for (const char& c : word) {
			letters[c]++;
		}

		for (const std::pair<char, int>& pair : letters) {
			if (pair.second > 1) {
				invalidLetters.insert(pair.first);
			}
		}

		for (size_t i = 0; i < word.size(); i++) {
			if (invalidLetters.find(word[i]) == invalidLetters.end()) {
				validIndexes.push_back(i);
			}
		}

		firstIndex = std::rand() % validIndexes.size();
		secondIndex = std::rand() % validIndexes.size();
		if (firstIndex == secondIndex) {
			while (firstIndex == secondIndex) {
				secondIndex = std::rand() % validIndexes.size();
			}
		}

		firstIndex = validIndexes[firstIndex];
		secondIndex = validIndexes[secondIndex];

		firstLetter = word[firstIndex];
		secondLetter = word[secondIndex];
	}

	for (char& c : lettersContainer) {
		if(c == firstLetter || c == secondLetter) {
			c = ' ';
		}
	}

	return firstIndex;
}

int endGameScore(Difficulty& difficulty, Hangman& hangman, int& score) {

	if (hangman.getState() == GameState::WON) {
		switch (difficulty) {
		case Difficulty::VERYEASY:
			score += 10 + hangman.getLives() * 1;
			break;
		case Difficulty::EASY:
			score += 30 + hangman.getLives() * 3;
			break;
		case Difficulty::MEDIUM:
			score += 60 + hangman.getLives() * 6;
			break;
		case Difficulty::HARD:
			score += 100 + hangman.getLives() * 10;
			break;
		}
	}
	else {
		switch (difficulty) {
		case Difficulty::VERYEASY:
			score -= 5;
			break;
		case Difficulty::EASY:
			score -= 15;
			break;
		case Difficulty::MEDIUM:
			score -= 30;
			break;
		case Difficulty::HARD:
			score -= 50;
			break;
		}

		if (score < 0) {
			score = 0;
		}
	}

	return score;

}