#include "TableOfNames.h"
#include <stack>

TableOfNames::TableOfNames()
{
	_global = new FieldOFView();
	_current = _global;
}

FieldOFView* TableOfNames::getGlobalScale()
{
	return _global;
}

void TableOfNames::linkToken(Identifier* identifier)
{
	std::stack<FieldOFView*> scales;
	scales.push(_current);

	bool isLinked = false;

	while (!scales.empty())
	{
		FieldOFView* scale = scales.top();
		scales.pop();

		std::map<std::string, IdentifierInfo*> scopeIdentifiers = scale->getIdentifiers();
		auto iterator = scopeIdentifiers.find(identifier->getOriginalString());
		if (iterator != scopeIdentifiers.end())
		{
			identifier->LinkToNamesTabel((*iterator).second);
			isLinked = true;
			break;
		}

		if (scale->getParentScale() != nullptr)
			scales.push(scale->getParentScale());
	}

	
}

void TableOfNames::addIdentifier(Identifier* token, IdentifierInfo* info)
{
	_current->addIdentifier(token, info);
}

int TableOfNames::getCurrentInverstmentLevel()
{
	return _current->getInverstmentLevel();
}

void TableOfNames::downScale()
{
	FieldOFView* temp = _current->getParentScale();
	if (temp != nullptr)
		_current = temp;
}

void TableOfNames::upScale()
{
	_current = _current->createChildScale();
}
