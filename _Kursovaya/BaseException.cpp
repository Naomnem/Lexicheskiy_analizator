#include "BaseException.h"

BaseException::BaseException(std::string message)
{
	_message = message;
}

std::string BaseException::getMessage()
{
	return _message;
}

std::ostream& operator<<(std::ostream& out, BaseException* exception)
{
	out << exception->getMessage();
	return out;
}