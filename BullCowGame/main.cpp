/* Console Executable
 Makes use of the FBullCowGame Class
 Acts as the view in the MVC pattern. Handles all user interaction.
 Internal logic is in the FBullCowGame class.

 Author: Chase Hennion <chase_hennion@outlook.com>
*/

#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Aliases that will be more compatible with Unreal when it is used.
using FText = std::string;
using int32 = int;

// Function Signatures/Prototypes
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();
int32 GetValidDesiredWordLength();

// Constants
constexpr int32 MAX_WORD_LENGTH = 7;
constexpr int32 MIN_WORD_LENGTH = 3;

// Global Variables
FBullCowGame BCGame;  // Object is reused across games.

// Program Start Point
int main() {

	PrintIntro();

	do {
		PlayGame();
	} while ( AskToPlayAgain() );
	
	return 0;
}

// Introduces the Game to the Player
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
	
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n\n";
	return;
}

// Plays a single game to completion.
void PlayGame() {

	// Ask the player for the length of isogram they would like 
	int32 WordLength = GetValidDesiredWordLength();

	// Get the game to find an isogram with the desired length
	BCGame.SetHiddenWord( WordLength );

	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "Max Tries: " << MaxTries << std::endl;

	// While the game has NOT been won and tries remain
	while( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries ) {
		std::string Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess( Guess );
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}

// Obtains a valid guess from the player.
// A guess is valid if it is the same length as the hidden word, is an isogram, and is all lowercase.
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

// Asks the player if they would like to play the game again.
// @return  true if the player responds yes, false otherwise
bool AskToPlayAgain() {

	std::cout << "Would you like to play again? (y/n): ";
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

// Prompts the player to enter their desired isogram length for the game.
int32 GetValidDesiredWordLength()
{
	
	int32 Choice = -1;
	bool ValidChoice = false;

	do {

		std::cout << "What length isogram would you like to play the game with?\n";
		std::cout << "Currently Supported Isogram Lengths: 3, 4, 5, 6 and 7.\n\n";
		std::cout << "Please enter your desired isogram length: ";
		FText Response = "";
		std::getline( std::cin, Response );
		// Include handling for when users provide a non-integer value.
		try {
			Choice = stoi( Response );
			if ( Choice >= MIN_WORD_LENGTH && Choice <= MAX_WORD_LENGTH ) {
				ValidChoice = true;
			}
			else {
				std::cout << "Whoops! It looks like " << Choice << " is not a valid value. Please try again.\n\n";
			}
		}
		catch ( std::invalid_argument )
		{
			std::cout << "Whoops! It looks like " << Response << " is not an integer value. Please try again.\n\n";
		}
		
	} while ( !ValidChoice );

	return Choice;
}
