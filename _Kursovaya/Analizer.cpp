#include "Analizer.h"
#include "KeyWord.h"
#include "Punctuator.h"


std::list<Token*> Analizer::getTokens()
{
	return _tokens;
}

TableOfNames* Analizer::getTableOfNames()
{
	return _tabelOfNames;
}

Analizer::Analizer(const char* input, size_t lenght)
{
	_tabelOfNames = new TableOfNames;
	_tokens = {};
	_scanner = new Scanner(input , lenght);
	_brackets = new BracketCounter();
}
void Analizer::Scan()
{
	Token* token;
	while (_scanner->tryScan(token, true))
	{
		TypeOfToken type = token->getTokenType();
		if (type == TypeOfToken::Invalid)
			throw new InvalidTokenException(dynamic_cast<InvalidToken*>(token));
		_tokens.push_back(token);
	}

	Token* typeToken = nullptr;
	IdentifierType identifierType = IdentifierType::Undefined;
	bool isKeywordContext = false;

	for (auto iterator = _tokens.begin(); iterator != _tokens.end(); iterator++)
	{
		token = *iterator;
		TypeOfToken type = token->getTokenType();

		if (type == TypeOfToken::Keywords)
		{
			KeyWord* keyword = dynamic_cast<KeyWord*>(token);
			if (keyword->IsType())
			{
				typeToken = keyword;
				identifierType = IdentifierType::Variable;
				continue;
			}
			std::string origignalString = keyword->getOriginalString();
			if (origignalString == "class")
			{
				typeToken = keyword;
				identifierType = IdentifierType::Class;
				continue;
			}
			if (origignalString == "struct")
			{
				typeToken = keyword;
				identifierType = IdentifierType::Struct;
				continue;
			}

			if (origignalString == "if" || origignalString == "for" || origignalString == "while")
				isKeywordContext = true;

		}

		if (type == TypeOfToken::Identifiers)
		{
			Identifier* identifier = dynamic_cast<Identifier*>(token);
			if (typeToken == nullptr)
			{
				_tabelOfNames->linkToken(identifier);
				if (identifier->IsType())
				{
					typeToken = identifier;
					identifierType = IdentifierType::Variable;
				}
				continue;
			}

			if (identifierType == IdentifierType::Variable)
			{
				Token* nextToken = *(++iterator);
				iterator--;

				if (nextToken != nullptr && nextToken->getOriginalString() == "(")
				{
					identifierType = IdentifierType::Function;
				}
			}
			IdentifierInfo* info = new IdentifierInfo(typeToken, identifierType);
			_tabelOfNames->addIdentifier(dynamic_cast<Identifier*>(token), info);
			continue;
		}

		if (token->getOriginalString() != ",")
		{
			typeToken = nullptr;
			identifierType = IdentifierType::Undefined;
		}

		if (type == TypeOfToken::Punctuators)
		{
			Punctuator* punctuator = dynamic_cast<Punctuator*>(token);

			if (!punctuator->isBracket())
				continue;

			_brackets->addCount(punctuator);

			if (_brackets->getDepth() + isKeywordContext > _tabelOfNames->getCurrentInverstmentLevel())
				_tabelOfNames->upScale();
			else if (_brackets->getDepth() < _tabelOfNames->getCurrentInverstmentLevel())
				_tabelOfNames->downScale();
			isKeywordContext = false;
			continue;
		}

	}

	if (_brackets->getDepth() != 0)
		throw new InvalidBracketOrderException();
}
