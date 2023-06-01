#include "IdentifierInfo.h"

IdentifierInfo::IdentifierInfo(Token* typeToken, IdentifierType type)
{
    _typeToken = typeToken;
    _type = type;
}

IdentifierType IdentifierInfo::getType()
{
    return _type;
}

std::string IdentifierInfo::toString()
{
    std::string type;
    if (_type == IdentifierType(0))
    {
        type = "Undefined";
    }
    else if (_type == IdentifierType(1))
    {
        type = "Function";
    }
    else if (_type == IdentifierType(2))
    {
        type = "Class";
    }
    else if (_type == IdentifierType(3))
    {
        type = "Struct";
    }
    else if (_type == IdentifierType(4))
    {
        type = "Variable";
    }
    else
    {
        type = "Error";
    }

    return "Type: " + type + " TypeToken: " + ((_typeToken == nullptr) ? "NULL" : _typeToken->getOriginalString());
}

std::ostream& operator<<(std::ostream& out, IdentifierInfo* info)
{
    out << info->toString();
    return out;
}