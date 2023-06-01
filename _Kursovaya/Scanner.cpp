#include "Scanner.h"
#include "CharConstantRegexp.h"
#include "NumConstantRegexp.h"
#include "LiteralRegexp.h"
#include "OperatorRegexp.h"
#include "PunctuatorRegexp.h"
#include "KeyWordIdentifierRegexp.h"
#include "InvalidToken.h"
#include <vector>

Scanner::Scanner(std::string string) : Scanner(string.c_str(), string.length())
{ }

Scanner::Scanner(const char* input, size_t length)
{
	_pointer = new Pointer(input, length);
	_scanners = std::vector<TokenRegexp*>{
		new OperatorRegexp(_pointer),
		new PunctuatorRegexp(_pointer),
		new CharConstantRegexp(_pointer),
		new NumConstantRegexp(_pointer),
		new LiteralRegexp(_pointer),
		new KeyWordIdentifierRegexp(_pointer),
	};
}

bool IsSpace(char symbol)
{
	return (symbol == ' ') || (symbol == '\t') || (symbol == '\n')
		|| symbol == ('\v') || (symbol == '\f') || (symbol == '\r');
}

bool Scanner::trySkipSpaces()
{
	bool anySpace = IsSpace(_pointer->getCurrent());
	while (IsSpace(_pointer->getCurrent()) && _pointer->moveNext())
	{
	}
	return anySpace;
}

bool Scanner::trySkipComments()
{
	if (_pointer->compareFollowing("/*"))
	{
		while (_pointer->moveNext() && !_pointer->compareFollowing("*/"))
		{
		}
		_pointer->moveNext(2);
		return true;
	}
	else if (_pointer->compareFollowing("//"))
	{
		while (_pointer->moveNext() && _pointer->getCurrent() != '\n')
		{
		}
		_pointer->moveNext();
		return true;
	}
	return false;
}

bool Scanner::tryScanInvalidToken(Token*& token)
{
	bool isReachedEnd = _pointer->isReachedEnd();
	if (!isReachedEnd)
	{
		size_t currentPoint = _pointer->getPassedLength();
		size_t lastPoint = currentPoint;
		while (!tryScan(token, false) && !isReachedEnd)
		{
			_pointer->moveNext();
			lastPoint = _pointer->getPassedLength();
			isReachedEnd = _pointer->isReachedEnd();
		}

		token = new InvalidToken(_pointer->getHeadPtr() + currentPoint, lastPoint - currentPoint, "An indefinite Token.");
		if (!isReachedEnd)
			_pointer->movePrevious(_pointer->getPassedLength() - lastPoint);
		return true;
	}
	return false;
}


/// ¬ случае успешного поиска, проинициализирует токен новым значением
/// true - если поиск был успешен, false если иначе

bool Scanner::tryScan(Token*& token, bool catchInvalidToken)
{
	while (true)
	{
		//ѕодгон€ем к строке с кодом убира€ табы и прочее
		trySkipSpaces();
		if (trySkipComments())
			continue;

		//ѕытаемс€ запарсить различные виды лексем
		for (TokenRegexp* parser : _scanners)
		{
			if (parser->tryAnalize(token))
				return true;
		}

		//≈сли пройд€ через все фильтры, мы не нашли лексему, значит лексема имела неверный формат
		if (catchInvalidToken && tryScanInvalidToken(token))
			return true;

		return false;
	}
}