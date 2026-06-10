// Deck.h
#pragma once
#include <vector>
#include <string>
#include "Card.h"

class Deck
{
	public:
		Deck();
	
		void createDeck();
	
		void shuffle();
	
		void draw5();
	
		void printDeck();
	
		void printHand();

		std::vector<Card>& getHand();
		std::vector<Card> getDeck();

		void clearHand();
	
	private:
		std::vector<Card> mDeck;
		std::vector<Card> mHand;
		char mRanks[13] = { '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K', 'A' };	
		char mSuits[4] = { 'D', 'H', 'C', 'S' };
		int mValues[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 }; 
};
