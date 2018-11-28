#pragma once
#include "FinderBase.h"
class RegressionFinder :
	public FinderBase
{
public:
	RegressionFinder();
	~RegressionFinder();
	bool match(std::string inputString, unsigned int i, std::string searchString, unsigned int j);
	unsigned int Find(std::string inputString, std::string searchString);

};

