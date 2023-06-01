#pragma once
#include "Token.h"
#include "Pointer.h"

class TokenRegexp abstract
{
protected:
	Pointer* _pointer;
public:
	TokenRegexp(Pointer* pointer);
	virtual bool tryAnalize(Token*& token) = 0;
};

