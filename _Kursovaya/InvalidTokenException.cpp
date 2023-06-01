#include "InvalidTokenException.h"

InvalidTokenException::InvalidTokenException(InvalidToken* token) : BaseException("InvalidTokenException: " + token->toString())
{
	_token = token;
}

InvalidToken* InvalidTokenException::getInvalidToken()
{
	return _token;
}