/*
Implementation of the FBullCowGame class.

Please see FBullCowGame.h for class documentation.

Author: Chase Hennion <chase_hennion@outlook.com>
*/

#pragma once
#include "FBullCowGame.h"
#define TMap std::map

using FString = std::string;
using int32 = int;

constexpr int32 MAX_TRIES = 8;
const FString HIDDEN_WORD = "planet";

FBullCowGame::FBullCowGame() {
	// Only need to setup the Isograms map once
	ReadIsogramsFromFile();
	Reset();
}

FBullCowGame::~FBullCowGame() {
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameWon; }

int32 FBullCowGame::GetMaxTries() const { 
	// The number of tries available is dictated by the length of the word.
	// The longer the word, the more tries available.
	TMap< int32, int32 > LengthToMaxTries{
		{3, 4},
		{4, 7},
		{5, 10},
		{6, 15},
		{7, 20}
	};
	return LengthToMaxTries[GetHiddenWordLength()];
}

void FBullCowGame::Reset() {
	MyCurrentTry = 1;
	bGameWon = false;
	return;
}

void FBullCowGame::SetHiddenWord( int32 WordLength )
{
	// Get a random index within the vector containing isograms of the 
	// same size desired by the player.
	int32 randomIndex = rand() % Isograms[WordLength].size();
	MyHiddenWord = Isograms[WordLength][randomIndex];
	return;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = GetHiddenWordLength(); // Assume that the guess and hidden word have the same length

	// Look through the hiddenword
	for ( int32 HWIndex = 0; HWIndex < WordLength; HWIndex++ ) {
		// Compare letters against guess word
		for ( int32 GuessIndex = 0; GuessIndex < WordLength; GuessIndex++ ) {
			// If the letters match, 
			if ( Guess[GuessIndex] == MyHiddenWord[HWIndex] ) {
				if ( GuessIndex == HWIndex ) {
					// Letters match and they are in the same position in 
					// both the guess and the hidden word.
					BullCowCount.Bulls++;
				}
				else {
					// Letters do match but they are not in the same position in 
					// both the guess and the hidden word.
					BullCowCount.Cows++;
				}	
			}
		}		
	}

	if ( BullCowCount.Bulls == WordLength ) {
		// The player has guessed the hidden word and has won the game.
		bGameWon = true;
	}
		
	return BullCowCount;
}

EGuessStatus FBullCowGame::ValidateGuess( FString Guess ) {

	
	if ( !IsIsogram( Guess ) ) {
		// If the guess is not an Isogram
		return EGuessStatus::Not_Isogram;
	} 
	else if ( !IsLowercase( Guess ) ) { 
		// If the guess is not all lowercase
		return EGuessStatus::Not_Lowercase;
	}
	else if ( Guess.length() != GetHiddenWordLength() ) {
		// If the guess length is incorrect
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}

}

bool FBullCowGame::IsIsogram(FString Word) const {

	// If the string has 0 or 1 characters, then it must be isogram
	if ( Word.length() <= 1 ) {
		return true;
	}

	// TSet could also be used here
	// Create a new map, templated with chars as the keys and bools as the values.
	TMap<char, bool> LettersSeen;

	// Setup a range based for loop.
	// Read as "For all chars within word"
	// Why are we using auto? auto means that the compiler decides the type of the variable for you.
	// It is useful to see if the complier can properly see the correct type this way prior to compiling.
	for ( auto Letter : Word ) {
		Letter = tolower( Letter );
		if ( LettersSeen[Letter] ) {
			// We have already seen the letter so this word must not be an isogram.
			return false;
		}
		else {
			// We haven't seen the letter before. Remember it for later iterations.
			LettersSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowercase( FString Word ) const {

	for ( auto Letter : Word ) {
		if ( !islower( Letter ) ) {
			return false;
		}
	}

	return true;
}

void FBullCowGame::ReadIsogramsFromFile()
{
	// Open up the isograms file
	// Read in all of the contents and populate the words map
	std::ifstream IsogramFile;
	FString CurrentLine = "";

	IsogramFile.open( "../isograms.txt", std::ios::in );
	while ( std::getline( IsogramFile, CurrentLine ) ) {
		Isograms[CurrentLine.length()].push_back( CurrentLine );
	}

	IsogramFile.close();
	return;
}
