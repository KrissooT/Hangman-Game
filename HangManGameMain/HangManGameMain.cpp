#include "Menus.h"
#include "WordAndInput.h"
#include "Hangman.h"

int main()
{
	MainMenu();

	int userInput = menuInput();

	Difficulty difficulty = Difficulty(userInput);

	int score = 0;
	bool playing = true;
	std::srand(std::time(0));

	while (playing) {

		std::vector<char> lettersContainer;

		for (char c = 'A'; c <= 'Z'; c++) {
			lettersContainer.push_back(c);
		}


		std::string word = getRandomWord("words.txt", difficulty);
		int secondIndex;
		int firstIndex = randomLetters(word, lettersContainer, secondIndex);
		Hangman hangman{ word, firstIndex, secondIndex };

		while (hangman.getState() == GameState::RUNNING) {

			hangman.displayWord();
			Letters(lettersContainer);

			std::cout << "\nEnter letter: ";
			char guess = gameInput(lettersContainer, hangman);

			guess = toupper(guess);

			for (char& c : lettersContainer) {
				if (c == guess) {
					c = ' ';
					break;
				}
			}

			hangman.guessLetter(guess, lettersContainer);
		}

		if (hangman.getState() == GameState::WON) {
			Victory();
			score = endGameScore(difficulty, hangman, score);
		}
		else {
			Defeat(hangman.getLives());
			score = endGameScore(difficulty, hangman, score);
		}

		std::cout << "The word was: " << word << "!\n";
		std::cout << "Current Score: " << score << "!\n";

		playAgain(userInput, difficulty, playing);
	}
}
