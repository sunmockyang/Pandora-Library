#include "ChildPatron.h"

ChildPatron::ChildPatron(Name* name, unsigned int age) : Patron(name, age){

}

// Technically this function should be same as the
// AdultPatron class since they both can have dependents
int ChildPatron::GetLifetimeCO(){
	int n = lifetimeCO;
	
	Patron* arr[dependents.size()];
	dependents.toArray(arr);

	for (int i = 0; i < dependents.size(); ++i)
	{
		n += arr[i]->GetLifetimeCO();
	}
	return n;
}

bool ChildPatron::MakeDependent(Patron* parent){
	if(parent == NULL) return false;

	// Add dependent
	parent->dependents.add(0, this);
	this->parent = parent;

	return true;
}