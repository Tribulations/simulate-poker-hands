// functions.h
#pragma once
#include <vector>
#include "Card.h"

bool isPair(std::vector<Card>& pokerHand);

bool isFullHouse(std::vector<Card>& pokerHand);

bool isFourOfAKind(std::vector<Card>& pokerHand);

bool isRoyalFlush(std::vector<Card>& pokerHand);

void sortByRank(std::vector<Card>& pokerHand);

void sortByValue(std::vector<Card>& pokerHand);