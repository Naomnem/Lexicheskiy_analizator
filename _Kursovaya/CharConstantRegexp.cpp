#include "CharConstantRegexp.h"

CharConstantRegexp::CharConstantRegexp(Pointer* pointer) : TokenRegexp(pointer)
{ }

bool CharConstantRegexp::tryAnalize(Token*& token)
{
	Pointer tempPointer = Pointer(_pointer->getCurrentPtr(), _pointer->getRemainingLength());
	if (tempPointer.getCurrent() != '\'')
	{
		return false;
	}

	while (tempPointer.moveNext() && tempPointer.getCurrent() != '\'')
	{
		if (tempPointer.getCurrent() == '\\')
			tempPointer.moveNext();

	}

	tempPointer.moveNext();
	token = new CharConstant(_pointer->getCurrentPtr(), tempPointer.getPassedLength());
	_pointer->moveNext(tempPointer.getPassedLength());
	{
		return true;
	}
}