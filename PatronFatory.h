#ifndef PATRONFACTORY_h
#define PATRONFACTOR_h

#include "Patron.h"

class PatronFatory
{
public:
	PatronFatory();
	~PatronFatory();
	void createPatron(string firstName, string lastName, int age, Patron** newPatron) = 0;
};

#endif