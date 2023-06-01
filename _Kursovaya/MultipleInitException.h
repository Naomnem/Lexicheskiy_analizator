#pragma once
#include "BaseException.h"
#include "Identifier.h"

class MultipleInitException : public BaseException
{
private:
	Identifier* _identifier;
public:
	MultipleInitException(Identifier* identifier);
	Identifier* GetIdentifier();
};

