#pragma once
#include "Token.h"
class InvalidToken : public Token
{
private:
	std::string _reason;
public:
	InvalidToken(const char* startPtr, size_t length);
	InvalidToken(const char* startPtr, size_t length, std::string reason);
	std::string toString() override;
};

