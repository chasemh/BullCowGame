#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

// Aliases that will be more compatible with Unreal when it is used.
#define TMap std::map
using FString = std::string;
using int32 = int;

/*
Struct FBullCowCount

A struct used to store the number of "Bulls" and "Cows" that a certain 
guess contains.
A "Bull" designates that the provided guess has the same character in the same location
as the hidden word.
A "Cow" designates that the provided guess has the same character in it as the guess but it
is in the incorrect location.
*/
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

/*
Enum Class EGuessStatus

Contains a list of error codes that could be returned with a guess is submitted by a user.
Invalid: An invalid state. Used internally.
OK: Guess is acceptable
Not_Isogram: Guess is not an isogram
Wrong_Length: The length of the guess does not match the length of the hidden word
Not_Lowercase: The guess does not contain all lowecase characters.

Author: Chase Hennion <chase_hennion@outlook.com>
*/
enum class EGuessStatus {
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

/*
Class FBullCowGame

Contains all of the internal logic for playing the game "Bulls and Cows",
an isogram guessing game. Contains no handling for user interaction. 
This is an implementation of the game presentedin Section 2 of the Udemy 
Unreal Course. The original game concept and format was presented by Ben 
Tristem and the implementation here contains several of the ideas presented 
in the lectures for the course.

Author: Chase Hennion <chase_hennion@outlook.com>
*/
class FBullCowGame {
public:

	/*
	Default constructor.
	*/
	FBullCowGame(); 

	/*
	Default destructor
	*/
	~FBullCowGame();
	
	 /*
	 Obtains the maximum number of tries in the game.
	 @return The maximum number of tries in the game.
	 */
	int32 GetMaxTries() const;


	/*
	Obtains the current try number the player is on.
	@return The current try number the player is on.
	*/
	int32 GetCurrentTry() const;

	/*
	Gets the length of the hidden word the player is trying to guess.
	@return The length of the hidden word.
	*/
	int32 GetHiddenWordLength() const;

	/*
	Checks to see if the player has guessed the hidden word and thus won the game.
	@return true if the player has guessed the hidden word, false otherwise
	*/
	bool IsGameWon() const;


	/*
	Resets the game variables in preparation for a new game.
	*/
	void Reset();

	/*
	Sets the hidden word based upon the desired word length.
	@param The hidden word length.
	*/
	void SetHiddenWord( int32 );

	/*
	Submits a valid guess to the game
	@param The valid guess to submit.
	@return  An instance of FBullCowCount, which contains the number of "Bulls" and "Cows" for the guess.
	*/
	FBullCowCount SubmitValidGuess(FString);

	/*
	Validates a guess.
	@param The guess to validate.
	*/
	EGuessStatus ValidateGuess(FString);

private:
	/*
	The current try the player is on.
	*/
	int32 MyCurrentTry;

	/*
	The hidden word that the player is trying to guess.
	*/
	FString MyHiddenWord;

	/*
	A boolean. If set to true, the game has been won by the player.
	*/
	bool bGameWon;

	/*
	A map containing a list of random isograms read from a file
	Used internally to select a random isogram of the length specified by the player.
	*/
	TMap< int32, std::vector< FString > > Isograms;

	/*
	Checks to see if a given word is an isogram
	@param The word to check.
	*/
	bool IsIsogram( FString ) const;

	/*
	Checks to see if a given word has all lowercase characters
	@param The word to check
	*/
	bool IsLowercase( FString ) const;

	/*
	Reads isograms from a file and populates the Isograms map.
	*/
	void ReadIsogramsFromFile();
};