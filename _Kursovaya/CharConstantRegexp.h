#pragma once
#include "TokenRegexp.h"
#include "CharConstant.h"

class CharConstantRegexp : public TokenRegexp
{
public:
	CharConstantRegexp(Pointer* pointer);
	bool tryAnalize(Token*& token) override;
};

