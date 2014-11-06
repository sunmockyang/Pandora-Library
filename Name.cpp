#include "Name.h"

Name::Name(std::string first, std::string last) : First(first), Last(last){}

bool Name::compare(Name* name){
	return (name->First == First && name->Last == Last);
}