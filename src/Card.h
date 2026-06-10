// Card.h
#pragma once

class Card
{
	public:
		Card(char _rank, char _suit, int _value) : mRank(_rank), mSuit(_suit), mValue(_value){}

		char getRank();
		char getSuit();
		int getValue();

	private:
		char mRank;
		char mSuit;
		int mValue;
};