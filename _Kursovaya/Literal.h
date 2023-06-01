#pragma once
#include "Token.h"
#include "Pointer.h"

class Literal : public Token
{
public:
	Literal(const char* startPtr, size_t length);
	std::string toString() override;
};

