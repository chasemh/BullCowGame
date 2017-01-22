#pragma once
// Directive above ensures this class is only imported once 
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#define TMap std::map

//Best Practice: Don't use namespaces in header files.

//FString = Mutable string, typically used internally for Unreal.
//FText = Typically reserved for user output

// Aliases that will be more compatible with Unreal when it is used.
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

// When you add 'class' to the definition, it turns an enum into a strongly typed enum.
// This allows you to have multiple enums that contain the same values.
// If you did not make them strongly typed, you could not have two enums that contain 
// OK for example because of the high level scoping of the enum's values.
// Enums are useful for provding richer, more meaningful return values.
// In this case, we are using enums sort of like exit/error codes.
enum class EGuessStatus {
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

enum class EResetStatus {
	OK
};

class FBullCowGame {
public:

	FBullCowGame(); //Constructor
	~FBullCowGame(); //Destructor
	
	// Best Practice: Accessors methods should have the const qualifier
	// This prevents modifications of the object parameters when accessing them.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	void Reset();
	void SetHiddenWord( int32 );
	FBullCowCount SubmitValidGuess(FString);
	EGuessStatus ValidateGuess(FString);

private:
	// Initialized in constructor
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameWon;
	TMap< int32, std::vector< FString > > Isograms;

	bool IsIsogram( FString ) const;
	bool IsLowercase( FString ) const;
	void ReadIsogramsFromFile();
};