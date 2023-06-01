#include "Pointer.h"
Pointer::Pointer(const char* headPtr, size_t length)
{
    _headPtr = headPtr;
    _currentPtr = headPtr;
    _length = length;
}

size_t Pointer::getLength()
{
    return _length;
}

size_t Pointer::getRemainingLength()
{
    return _length - getPassedLength();
}

size_t Pointer::getPassedLength()
{
    return _currentPtr - _headPtr;
}

bool Pointer::isReachedEnd()
{
    return _headPtr + _length == _currentPtr;
}

const char* Pointer::getHeadPtr()
{
    return _headPtr;
}

char Pointer::getCurrent()
{
    return *_currentPtr;
}

const char* Pointer::getCurrentPtr()
{
    return _currentPtr;
}

bool Pointer::compareFollowing(std::string string)
{
    if (string.length() > getRemainingLength())
    {
        return false;
    }

    Pointer temp = Pointer(_currentPtr, string.length());;

    for (int i = 0; !temp.isReachedEnd(); i++)
    {
        if (temp.getCurrent() != string[i])
            return false;
        temp.moveNext();
    }

    return true;
}

bool Pointer::moveNext()
{
    if (_currentPtr - _headPtr <= _length)
    {
        _currentPtr++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Pointer::moveNext(size_t length)
{
    for (int i = 0; i < length; i++)
    {
        if (_currentPtr - _headPtr < _length)
        {
            _currentPtr++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool Pointer::movePrevious()
{
    if (_currentPtr > _headPtr)
    {
        _currentPtr--;
        return true;
    }
    else
    {
        return false;
    }
}


bool Pointer::movePrevious(size_t length)
{
    for (int i = 0; i < length; i++)
    {
        if (_currentPtr > _headPtr)
        {
            _currentPtr--;
        }
        else
        {
            return false;
        }
    }
    return true;
}