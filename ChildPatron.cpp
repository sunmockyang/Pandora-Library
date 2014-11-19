#include "ChildPatron.h"

ChildPatron::ChildPatron(Name* name, unsigned int age) : Patron(name, age){

}

// Technically this function should be same as the
// AdultPatron class since they both can have dependents
int ChildPatron::GetLifetimeCO(){
	int n = lifetimeCO;
	for (int i = 0; i < dependents->count(); ++i)
	{
		n += dependents->get(i)->GetLifetimeCO();
	}
	return n;
}

bool ChildPatron::MakeDependent(Patron* parent){
	if(parent == NULL) return false;

	// Add dependent
	parent->dependents->push(this);
	this->parent = parent;

	return true;
}