#pragma once
#include <iostream>
#include <string>

enum class TypeOfToken { Invalid, Identifiers, Constants, Keywords, Punctuators, Operator, Literals };

class Token abstract
{
private:
	
	TypeOfToken _typeOfToken;
	const char* _startPtr;
	size_t _length;

public:
	Token(TypeOfToken id, const char* startPtr, size_t length);

	size_t getLength();
	const char* getStartPtr();
	TypeOfToken getTokenType();
	std::string getOriginalString();
	virtual std::string toString() abstract;

};

std::ostream& operator << (std::ostream& out, Token* token);