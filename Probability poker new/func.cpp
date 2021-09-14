// func.cpp
#include <fstream>
#include "func.h"
#include "functions.h"
#include "Deck.h"
#include <iostream>
#include <string>

string readLastline(string filepath)
{
	ifstream file;
	file.open(filepath, ios::in);

	string lastline;

	if (file.is_open())
	{
		file.seekg(-1, std::ios_base::end);
		int pos = file.tellg();

		for (; pos > 0; --pos)
		{
			file.seekg(pos);

			if (file.peek() == '\n')
			{
				pos++;
				file.seekg(pos);
				break;
			}

		}

		getline(file, lastline);
	}
	else
		cout << "Could not open the file";

	file.close();

	return lastline;
}

// func.cpp
Vals getVals(string line)
{
	int pos = line.find_first_of(',');
	int total = stoi(line.substr(0, pos));

	line = line.substr(pos + 1);

	pos = line.find_first_of(',');
	int favOut = stoi(line.substr(0, pos));

	float relFreq = stof(line.substr(pos + 1));

	Vals vals(total, favOut, relFreq);

	return vals;
}

bool fileIsEmpty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}
