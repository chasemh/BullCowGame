# Cows and Bulls Game Design Document (GDD)
Written by Chase Hennion  
Last Update: 16/01/2017

## Problem
* I want a mental challenge
* I want to feel smart / prove myself
* I miss word puzzles
* I want to challenge someone

## Concept and Rules
* Cows and Bulls is a "guess the isogram" game
* Isogram = Word with no repeating letters
* User has limited number of guesses
* After each guess, the CPU outputs the following:
	* A "Bull" = Right letter in the right location
	* A "Cow" = Right letter but in the wrong place
* You win by guessing the word within the max number of tries

## Requirements
Try answering the following questions:
* What will the inputs be? In what format?
* What will the outputs be?
* What tasks will the user be asked to do?
* Any performance limits worth mentioning?
* What assets (art, sound, story text) do we need?

### Inputs
* This is going to be a console/command line project
* Input from the user will be as plain text typed into the console

### Outputs
* CPU should print a Bull when the right letter is in the right place
	* Need an ASCII art Bull
* CPU should print a Cow when the right letter is guessed but it is in the wrong place
	* Need an ASCII art Cow
* The computer should also remind the player of how many guesses they have remaining
* Remind the user of the words they have guessed previously

### Tasks
* The player will need to guess words
* Need logic to ensure user provides acceptable input
	* Word provided needs to be the same length as the secret word
	* Word must be an isogram (word must not have any repeating letters)
	* Need logic to sanitize input (convert to a common case etc.)
	* Exception handling for non-strings

### Performance Limits
* Console applications so not very CPU heavy
* Ensure logic for checking guesses is efficient and doesn't use an exorbinant amount of CPU time
* Right now only going to have one secret word to guess

### Assets (Possibly Needed, Could be No List for now)
* ASCII Bull
* ASCII Cow

## Possible Future Ideas (Current No List)
* Have a bank of words that could be guessed
* Pull bank of words for an external source, maybe an online dictionary
* Selectable difficulty
	* Harder Game = Longer word, fewer guesses
* Logic to check if user provided isogram is in fact a real English word and not just a bunch of characters
* Timer system
* Hint system
