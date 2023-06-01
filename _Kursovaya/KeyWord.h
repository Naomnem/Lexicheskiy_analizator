#pragma once
#include "Token.h"
#include "Pointer.h"
#include<vector>
#include<string>
#include <algorithm>

static std::vector<std::string> Keywords = {
	"#include"      ,
	"#define"       ,
	"#region"       ,
	"class"         ,
	"auto"			,
	"break"			,
	"case"			,
	"char"			,
	"const"			,
	"continue"		,
	"default"		,
	"do"			,
	"double"		,
	"else"			,
	"enum"			,
	"extern"		,
	"float"			,
	"for"			,
	"goto"			,
	"if"			,
	"inline"		,
	"int"			,
	"long"			,
	"register"		,
	"restrict"		,
	"return"		,
	"short"			,
	"signed"		,
	"sizeof"		,
	"static"		,
	"struct"		,
	"switch"		,
	"typedef"		,
	"union"			,
	"unsigned"		,
	"void"			,
	"volatile"		,
	"while"			,
};

int KeywordIndex(std::string string);

class KeyWord : public Token
{
private:
	int _keywordId;
public:
	KeyWord(int id, const char* startPtr, size_t length);
	int GetKeywordId();
	bool IsType();
	std::string toString() override;
};

