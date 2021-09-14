// main.cpp
#include "Deck.h"
#include "functions.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include "func.h"
using namespace std;

int main()
{	
	ofstream logFile;
	string filepath = "fourOfAKind.txt";
	ifstream file;
	file.open(filepath, ios::in);

	int favOutCount;
	int total;
	double relFreq;

	if(fileIsEmpty(file))
	{
		cout << "The file" << " " << filepath << " was created!" << "\n";
		favOutCount = 0;
		total = 0;
		relFreq = 0.0;
	}
	else
	{
		cout << "Successfully opened the file" << " " << filepath << "." << "\n";
		string lastline = readLastline(filepath);
		Vals vals = getVals(lastline);

		favOutCount = vals.getFavOut();
		total = vals.getTotal();
		relFreq = static_cast<double>(vals.getRelFreq());
	}

	int interval = 10000;

	// measure the time the program takes to finish
	std::chrono::system_clock::time_point tpStart = std::chrono::system_clock::now(); 
	std::chrono::system_clock::duration dtnStart = tpStart.time_since_epoch();

	// main.cpp
	for (int j = 0; j < 100; ++j)
	{
		
		int i = 0;
		for (; i < interval; ++i)
		{
			Deck deck;
			deck.shuffle();
			deck.shuffle();
			deck.shuffle();
			deck.shuffle();
			deck.draw5();

			if (isFourOfAKind(deck.getHand()))
			{	
				favOutCount++;
				deck.printHand();
			}
		}

		relFreq = (static_cast<float>(favOutCount) / (i * j + interval + total));

		logFile.open(filepath, fstream::out | fstream::app);
		if (logFile.is_open())
		{
			logFile << endl << i * j + interval + total << "," << favOutCount << "," << relFreq;
			logFile.close();
		}
		else
			return -1;	
	}
	
	std::chrono::system_clock::time_point tpEnd = std::chrono::system_clock::now();
	std::chrono::system_clock::duration dtnEnd = tpEnd.time_since_epoch();
	time_t totDuration = (dtnEnd.count() * std::chrono::system_clock::period::num / std::chrono::system_clock::period::den) - (dtnStart.count() * std::chrono::system_clock::period::num / std::chrono::system_clock::period::den);

	cout << "The time it took in seconds: " << totDuration << endl;

	return 0;
}
