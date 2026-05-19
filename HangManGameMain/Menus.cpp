#include "Menus.h"

//Clears Screen

void clearScreen() {
	std::cout << "\033[2J\033[1;1H";
}

//Printing Main menu

void MainMenu() {

	std::cout << R"(
  _   _                                           
 | | | | __ _ _ __   __ _ _ __ ___   __ _ _ __  
 | |_| |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
 |  _  | (_| | | | | (_| | | | | | | (_| | | | |
 |_| |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
                     |___/                     
)" << '\n';

	std::cout
		<< "                  ______\n"
		<< "                 |/     |\n"
		<< "                 |      O\n"
		<< "                 |     /|\\\n"
		<< "                 |     / \\\n"
		<< "                 |\n"
		<< "                /|\\\n\n";

	std::cout << "Please choose your difficulty:\n"
		<< "1. Very Easy\n"
		<< "2. Easy\n"
		<< "3. Medium\n"
		<< "4. Hard\n"
		<< "0. Quit Game\n\n";
}

//Letters from A - Z

void Letters(std::vector<char>& lettersContainer) {
	bool isFirst = true;
	static int letter;
	letter = 0;
	for (int rows = 0; rows < 3; rows++) {
		int lettersToPrint = 11;
		if (rows == 1) {
			lettersToPrint = 19;
		}
		else if (rows == 2) {
			lettersToPrint = 26;
		}
		else {
			lettersToPrint--;
		}
		for (letter; letter < lettersToPrint; letter++) {
			if (isFirst) {
				std::cout << lettersContainer[letter] << "  ";
				isFirst = false;
			}
			else {
				if (rows == 2) {
					std::cout << "  " << lettersContainer[letter] << "  ";
				}
				else {
					std::cout << ' ' << lettersContainer[letter] << "  ";
				}
			}
		}
		std::cout << '\n';
	}
}

//Drawing

void HangmanDrawing(int lives) {
	std::cout << "  ______\n";
	std::cout << " |/     |\n";

	if (lives <= 5)
		std::cout << " |      O\n";
	else
		std::cout << " |\n";

	if (lives == 4)
		std::cout << " |      |\n";
	else if (lives == 3)
		std::cout << " |     /|\n";
	else if (lives <= 2)
		std::cout << " |     /|\\\n";
	else
		std::cout << " |\n";

	if (lives == 1)
		std::cout << " |     /\n";
	else if (lives <= 0)
		std::cout << " |     / \\\n";
	else
		std::cout << " |\n";

	std::cout << " |\n";
	std::cout << "/|\\\n\n";
}

//Victory

void Victory() {
	clearScreen();

	std::cout << R"(

  ____   ___  _   _  ____ ____   _  _____ _   _ _        _  _____ ___ ___  _   _ ____  
 / ___| / _ \| \ | |/ ___|  _ \ / \|_   _| | | | |      / \|_   _|_ _/ _ \| \ | / ___| 
| |    | | | |  \| | |  _| |_) / _ \ | | | | | | |     / _ \ | |  | | | | |  \| \___ \ 
| |___ | |_| | |\  | |_| |  _ < ___ \| | | |_| | |___ / ___ \| |  | | |_| | |\  |___) |
 \____| \___/|_| \_|\____|_| \_/_/   \_\_|  \___/|___/_/   \_\_| |___\___/|_| \_|____/ 

)" << '\n';


	std::cout << "You WON!\n";
}

//Defeat

void Defeat(int lives) {

	clearScreen();
	HangmanDrawing(lives);
	std::cout << "You LOST!\n";
}

//Play Again Menu

void PlayAgainMenu() {

	std::cout << "\nWhat's next?: \n";
	std::cout << "1. Play Again (Same Difficulty)\n";
	std::cout << "2. Change Difficulty\n";
	std::cout << "0. Quit Game\n";
	std::cout << "\nChoice: ";

}