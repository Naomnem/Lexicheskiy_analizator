#pragma once
#include "TokenRegexp.h"
#include "IntegerConstant.h"
#include "FloatConstant.h"

class NumConstantRegexp : public TokenRegexp
{
public:
	NumConstantRegexp(Pointer* pointer);
	bool tryAnalize(Token*& token) override;
};

