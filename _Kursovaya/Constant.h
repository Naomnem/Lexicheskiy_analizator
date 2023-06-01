#pragma once
#include "Token.h"
#include "Pointer.h"

class Constant : public Token
{
public:
	Constant(const char* startPtr, size_t length);
	std::string toString() override;
};

