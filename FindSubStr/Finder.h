#pragma once
#include <string>
class Finder
{
public:
	Finder();
	~Finder();

	int findUsingSimpleDP(std::string inputString, std::string searchString);
	unsigned int findUsingRegression(std::string inputString, std::string searchString);
	bool match(std::string inputString, unsigned int i, std::string searchString, unsigned int j);

	unsigned int findBruteForce(std::string inputString, std::string searchString);
};

