#include "Constant.h"

Constant::Constant(const char* startPtr, size_t length) : Token(TypeOfToken::Constants, startPtr, length){ }

std::string Constant::toString()
{
	return "Constant: " + Token::toString();
}