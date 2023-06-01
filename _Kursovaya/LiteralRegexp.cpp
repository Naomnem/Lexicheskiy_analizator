#include "LiteralRegexp.h"

LiteralRegexp::LiteralRegexp(Pointer* pointer) : TokenRegexp(pointer) {};

bool LiteralRegexp::tryAnalize(Token*& token)
{
	Pointer tempPointer = Pointer(_pointer->getCurrentPtr(), _pointer->getRemainingLength());
	if (tempPointer.getCurrent() == '"')
	{
		while (tempPointer.moveNext() && (tempPointer.getCurrent() != '"'))
		{
			if (tempPointer.getCurrent() == '\\')
				tempPointer.moveNext(2);
		}
		tempPointer.moveNext();
		token = new Literal(_pointer->getCurrentPtr(), tempPointer.getPassedLength());
		_pointer->moveNext(tempPointer.getPassedLength());
		return true;
	}
	return false;
}
 