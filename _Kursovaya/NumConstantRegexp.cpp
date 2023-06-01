#include "NumConstantRegexp.h"
#include "InvalidToken.h"

NumConstantRegexp::NumConstantRegexp(Pointer* pointer) : TokenRegexp(pointer) {};

bool isDigit(char symbol, NumberSystem numberSystem)
{
	if (numberSystem == NumberSystem::Hex)
		if ('a' <= tolower(symbol) && tolower(symbol) <= 'f')
			return true;
	return int('0') <= int(symbol) && int(symbol) <= int('9');
}

bool NumConstantRegexp::tryAnalize(Token*& token)
{
	NumberSystem numberSystem = NumberSystem::Decimal;
	Pointer tempPointer = Pointer(_pointer->getCurrentPtr(), _pointer->getRemainingLength());
	if (!isDigit(tempPointer.getCurrent(), numberSystem))
	{
		return false;
	}

	//Будет подсчёт количества точек
	int dots = 0;

	//Проверка префикса
	if (tempPointer.getCurrent() == '0')
	{
		numberSystem = NumberSystem::Octal;
		tempPointer.moveNext();
		switch (std::tolower((tempPointer.getCurrent())))
		{
		case 'x':
			numberSystem = NumberSystem::Hex;
			tempPointer.moveNext();
			break;
		case 'b':
			numberSystem = NumberSystem::Binary;
			tempPointer.moveNext();
			break;
		default:
			break;
		}
	}


	//Анализ числа

	while (true)
	{
		if (!tempPointer.moveNext())
			break;

		if (isDigit(tempPointer.getCurrent(), numberSystem))
			continue;

		if (tempPointer.getCurrent() == '.')
		{
			dots++;
			continue;
		}
		break;
	}

	//Проверка постфикса
	switch (std::tolower(tempPointer.getCurrent()))
	{
	case 'f':
	case 'l':
	case 'u':
		tempPointer.moveNext();
		break;
	default:
		break;
	}
	//проверка на long long  
	if (tempPointer.getCurrent() == 'l')
		tempPointer.moveNext();

	if (dots < 1)
	{
		token = new IntegerConstant(_pointer->getCurrentPtr(), tempPointer.getPassedLength(), numberSystem);
		_pointer->moveNext(tempPointer.getPassedLength());
		return true;
	}

	if (dots > 1 || numberSystem != NumberSystem::Decimal)
	{

		token = new InvalidToken(_pointer->getCurrentPtr(), tempPointer.getPassedLength(), "Invalid floating-point constant");
		_pointer->moveNext(tempPointer.getPassedLength());
		return true;
	}

	token = new FloatConstant(_pointer->getCurrentPtr(), tempPointer.getPassedLength());
	_pointer->moveNext(tempPointer.getPassedLength());

	return true;
}