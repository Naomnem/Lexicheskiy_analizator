#pragma once
#include <string>
#include <iostream>

class BaseException
{
private:
	std::string _message;
public:
	BaseException(std::string message);
	std::string getMessage();
};

std::ostream& operator<<(std::ostream& out, BaseException* exception);

