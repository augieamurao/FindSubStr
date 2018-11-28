#pragma once
#include <string>

class FinderBase
{
public:
	FinderBase();
	~FinderBase();
	virtual unsigned int Find(std::string inputString, std::string searchString);
};

