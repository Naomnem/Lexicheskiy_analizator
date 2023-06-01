#include "PunctuatorRegexp.h"

PunctuatorRegexp::PunctuatorRegexp(Pointer* pointer) : TokenRegexp(pointer){}

bool PunctuatorRegexp::tryAnalize(Token*& token)
{
	Pointer tempPointer = Pointer(_pointer->getCurrentPtr(), _pointer->getRemainingLength());
	int punctuatorId = findPunctuator(std::string(tempPointer.getCurrentPtr(), 1));

	if (punctuatorId < 0)
		return false;

	while (tempPointer.moveNext())
	{
		int id = findPunctuator(std::string(tempPointer.getHeadPtr(), tempPointer.getPassedLength()));
		if (id < 0)
			break;
		punctuatorId = id;
	}
	tempPointer.movePrevious();
	token = new Punctuator(punctuatorId, tempPointer.getHeadPtr(), tempPointer.getPassedLength());
	_pointer->moveNext(tempPointer.getPassedLength());
	return true;
}