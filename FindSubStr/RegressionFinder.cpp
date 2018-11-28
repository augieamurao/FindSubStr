#include "stdafx.h"
#include "RegressionFinder.h"


RegressionFinder::RegressionFinder()
{
}


RegressionFinder::~RegressionFinder()
{
}

bool RegressionFinder::match(std::string inputString, unsigned int i, std::string searchString, unsigned int j)
{
	// We're past the end of the input string, so no match		
	if (i >= inputString.length())
	{
		return false;
	}

	// current character matches
	if (inputString[i] == searchString[j])
	{
		// We're at the end of the search string, so we have a match
		if (j == searchString.length() - 1)
		{
			return true;
		}
		// Continue checking the other characters
		else
		{
			return match(inputString, ++i, searchString, ++j);
		}
	}
	else
	{
		return false;
	}
}

unsigned int RegressionFinder::Find(std::string inputString, std::string searchString)
{
	unsigned int startIdx = UINT_MAX;
	for (unsigned int i = 0; i < inputString.length(); i++)
	{
		if (match(inputString, i, searchString, 0))
		{
			startIdx = i;
			break;
		}
	}
	return startIdx;
}

