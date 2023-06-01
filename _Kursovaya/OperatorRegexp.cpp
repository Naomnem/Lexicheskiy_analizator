#include "OperatorRegexp.h"

OperatorRegexp::OperatorRegexp(Pointer* pointer) :TokenRegexp(pointer)
{ }

bool OperatorRegexp::tryAnalize(Token*& token)
{
	Pointer tempPointer = Pointer(_pointer->getCurrentPtr(), _pointer->getRemainingLength());
	int punctuatorId = findOperator(std::string(tempPointer.getCurrentPtr(), 1));

	if (punctuatorId < 0)
		return false;

	while (tempPointer.moveNext())
	{
		int id = findOperator(std::string(tempPointer.getHeadPtr(), tempPointer.getPassedLength()));
		if (id < 0)
			break;
		punctuatorId = id;
	}
	tempPointer.movePrevious();
	token = new Operator(punctuatorId, tempPointer.getHeadPtr(), tempPointer.getPassedLength());
	_pointer->moveNext(tempPointer.getPassedLength());
	return true;
}