#include "stdafx.h"
#include "Finder.h"


unsigned int FinderBase1::Find(std::string inputString, std::string searchString)
{
	return 0;
}

unsigned int FinderBruteForce1::Find(std::string inputString, std::string searchString)
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

Finder::Finder()
{
}


Finder::~Finder()
{
}

int Finder::findUsingSimpleDP(std::string inputString, std::string searchString)
{
	//int matrix[][] = new int[inputString.length()][searchString.length()];

	// Note: this algorithm does not work when candidate cases overlap

	int nextCharToMatch = 0;
	int startIdx = -1;

	for (int i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] == searchString[nextCharToMatch])
		{
			//set the start index if this is the first matched character
			if (nextCharToMatch == 0)
			{
				startIdx = i;
			}

			++nextCharToMatch;
			
			// check if we've matched the whole string
			if (nextCharToMatch == searchString.length())
			{
				break;
			}
		}
		else
		{
			// bug -> if the character is the first character of the search string we are throwing it away TETEST
			// Any overlapping candidate combination could cause possible combinations to be missed.  
			startIdx = -1;
			nextCharToMatch = 0;
		}
	}
	return startIdx;
}

unsigned int Finder::findUsingRegression(std::string inputString, std::string searchString)
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

bool Finder::match(std::string inputString, unsigned int i, std::string searchString, unsigned int j)
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

unsigned int Finder::findBruteForce(std::string inputString, std::string searchString)
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

