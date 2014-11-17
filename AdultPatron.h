#ifndef ADULTPATRON_h
#define ADULTPATRON_h

#include "Patron.h"

class AdultPatron : public Patron
{
public:
	AdultPatron(Name*, unsigned int);
	~AdultPatron();
};

#endif