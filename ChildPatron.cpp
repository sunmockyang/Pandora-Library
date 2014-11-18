#include "ChildPatron.h"

ChildPatron::ChildPatron(Name* name, unsigned int age) : Patron(name, age){

}

int ChildPatron::GetLifetimeCO(){
	int n = lifetimeCO;
	for (int i = 0; i < dependents->count(); ++i)
	{
		n += dependents->get(i)->GetLifetimeCO();
	}
	return n;
}