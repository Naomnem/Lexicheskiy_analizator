#pragma once
#include "FieldOFView.h"

class TableOfNames
{
private:
	FieldOFView* _global;
	FieldOFView* _current;
public:
	TableOfNames();
	FieldOFView* getGlobalScale ();
	void linkToken(Identifier* identifier);
	void addIdentifier(Identifier* identifier, IdentifierInfo* info);
	int getCurrentInverstmentLevel();
	void upScale();
	void downScale();
};

