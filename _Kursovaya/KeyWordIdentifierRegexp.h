#pragma once
#include "TokenRegexp.h"
#include "KeyWord.h"
#include "Identifier.h"

class KeyWordIdentifierRegexp : public TokenRegexp
{
public:
	KeyWordIdentifierRegexp(Pointer* pointer);
	bool tryAnalize(Token*& token) override;
};

