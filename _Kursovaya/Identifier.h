#pragma once
#include "Token.h"
#include "Pointer.h"
#include "IdentifierInfo.h"

class Identifier : public Token
{
private:
	IdentifierInfo* _info;
public:
	Identifier(const char* startPtr, size_t length);
	bool IsType();
	void LinkToNamesTabel(IdentifierInfo* info);
	std::string toString() override;
};

