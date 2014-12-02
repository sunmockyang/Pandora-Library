#include "AdultPatronFactory.h"

void AdultPatronFactory::createPatron(string firstName, string lastName, int age, Patron** newPatron){
	*newPatron = new AdultPatron(new Name(firstName, lastName), age);
}