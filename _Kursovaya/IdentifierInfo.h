#pragma once
#include "Token.h"

enum class IdentifierType
{
	Undefined,
	Function,
	Class,
	Struct,
	Variable,
};

class IdentifierInfo
{
private:
	IdentifierType _type;
	Token* _typeToken;
public:
	IdentifierInfo(Token* typeToken, IdentifierType type);
	IdentifierType getType();
	std::string toString();
};

std::ostream& operator<<(std::ostream& out, IdentifierInfo* info);

