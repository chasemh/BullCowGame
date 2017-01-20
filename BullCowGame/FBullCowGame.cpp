#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

constexpr int32 MAX_TRIES = 8;
const FString HIDDEN_WORD = "ant";

FBullCowGame::FBullCowGame() {
	Reset();
}

FBullCowGame::~FBullCowGame() {
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset() {
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	return;
}

// Receives a Valid Guess
// Increments Turn
// Returns the count of bulls and cows
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	// Increment the turn number
	MyCurrentTry++;

	// Instantiate a new BullCowCount struct
	FBullCowCount BullCowCount;

	// Look through the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for ( int32 HWIndex = 0; HWIndex < HiddenWordLength; HWIndex++ ) {
		// Compare letters against hidden word in the same index
		for ( int32 GuessIndex = 0; GuessIndex < HiddenWordLength; GuessIndex++ ) {
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
		
	return BullCowCount;
}

bool FBullCowGame::IsGameOver() const {
	return false;
}

EWordStatus FBullCowGame::ValidateGuess(FString guess) {

	return EWordStatus::OK; //TODO Add logic to validate 
}

bool FBullCowGame::IsIsogram(FString str) {
	return false;
}

void FBullCowGame::PrintBull() const {
}

void FBullCowGame::PrintCow() const {
}
