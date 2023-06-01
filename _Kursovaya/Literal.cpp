#include "Literal.h"

Literal::Literal(const char* startPtr, size_t length) : Token(TypeOfToken::Literals, startPtr, length){}

std::string Literal::toString()
{
    return "Literal: " + Token::toString();
}