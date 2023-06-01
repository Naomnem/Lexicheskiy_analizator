#include "Punctuator.h"

Punctuator::Punctuator(int id, const char* startPtr, size_t length) : Token(TypeOfToken::Punctuators, startPtr, length)
{
	_punctuatorId = id;
}

std::string Punctuator::toString()
{
	return "Punctuator: " + std::string(getStartPtr(), getLength());
}

bool Punctuator::isBracket()
{
	return _punctuatorId < 6;
}

bool Punctuator::isOpenBracket()
{
	return isBracket() && (_punctuatorId % 2 == 0);
}

bool Punctuator::isCloseBracket()
{
	return isBracket() && (_punctuatorId % 2 == 1);
}

int Punctuator::getPunctuatorId()
{
	return _punctuatorId;
}

int findPunctuator(std::string string)
{
	int i = 0;
	for (std::string punctuator : Punctuators)
	{
		if (punctuator == string)
			return i;
		i++;
	}
	return -1;
}