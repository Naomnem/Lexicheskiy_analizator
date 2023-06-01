#pragma once
#include "TokenRegexp.h"
#include "Punctuator.h"

class PunctuatorRegexp : public TokenRegexp
{
public:
	PunctuatorRegexp(Pointer* pointer);
	bool tryAnalize(Token*& token) override;
};

