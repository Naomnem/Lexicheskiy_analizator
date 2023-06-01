#pragma once
#include "TokenRegexp.h"
#include <vector>;


class Scanner
{
private:
	Pointer* _pointer;
	std::vector<TokenRegexp*> _scanners;

	bool trySkipSpaces();
	bool trySkipComments();
	bool tryScanInvalidToken(Token*& token);
public:
	Scanner(std::string string);
	Scanner(const char* input, size_t lenght);

	bool tryScan(Token*& token, bool catchInvalidToken);
};

