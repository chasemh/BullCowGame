#include <iostream>
#include <string>

// # Designates a preprocessor directive
// Use <> for including standard libraries
// Use "" for your including your own header files

using namespace std;

// Method Signatures/Prototypes
void PrintIntro();
void PlayGame();
string GetGuess();

// Entry point for application
int main() {

	PrintIntro();
	PlayGame();
	return 0;
}

// Introduce the Game
void PrintIntro() {
	
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

// Play the Game
// Allow the Player to make a set number of guesses
void PlayGame() {

	constexpr int NUM_GUESSES = 5;
	for (int i = 0; i < NUM_GUESSES; ++i) {
		string Guess = GetGuess();
		cout << "Your guess: " << Guess << endl << endl;
	}
}

// Obtain a guess from the player
string GetGuess() {
	
	cout << "Please guess an isogram: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}
