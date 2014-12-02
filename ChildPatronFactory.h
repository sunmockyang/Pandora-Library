#ifndef CHILDPATRONFACTORY_H
#define CHILDPATRONFACTORY_H
#include "PatronFactory.h"
#include "ChildPatron.h"

class ChildPatronFactory
{
public:
	virtual void createPatron(string firstName, string lastName, int age, Patron** newPatron);
};

#endif