#pragma once
#include "TokenRegexp.h"
#include "Literal.h"

class LiteralRegexp : public TokenRegexp
{
public:
	LiteralRegexp(Pointer* pointer);
	bool tryAnalize(Token*& token) override;
};

