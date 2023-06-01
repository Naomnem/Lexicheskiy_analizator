#pragma once
#include <string>


class Pointer
{
private:
	const char* _headPtr;
	const char* _currentPtr;
	size_t _length;

public:
	Pointer(const char* headPtr, size_t length);

	size_t getLength();
	size_t getRemainingLength();
	size_t getPassedLength();

	bool isReachedEnd();

	char getCurrent();
	const char* getHeadPtr();
	const char* getCurrentPtr();

	bool compareFollowing(std::string string);

	bool moveNext();
	bool moveNext(size_t length);
	bool movePrevious();
	bool movePrevious(size_t length);
};

