// functions.cpp
#include "functions.h"
#include <iostream>

bool isPair(std::vector<Card>& pokerHand)
{
	int matchingRanks = 1;
	
	sortByRank(pokerHand);
	
	// loop trough all cards and count matching ranks
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = i + 1; j < 5; ++j)
		{
			if (matchingRanks > 2)
				return false;
	
			if ( pokerHand.at(i).getRank() == pokerHand.at(j).getRank() ) // found two of the same rank
				matchingRanks++;
		}
	}

	if (matchingRanks == 1 || matchingRanks > 2)
		return false;
	else
		return true;
}

bool isFullHouse(std::vector<Card>& pokerHand)
{
	sortByRank(pokerHand);

	// first 2 ranks and last 3 ranks match, eg. KKAAA
	if (pokerHand.at(0).getRank() == pokerHand.at(1).getRank())
		if (pokerHand.at(2).getRank() == pokerHand.at(3).getRank() && pokerHand.at(2).getRank() == pokerHand.at(4).getRank())
			return true;

	// first 3 and last 2 eg. KKKAA
	if (pokerHand.at(0).getRank() == pokerHand.at(1).getRank() && pokerHand.at(0).getRank() == pokerHand.at(2).getRank())
		if (pokerHand.at(3).getRank() == pokerHand.at(4).getRank())
			return true;

	return false;

}

// functions.cpp
bool isFourOfAKind(std::vector<Card>& pokerHand)
{
	sortByRank(pokerHand);
	
	if (pokerHand.at(0).getRank() == pokerHand.at(3).getRank())
		return true;
	else if (pokerHand.at(1).getRank() == pokerHand.at(4).getRank())
		return true;
	else
		return false;	
}

bool isRoyalFlush(std::vector<Card>& pokerHand)
{
	sortByValue(pokerHand);

	for (int i = 0; i < 4; ++i)
	{

		if (pokerHand.at(i).getValue() == 9 + i && pokerHand.at(i + 1).getValue() == 9 + i + 1 && pokerHand.at(i).getSuit() == pokerHand.at(i + 1).getSuit())
			continue;
		else
			return false;
	}

	return true;
}

// functions.cpp
void sortByRank(std::vector<Card>& pokerHand)
{
	int i, j, n = pokerHand.size();
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (static_cast<int>(pokerHand.at(j).getRank() ) > static_cast<int>(pokerHand.at(j + 1).getRank() ))
			{
				Card temp = pokerHand.at(j);
				pokerHand.at(j) = pokerHand.at(j + 1);
				pokerHand.at(j + 1) = temp;
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break
		if (swapped == false)
			break;
	}
}

void sortByValue(std::vector<Card>& pokerHand)
{
	int i, j, n = pokerHand.size();
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (pokerHand.at(j).getValue() > pokerHand.at(j + 1).getValue())
			{
				Card temp = pokerHand.at(j);
				pokerHand.at(j) = pokerHand.at(j + 1);
				pokerHand.at(j + 1) = temp;
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break
		if (swapped == false)
			break;
	}
}