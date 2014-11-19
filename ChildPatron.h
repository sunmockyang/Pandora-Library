#ifndef CHILDPATRON_h
#define CHILDPATRON_h

#include "Patron.h"

class ChildPatron : public Patron
{
public:
	ChildPatron(Name*, unsigned int);
	~ChildPatron();

	virtual int GetLifetimeCO();
	virtual bool MakeDependent(Patron*);
};

#endif