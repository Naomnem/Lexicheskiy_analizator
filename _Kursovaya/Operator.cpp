#include "Operator.h"

Operator::Operator(int operatorId, const char* startPtr, size_t length) : Token(TypeOfToken::Operator, startPtr, length)
{
	_operatorId = operatorId;
}

std::string Operator::toString()
{
	return "Operator: " + Token::toString();
}

int findOperator(std::string string)
{
	int i = 0;
	for (std::string _operator : Operators)
	{
		if (_operator == string)
			return i;
		i++;
	}
	return -1;
}