#pragma once
#include "Punctuator.h"
#include "InvalidBracketOrderException.h"
#include <list>

class BracketCounter
{
private:
	std::list<Punctuator*> _brackets;
public:
	BracketCounter();
	void addCount(Punctuator* bracket);
	size_t getDepth();

};

