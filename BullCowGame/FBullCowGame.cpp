#include "FBullCowGame.h"


FBullCowGame::FBullCowGame() {
	Reset();
}

FBullCowGame::~FBullCowGame() {
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset() {
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	return;
}

std::string FBullCowGame::GetNextGuess() {
	return std::string();
}

void FBullCowGame::PlayGame() {
	return;
}

bool FBullCowGame::IsGameOver() const{
	return false;
}

bool FBullCowGame::ValidateGuess(std::string guess) {
	return false;
}

bool FBullCowGame::IsIsogram(std::string str) {
	return false;
}

void FBullCowGame::PrintBull() const {
}

void FBullCowGame::PrintCow() const {
}
