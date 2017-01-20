#pragma once
// Directive above ensures this class is only imported once 
#include <iostream>
#include <string>

//Best Practice: Don't use namespaces in header files.

constexpr int MAX_TRIES = 8;

class FBullCowGame {
public:

	FBullCowGame(); //Constructor
	~FBullCowGame(); //Destructor
	
	// Best Practice: Accessors methods should have the const qualifier
	// This prevents modifications of the object parameters when accessing them.
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameOver() const;

	void Reset();
	// TODO Provide a method submitting valid guesses
	// method should could all bulls and cows and update the current turn number
	

private:
	// Initialized in constructor
	int MyMaxTries;
	int MyCurrentTry;

	// TODO Should these be public static methods?
	bool ValidateGuess( std::string guess );
	bool IsIsogram( std::string str );
	void PrintBull() const;
	void PrintCow() const;
};