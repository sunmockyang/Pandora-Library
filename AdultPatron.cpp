#include "AdultPatron.h"

AdultPatron::AdultPatron(Name* name, unsigned int age) : Patron(name, age){

}

int AdultPatron::GetLifetimeCO(){
	int n = lifetimeCO;
	
	Patron* arr[dependents.size()];
	dependents.toArray(arr);

	for (int i = 0; i < dependents.size(); ++i)
	{
		n += arr[i]->GetLifetimeCO();
	}
	return n;
}

bool AdultPatron::MakeDependent(Patron* parent){
	return false; // Adults cannot be dependents
}