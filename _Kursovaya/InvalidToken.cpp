#include "InvalidToken.h"

InvalidToken::InvalidToken(const char* startPtr, size_t length) : InvalidToken(startPtr, length, "Not specified")
{
}

InvalidToken::InvalidToken(const char* startPtr, size_t length, std::string reason) : Token(TypeOfToken::Invalid, startPtr, length)
{
	_reason = reason;
}

std::string InvalidToken::toString()
{
	return "InvalidToken: " + Token::toString() + " [" + _reason + "]";
}
