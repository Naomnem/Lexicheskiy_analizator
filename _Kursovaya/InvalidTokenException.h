#pragma once
#include "BaseException.h"
#include "InvalidToken.h"

class InvalidTokenException : public BaseException
{
private:
	InvalidToken* _token;

public:
	InvalidTokenException(InvalidToken* token);
	InvalidToken* getInvalidToken();

};

