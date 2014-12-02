#include "ChildPatronFactory.h"

void ChildPatronFactory::createPatron(string firstName, string lastName, int age, Patron** newPatron){
	*newPatron = new ChildPatron(new Name(firstName, lastName), age);
}