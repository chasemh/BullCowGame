#include <iostream>
#include <string>
#include "FBullCowGame.h"

// # Designates a preprocessor directive
// Use <> for including standard libraries
// Use "" for your including your own header files

// Method Signatures/Prototypes
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // Instantiate a new game

// Entry point for application
int main() {

	PrintIntro();

	do {
		PlayGame();
	} while ( AskToPlayAgain() );
	
	return 0;
}

// Introduce the Game
void PrintIntro() {
	
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

// Play the Game
// Allow the Player to make a set number of guesses
void PlayGame() {

	int MaxTries = BCGame.GetMaxTries();
	std::cout << "Max Tries: " << MaxTries << std::endl;

	//TODO Change from FOR to WHILE after adding validation
	for (int i = 0; i < MaxTries; ++i) {
		std::string Guess = GetGuess();
		// TODO Add Guess Validation
		// TODO Submit Valid Guess to Game
		// TODO Print Number of Bulls and Cows
		std::cout << "Your guess: " << Guess << std::endl << std::endl;
	}

	// TODO Add a Game summary
}

// Obtain a guess from the player
std::string GetGuess() {
	
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ": Please guess an isogram: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {

	std::cout << "Would you like to play again? (y/n): ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}
