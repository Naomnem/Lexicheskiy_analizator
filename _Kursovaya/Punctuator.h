#pragma once
#include "Token.h"
#include <string>
#include <vector>
#include "Pointer.h"

static std::vector<std::string> Punctuators = {
	"[", "]", "(", ")", "{", "}", "#", ".", ",", ";", "::", ":" };

int findPunctuator(std::string string);

class Punctuator : public Token
{
private:
	int _punctuatorId;
	std::string _value;
public:
	Punctuator(int id, const char* startPtr, size_t length);
	std::string toString() override;
	bool isBracket();
	bool isOpenBracket();
	bool isCloseBracket();
	int getPunctuatorId();

};

