#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book{
	public:
		Book(string, string, int);
		~Book();

		enum bookStatusType {
			CHECKED_IN,
			CHECKED_OUT,
			UNDER_REPAIR,
			LOST
		};
	
		unsigned int id;
		const string title;
		const string author;
		const int year;
		bookStatusType status;

		bool checkIn();
		bool checkOut();
		bool canCheckOut();
		
	private:
		
};

#endif