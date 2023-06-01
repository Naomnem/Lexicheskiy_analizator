#pragma once
#include "TokenRegexp.h"
#include "Operator.h"

class OperatorRegexp : public TokenRegexp
{
public:
	OperatorRegexp(Pointer* pointer);
	bool tryAnalize(Token*& token) override;
};

