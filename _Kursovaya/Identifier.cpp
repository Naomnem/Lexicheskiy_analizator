#include "Identifier.h"

Identifier::Identifier(const char* startPtr, size_t length) : Token(TypeOfToken::Identifiers, startPtr, length)
{
	_info = nullptr;
}

bool Identifier::IsType()
{
	if (_info == nullptr)
		return false;
	return _info->getType() == IdentifierType::Class || _info->getType() == IdentifierType::Struct;
}

void Identifier::LinkToNamesTabel(IdentifierInfo* info)
{
	_info = info;
}

std::string Identifier::toString()
{
	return "Identifier: " + Token::toString();
}