#pragma once
// Directive above ensures this class is only imported once 
#include <iostream>
#include <string>

//Best Practice: Don't use namespaces in header files.

//FString = Mutable string, typically used internally for Unreal.
//FText = Typically reserved for user output

// Aliases that will be more compatible with Unreal when it is used.
using FString = std::string;
using int32 = int;

constexpr int32 MAX_TRIES = 8;

class FBullCowGame {
public:

	FBullCowGame(); //Constructor
	~FBullCowGame(); //Destructor
	
	// Best Practice: Accessors methods should have the const qualifier
	// This prevents modifications of the object parameters when accessing them.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameOver() const;

	void Reset();
	// TODO Provide a method submitting valid guesses
	// method should could all bulls and cows and update the current turn number
	

private:
	// Initialized in constructor
	int32 MyMaxTries;
	int32 MyCurrentTry;

	// TODO Should these be public static methods?
	bool ValidateGuess( FString guess );
	bool IsIsogram( FString str );
	void PrintBull() const;
	void PrintCow() const;
};