#include "FieldOFView.h"

FieldOFView::FieldOFView() : FieldOFView(nullptr){}

FieldOFView::FieldOFView(FieldOFView* parent)
{
	_parent = parent;
	_identifiers = {};
	_childs = {};
	if (parent)
		_investmentLevel = parent->getInverstmentLevel() + 1;
	else
		_investmentLevel = 0;
}

int FieldOFView::getInverstmentLevel()
{
	return _investmentLevel;
}

std::list<FieldOFView*> FieldOFView::getChilds()
{
	return _childs;
}

FieldOFView* FieldOFView::createChildScale()
{
	FieldOFView* child = new FieldOFView(this);
	_childs.push_back(child);
	return child;
}

FieldOFView* FieldOFView::getParentScale()
{
	return _parent;
}

void FieldOFView::addIdentifier(Identifier* identifier, IdentifierInfo* info)
{
	if (_identifiers.count(identifier->getOriginalString()))
		throw new MultipleInitException(identifier);
	_identifiers.insert(std::pair<std::string, IdentifierInfo*>(identifier->getOriginalString(), info));
}

std::map<std::string, IdentifierInfo*> FieldOFView::getIdentifiers()
{
	return _identifiers;
}
