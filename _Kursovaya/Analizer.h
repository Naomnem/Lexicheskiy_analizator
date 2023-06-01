#pragma once
#include "TableOfNames.h"
#include "Scanner.h"
#include "InvalidTokenException.h"
#include "BracketCounter.h"
#include "InvalidBracketOrderException.h"

class Analizer
{
private:
	TableOfNames* _tabelOfNames;
	std::list<Token*> _tokens;
	Scanner* _scanner;
	BracketCounter* _brackets;
public:
	Analizer(const char* input, size_t lenght);
	void Scan();
	TableOfNames* getTableOfNames();
	std::list<Token*> getTokens();
};

