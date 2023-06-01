#include "Token.h"

Token::Token(TypeOfToken id, const char* startPtr, size_t lenght)
{
	_typeOfToken = id;
	_startPtr = startPtr;
	_length = lenght;
}

size_t Token::getLength()
{
	return _length;
}

const char* Token::getStartPtr()
{
	return _startPtr;
}

TypeOfToken Token::getTokenType()
{
	return _typeOfToken;
}

std::string Token::getOriginalString()
{
	return std::string(_startPtr, _length);
}

std::string Token::toString()
{
	return std::string(_startPtr, _length);
}

std::ostream& operator << (std::ostream& out, Token* token)
{
	std::cout << token->toString();
	return out;
}