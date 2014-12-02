#ifndef PATRONFACTORY_H
#define PATRONFACTORY_H

#include "Patron.h"

class PatronFatory
{
public:
	virtual void createPatron(string firstName, string lastName, int age, Patron** newPatron) = 0;
};

#endif