#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {
	Reset();
}

FBullCowGame::~FBullCowGame() {
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset() {
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	return;
}

bool FBullCowGame::IsGameOver() const{
	return false;
}

bool FBullCowGame::ValidateGuess(FString guess) {
	return false;
}

bool FBullCowGame::IsIsogram(FString str) {
	return false;
}

void FBullCowGame::PrintBull() const {
}

void FBullCowGame::PrintCow() const {
}
