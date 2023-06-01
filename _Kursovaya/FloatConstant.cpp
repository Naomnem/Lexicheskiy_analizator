#include "FloatConstant.h"

FloatConstant::FloatConstant(const char* startPtr, size_t length) : Constant(startPtr, length)
{ }

std::string FloatConstant::toString()
{
	return "FloatConstant: " + Token::toString();
}