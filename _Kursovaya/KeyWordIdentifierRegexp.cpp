#include "KeyWordIdentifierRegexp.h"

KeyWordIdentifierRegexp::KeyWordIdentifierRegexp(Pointer* pointer) : TokenRegexp(pointer) {}

bool isFirstAllowedCharacter(char symbol)
{
	return (symbol >= '@' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z') || symbol == '_';
}

bool isSubsequentAllowedCharacter(char symbol)
{
	return (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z') || symbol == '_' || isdigit(symbol);
}

bool KeyWordIdentifierRegexp::tryAnalize(Token*& token)
{
	Pointer tempPointer = Pointer(_pointer->getCurrentPtr(), _pointer->getRemainingLength());
	if (!isFirstAllowedCharacter(tempPointer.getCurrent()))
		return false;

	while (tempPointer.moveNext() && isSubsequentAllowedCharacter(tempPointer.getCurrent()))
	{
	}

	int keywordIndex = KeywordIndex(std::string(_pointer->getCurrentPtr(), tempPointer.getPassedLength()));

	if (keywordIndex < 0)
		token = new Identifier(_pointer->getCurrentPtr(), tempPointer.getPassedLength());
	else
		token = new KeyWord(keywordIndex, _pointer->getCurrentPtr(), tempPointer.getPassedLength());

	_pointer->moveNext(tempPointer.getPassedLength());
	return true;
}