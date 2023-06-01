#include "KeyWord.h"

KeyWord::KeyWord(int id, const char* startPtr, size_t length) :Token(TypeOfToken::Keywords, startPtr, length)
{
	_keywordId = id;
}

int KeyWord::GetKeywordId()
{
	return _keywordId;
}

bool KeyWord::IsType()
{
	std::string strValue = Token::toString();
	return (strValue == "int") || (strValue == "double")
		|| (strValue == "char") || (strValue == "float");
}

std::string KeyWord::toString()
{
	return "Keyword: " + Token::toString();
}

int KeywordIndex(std::string string)
{
	int i = 0;
	for (std::string keyword : Keywords)
	{
		if (keyword == string)
			return i;
		i++;
	}
	return -1;
}