// FindSubStr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "finder.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
	std::cout << "Starting FindSubStr...\n";

	std::string inputString = "TETiEST THIS IS A TES TEST ST";
	std::string searchString = "TEST";

	int startIdx = -1;

	Finder *myFinder = new Finder();
	//startIdx = myFinder->findUsingSimpleDP(inputString, searchString);
	//startIdx = myFinder->findUsingRegression(inputString, searchString);
	startIdx = myFinder->findBruteForce(inputString, searchString);


	

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

