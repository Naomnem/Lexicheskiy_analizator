#include "BracketCounter.h"

BracketCounter::BracketCounter()
{
	_brackets = {};
}

void BracketCounter::addCount(Punctuator* bracket)
{
	if (!bracket->isBracket())
		return;

	if (bracket->isOpenBracket())
	{
		_brackets.push_back(bracket);
		return;
	}

	if (_brackets.empty())
		throw new InvalidBracketOrderException();

	Punctuator* top = _brackets.back();
	if (top->getPunctuatorId() == bracket->getPunctuatorId() - 1)
	{
		_brackets.pop_back();
		return;
	}
	else
	{
		throw new InvalidBracketOrderException();
	}
}

size_t BracketCounter::getDepth()
{
	int count = 0;
	for (Punctuator* bracket : _brackets)
		count += (bracket->getOriginalString() == "{");

	return count;
}