#include "MultipleInitException.h"

MultipleInitException::MultipleInitException(Identifier* identifier) : BaseException("MultipleInitException " + identifier->toString())
{
	_identifier = identifier;
}

Identifier* MultipleInitException::GetIdentifier()
{
	return _identifier;
}