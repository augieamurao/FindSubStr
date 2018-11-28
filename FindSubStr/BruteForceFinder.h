#pragma once
#include "FinderBase.h"
class BruteForceFinder :
	public FinderBase
{
public:
	BruteForceFinder();
	~BruteForceFinder();
	unsigned int Find(std::string inputString, std::string searchString);


};

