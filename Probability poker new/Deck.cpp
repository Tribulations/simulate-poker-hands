// Deck.cpp
#include "Deck.h"
#include <iostream>
#include <random>
using namespace std;

Deck::Deck()
{
	createDeck();
}

void Deck::createDeck()
{
	
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			Card card(mRanks[j], mSuits[i], mValues[j]); 
			mDeck.push_back(card);
		}
	}

}

void Deck::shuffle()
{
	
	random_device rd; 
	mt19937 mt(rd()); 
	uniform_int_distribution<unsigned int> dist(0, 51);

	bool positionUsed[52]{ 0 }; 

	for (int i = 0; i < 52; ++i)
	{
		int randPos = dist(mt);
		int randPos2 = dist(mt);

		if (positionUsed[randPos] == 0 && positionUsed[randPos2] == 0)
		{
			positionUsed[randPos] = 1;
			positionUsed[randPos2] = 1;

			Card temp = mDeck.at(randPos);
			mDeck.at(randPos) = mDeck.at(randPos2);
			mDeck.at(randPos2) = temp;
		}
	}
}

// Deck.cpp
void Deck::draw5()
{
	for (int i = 0; i < 5; ++i)
	{
		mHand.push_back(mDeck.at(i));
	}
}

void Deck::printDeck()
{
	for (int i = 0; i < 52; ++i)
	{
		cout  << mDeck.at(i).getRank() << mDeck.at(i).getSuit() << " ";
	}
}

void Deck::printHand()
{
	for (int i = 0; i < 5; ++i)
	{
		cout << mHand.at(i).getRank() << mHand.at(i).getSuit() << " ";
	}

	cout << endl;
}

std::vector<Card>& Deck::getHand()
{
	return mHand;
}

std::vector<Card> Deck::getDeck()
{
	return mDeck;
}

void Deck::clearHand()
{
	mHand.clear();
}


