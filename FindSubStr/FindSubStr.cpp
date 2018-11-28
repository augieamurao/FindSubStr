// FindSubStr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FinderBase.h"
#include "BruteForceFinder.h"
#include "RegressionFinder.h"

using std::cout;
using std::endl;
using std::string;

int testSolution()
{
	int returnValue = 0;
	return returnValue;
}
int main()
{
	std::cout << "Starting FindSubStr...\n";

	std::string inputString = "TETiEST THIS IS A TES TEST ST";
	std::string searchString = "TEST";

	int startIdx = -1;

	FinderBase *baseFinder;
	BruteForceFinder *bfFinder = new BruteForceFinder();
	
	baseFinder = bfFinder;
	//startIdx = baseFinder->Find(inputString, searchString);

	RegressionFinder *regFinder = new RegressionFinder();
	baseFinder = bfFinder;
	startIdx = baseFinder->Find(inputString, searchString);

	if (startIdx > -1)
	{
		std::cout << searchString << "  was found at index: " << startIdx << std::endl;
		std::cout << "string found: " << inputString.substr(startIdx, searchString.length()) << std::endl;
	}
	else
	{
		std::cout << searchString << " was not found." << std::endl;
	}
	
    return 0;
}

