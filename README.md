# 🎮 Hangman Game (C++)

A fully interactive **console-based Hangman game** built in modern C++, featuring multiple difficulty levels, scoring, and a polished game loop.

---

## 🚀 Features

* 🎯 **Multiple Difficulty Levels**
  * Very Easy, Easy, Medium, Hard
	
* 🔤 **Random Word Selection**
  * Words loaded dynamically from a file

* 🎮 **Interactive Gameplay**
  * Real-time letter guessing with validation

* 🔁 **Game Flow Control**
  * Play again, change difficulty, or exit
	
* 🧠 **Smart Letter Reveal System**
  * Avoids duplicate hints and improves challenge
	
* 🏆 **Score System**
  * Score based on difficulty and remaining lives
	
* 🛡️ **Robust Input Handling**
  * Prevents invalid inputs and duplicate guesses

---

## 🛠️ Technologies Used

* C++
* STL (`vector`, `string`, `unordered_map`, `set`)
* File I/O (`fstream`)
* Modular design with header/source separation

---

## 📂 Project Structure

```
Hangman/
│
├── main.cpp
├── Hangman.h / Hangman.cpp        # Game logic
├── Menus.h / Menus.cpp            # UI and display
├── WordAndInput.h / .cpp          # Input + word handling
├── Defines.h                      # Enums (GameState, Difficulty)
├── words.txt                      # Word database
```

---

## ▶️ How to Run

1. Clone the repository:

```
git clone https://github.com/KrissooT/Hangman-Game.git
```

2. Compile:

```
g++ *.cpp -o hangman
```

3. Run:

```
./hangman
```

---

## 🎮 Gameplay Preview

```
_ _ _ L E

A B C D E F G ...
Enter letter:
```

* Guess letters to reveal the hidden word
* Each wrong guess costs a life
* Win before you run out of lives!

---

## 🧠 What I Learned

* Structuring a multi-file C++ project
* Separating logic, input handling, and UI
* Working with file input and dynamic data
* Designing game loops and state management
* Implementing clean and safe user input validation

---

## 🔧 Future Improvements

* Replace `rand()` with `<random>` for better randomness
* Persistent leaderboard (save scores to file)
* Unit testing for core logic
* GUI version (SFML or similar)

---

## 💼 Why This Project Matters

This project demonstrates:

* Clean code organization
* Problem-solving and game logic design
* Use of core C++ features and STL
* Attention to user experience and edge cases

---

## 👤 Author

[KrissooT](https://github.com/KrissooT)

---

## ⭐ If you like this project

Give it a star ⭐ — it helps a lot!
