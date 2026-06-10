// func.h
#pragma once
#include <string>
using namespace std;

class Vals
{
	public:
		Vals(int _total, int _favOut, float _relFreq) : mTotal(_total), mFavOut(_favOut), mRelFreq(_relFreq) {}
	
		int getTotal()
		{
			return mTotal;
		}
	
		int getFavOut()
		{
			return mFavOut;
		}
	
		float getRelFreq()
		{
			return mRelFreq;
		}
	
	private:
		int mTotal;
		int mFavOut;
		float mRelFreq;
};

string readLastline(string filepath);

Vals getVals(string line);

bool fileIsEmpty(std::ifstream& pFile);


