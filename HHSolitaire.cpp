/**********************************************************************
 Name:       Dhirat Raut
 Date:       30th March, 2022 (Wednesday)
 Course:     CSCI 501_01 (Computer Programming Concepts, C++)
 Professor:  Dr.Jordan Ringenberg
 Project_4:  Handheld Solitaire - Large Project

 Handheld Solitaire requires no table, has simple rules, and is easily
 learned and played. It is played with a traditional 52 card deck of 
 4 suits ((H)earts, (S)lubs, (D)iamonds, and (S)pades) and 13 ranks from 
 Ace (1) to king (13). Jokers are not included. The deck (face down) 
 is held in one hand, while the actual hand of cards to be played is 
 placed face up on top of the deck. 
************************************************************************/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Card.h"
#include "CardLL.h"

using namespace std;

// definig all of the functions
void populateDeck(CardLL* Deck);
void dealRandCard(CardLL* cardFrom, CardLL* CardTo);
char checkRandMatches(CardLL* Hand);
void removeRandMatches(CardLL* Hand, char card_matchType);

// first the main function
int main() {
	srand(time(NULL));							

	CardLL Deck;								
	CardLL Hand;								
	char matchResult = 0;						
	populateDeck(&Deck);						
	Deck.shuffle();								

	while (!Deck.isEmpty()) {

		dealRandCard(&Deck, &Hand);

		// uncomment getchar() to give program more of a game “feelings"
		// (void)getchar();

		Hand.print();

		matchResult = checkRandMatches(&Hand);

		while (matchResult != ' ' && matchResult != 0) {
			// Remove the Cards if matched
			removeRandMatches(&Hand, checkRandMatches(&Hand));

			// If not check for more matches 
			matchResult = checkRandMatches(&Hand);
		}
	}

	cout << endl << "Deck Empty! Printing Leftover Hands: " << endl;
	Hand.print();
	cout << endl;
	return 0;
}

// Function for Populating the Deck with 52 cards
void populateDeck(CardLL* Deck) {

	char suits[4] = { 'D','C','H','S' };	// 4-Suits Array

	for (int suit = 0; suit < 4; suit++) {				
		// for all the cardvalues from 1 to 13.
		for (int value = 1; value <= 13; value++) {			
			Deck->insertAtTop(suits[suit], value);				
		}
	}
}

// Function for drawing Cards from Deck to Hand
void dealRandCard(CardLL* Deck, CardLL* Hand) {

	int  tempValue;
	char tempChar;

	// for getting value and suit of top(0) card in Deck
	tempValue = (Deck->getCardAt(0))->getValue();
	tempChar = (Deck->getCardAt(0))->getSuit();

	// for adding it at the top of the hand
	Hand->insertAtTop(tempChar, tempValue);

	// for removing the top card in deck
	Deck->removeCardAt(0);
}


// Function for counting the matches
char checkRandMatches(CardLL* Hand) {

	// No match if the hand length is less than 4
	if (Hand->getLength() < 4) {
		return 0;
	}
	char result = ' ';				// stores the result of matching check

	int  firstCard_Value;			// it stores first card value
	char firstCard_Suit;			// it stores first card suit

	int  fourBackCard_Value;		// it stores 4 cards back value
	char fourBackCard_Suit;			// it stores 4 cards back suit

	// now to set the variables 
	firstCard_Value = (Hand->getCardAt(0))->getValue();
	firstCard_Suit = (Hand->getCardAt(0))->getSuit();

	fourBackCard_Value = (Hand->getCardAt(3))->getValue();
	fourBackCard_Suit = (Hand->getCardAt(3))->getSuit();

	if (firstCard_Suit == fourBackCard_Suit) {	
		return 'S';
	}
	// Number(value) Match
	else if (firstCard_Value == fourBackCard_Value) {	
		return 'V';
	}
	return ' ';					// return if not matched
}

//  Functions for removing the Cards
void removeRandMatches(CardLL* Hand, char card_matchType) {

	// if the card doesnt match, it wont remove card
	if (card_matchType == ' ') {
		return;
	}

	// if suit Match, (2, 3) would be removed
	else if (card_matchType == 'S') {

		cout << endl << "Suit Match! Removing: ";
		// for printing the Card(1)
		Hand->getCardAt(1)->print();
		cout << " ";
		// for printing the Card(2)
		Hand->getCardAt(2)->print();
		cout << endl;

		// first Removing Card number 1
		Hand->removeCardAt(1);
		// Removing Card 2 but only after removing Card 1 
		Hand->removeCardAt(1);
		Hand->print();

		return;
	}

	// if the value matched, (Top, 2, 3, 4) cards would be removed
	else if (card_matchType == 'V') {
		cout << endl << "Number Match! Removing: ";
		
		for (int index = 1; index <= 4; index++) {
			// for printing random 4 first Cards
			Hand->getCardAt(Hand->getLength() - index)->print();
			cout << " ";
		}
		cout << endl;

		// for removing all 4 Cards
		for (int index = 1; index <= 4; index++) {
			Hand->removeCardAt(0);
		}

		// for printing the hand again
		Hand->print();
		return;
	}
}