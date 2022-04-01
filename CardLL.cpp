/********************************************************************
	In order to fully develop the class, CardLL.cpp source file has
	been created.
*********************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "CardLL.h"

using namespace std;

// for the default Constructor function
CardLL::CardLL() {
	length  = 0;
	top		= NULL;
}

// for the destructor function to delete each item from list
CardLL::~CardLL() {
	while (top != NULL) {
		removeCardAt(0);
	}
}

// function that inserts a given card at the top of the list
void CardLL::insertAtTop(char card_suit, int card_value) {

	Card* newCard = new Card(card_value, card_suit, top);
	top = newCard;

	length++;
}

// this function will return a Card pointer which points to the card
// at the given position. If the position doesn’t exist in the list,
// it will just return NULL.
Card* CardLL::getCardAt(int pos) {
	if (pos > length || pos < 0) {		
		return NULL;				// length, or invalid pos								
	}

	Card* walk	  = top;			// walk pointer through list
	int   Check   = pos;			// Counter to walk through list

	// for locating the Card
	while (Check != 0) {			// loop to next Card pos times
		walk = walk->getNextCard();
		Check--;
	}
	// returning to pass the card
	return walk;						
}

// this function will remove the card at the given position,
// returning true if successful. If the position outside 
// the bounds of the list, otherwise return false.
bool CardLL::removeCardAt(int pos) {

	if (pos > length || isEmpty() || pos < 0) {							
		return false;
	}

	Card* lead   = top;				  // lead pointer through list
	Card* next   = top;				  // this next Pointer leads
	int Check    = pos;				  // check to walk through list

	if (pos == 0) {					  // if top position is removed
		if (length != 1) {			  // if length is not the only item
			top = top->getNextCard(); // if the second item is Top
		}
		else {							
			top = NULL;				  // else if the next item is NULL
		}
		delete lead;				  // to delete item at its position
		lead = NULL;
		length--;						
		return true;					
	}
	else {
		while (Check > 0) {				
			next = lead;				
			lead = lead->getNextCard();
			Check--;
		}
		next->setNextCard(lead->getNextCard());	
		delete lead;								
		lead = NULL;
		length--;									
		return true;
	}
}

// for length Getter Functions which returns length
int	CardLL::getLength() {
	return length;
}

// for the isEmpty Function which returns true if list's empty
bool CardLL::isEmpty() {
	return (top == NULL);
}

// For the Print Function 
void CardLL::print() {
	Card* walk = top;					
	cout << endl << "Top: ";		// prints "Top : " First item
	while (walk != NULL) {				
		walk->print();				// prints each item with spacebar		
		cout << " ";
		walk = walk->getNextCard();
	}
}

// Shuffle Function to randomly list cards using Fisher-Yates technique
void CardLL::shuffle() {
	Card* walk = top;
	int randPos;

	while (walk != NULL){				// Fisher-Yates shuffle loop
		randPos = rand() % length;		// get randomNumber betn 0 & len – 1
		swap(walk, getCardAt(randPos));	// to get the card at that position
		walk = walk->getNextCard();
	}
}

// Functions for Swapping Cards to Just swap the suit and the value.
void CardLL::swap(Card* card_card1, Card* card_card2) {
	int  tempInt;
	char tempChar;

	// for swapping the values
	tempInt = card_card1->getValue();
	card_card1->setValue(card_card2->getValue());
	card_card2->setValue(tempInt);

	// for swapping the suits
	tempChar = card_card1->getSuit();
	card_card1->setSuit(card_card2->getSuit());
	card_card2->setSuit(tempChar);
}
