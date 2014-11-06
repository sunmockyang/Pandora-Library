#ifndef NAME_H
#define NAME_H

#include <string>

class Name
{
public:
	Name(std::string first, std::string last);

	std::string First, Last;

	bool compare(Name*);
};

#endif