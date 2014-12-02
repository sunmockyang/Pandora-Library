#ifndef PATRONFACTORY_H
#define PATRONFACTORY_H

#include "Patron.h"

class PatronFactory
{
public:
	virtual void createPatron(string firstName, string lastName, int age, Patron** newPatron) = 0;
};

#endif