/* Console Executable
 Makes use of the FBullCowGame Class
 Acts as the view in the MVC pattern. Handles all user interaction.
 Internal logic is in the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// # Designates a preprocessor directive
// Use <> for including standard libraries
// Use "" for your including your own header files

// Aliases that will be more compatible with Unreal when it is used.
using FText = std::string;
using int32 = int;

// Method Signatures/Prototypes
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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


	std::cout << "  ____        _ _                 _____" << std::endl;
	std::cout << " |  _ \\      | | |       ___     / ____|" << std::endl;
	std::cout << " | |_) |_   _| | |___   ( _ )   | |     _____      _____" << std::endl;
	std::cout << " |  _ <| | | | | / __|  / _ \\/\\ | |    / _ \\ \\ /\\ / / __|" << std::endl;
	std::cout << " | |_) | |_| | | \\__ \\ | (_>  < | |___| (_) \\ V  V /\\__ \\" << std::endl;
	std::cout << " |____/ \\__,_|_|_|___/  \\___/\\/  \\_____\\___/ \\_/\\_/ |___/" << std::endl;
	std::cout << "                           /" << std::endl;
	std::cout << "       \\|/          (__)  /" << std::endl;
	std::cout << "             /------(oo) /      \\|/  ^__^" << std::endl;
	std::cout << "            / || B  (__)             (oo)------\\" << std::endl;
	std::cout << "           *  ||----||    \\|/        (__) C  ||  *  \\|/" << std::endl;
	std::cout << "          \\|/                   \\|/    ||---w||" << std::endl;
	
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
	return;
}

// Play the Game
// Allow the Player to make a set number of guesses
void PlayGame() {

	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "Max Tries: " << MaxTries << std::endl;

	// While the game has NOT been won and tries remain
	while( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries ) {
		std::string Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess( Guess );
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}

	// TODO Add a Game summary
	PrintGameSummary();
	return;
}

// Loop continually until the user provides a valid guess.
FText GetValidGuess() { 

	EGuessStatus Status = EGuessStatus::Invalid;
	FText Guess = "";

	do {

		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ": Please guess an isogram: ";
		std::getline( std::cin, Guess );

		Status = BCGame.ValidateGuess( Guess );

		switch ( Status ) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " isogram. An isogram has no repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word with all lowercase letters.\n\n";
			break;
		default:
			// Guess appears to be valid
			break;
		}

	} while ( Status != EGuessStatus::OK ); // Keep looping until we obtain no errors from the input.

	return Guess;
}

bool AskToPlayAgain() {

	std::cout << "Would you like to play again with the same word? (y/n): ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

// Summarizes the game after it has ended
void PrintGameSummary() {
	if ( BCGame.IsGameWon() ) {
		// Player has won the game. Congratulate them.
		std::cout << "Congratulations! You won!\n";
	}
	else {
		// The player did not win.
		std::cout << "Sorry, you didn't guess the isogram. Better luck next time.\n";
	}
	return;
}
