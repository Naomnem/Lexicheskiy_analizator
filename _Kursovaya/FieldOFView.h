#pragma once
#include <map>
#include <list>
#include "IdentifierInfo.h"
#include "Identifier.h"
#include "MultipleInitException.h"

class FieldOFView
{
private:
	FieldOFView* _parent;
	std::map<std::string, IdentifierInfo*> _identifiers;
	std::list<FieldOFView*> _childs;
	int _investmentLevel;
public:

	FieldOFView();
	FieldOFView(FieldOFView* parent);
	int getInverstmentLevel();
	std::list<FieldOFView*> getChilds();
	FieldOFView* createChildScale ();
	FieldOFView* getParentScale();
	void addIdentifier(Identifier*, IdentifierInfo*);
	std::map<std::string, IdentifierInfo*> getIdentifiers();
};

