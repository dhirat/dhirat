/***********************************************************************
	In order to develop the class, Card.cpp source file has been created.
************************************************************************/

#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

// Function to call constructors
Card::Card(){
	value		= 0;				// 0 = N/A
	suit		= ' ';				// ' ' = N/A
	nextCard	= NULL;				// NULL pointer
}

Card::Card(int card_value, char card_suit, Card* next){
	value    = card_value;
	suit     = card_suit;
	nextCard = next;
}

// For the Suit Setter Function
void Card::setSuit(char card_suit) {
	suit = card_suit;
}

// For Value Setter Function
void Card::setValue(int card_value) {
	value = card_value;
}

// For Next Card Setter Function
void Card::setNextCard(Card* next) {
	nextCard = next;
}

// for Suit Getter value
char Card::getSuit() {
	return suit;
}

// for Value Getter function
int	Card::getValue() {
	return value;
}

// For the Next Card Getter Function
Card* Card::getNextCard() {
	return nextCard;
}

// For Print Function
void Card::print() {

	switch (value)
	{
	case 1:
		cout << 'A';		// Take case 1 as Ace
		break;
	case 10:
		cout << 'T';		// Take case 10 as Ten
		break;
	case 11:
		cout << 'J';		// Take case 11 as Jack
		break;
	case 12:
		cout << 'Q';		// Take case 12 as Queen
		break;
	case 13:
		cout << 'K';		// Take case 13 as King
		break;
	default:				
		cout << value ;	    // Other values from 2 to 9
		break;
	}
	// for printing the suits
	cout << suit << " ";	
}