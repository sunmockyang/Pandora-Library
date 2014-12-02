#ifndef ADULTPATRONFACTORY_H
#define ADULTPATRONFACTORY_H

#include "PatronFactory.h"
#include "AdultPatron.h"

class AdultPatronFactory : public PatronFactory
{
public:
	virtual void createPatron(string firstName, string lastName, int age, Patron** newPatron);
};

#endif