#include "stdafx.h"
#include "BruteForceFinder.h"


BruteForceFinder::BruteForceFinder()
{
}


BruteForceFinder::~BruteForceFinder()
{
}

unsigned int BruteForceFinder::Find(std::string inputString, std::string searchString)
{
	unsigned int startIdx = UINT_MAX;
	bool matchFound = false;
	for (unsigned int i = 0; i < inputString.length(); i++)
	{
		// if this character matches the beginning of the searchString
		unsigned int j = i;
		unsigned int k = 0;
		//while ((j < inputString.length()-1) && (k < searchString.length()-1) &&  (inputString[j] == searchString[k]))
		while (inputString[j] == searchString[k])
		{
			// if we;ve matched all of the searchString
			if (k == searchString.length() - 1)
			{
				matchFound = true;
				break;
			}
			// if we've checked all the input characters without a match
			if (j == inputString.length() - 1)
			{
				break;
			}
			++j;
			++k;
		}
		if (matchFound)
		{
			startIdx = i;
			break;
		}
	}
	return startIdx;
}
