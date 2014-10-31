#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Name.h"
#include "Book.h"
#include "PatronArray.h"
#include "DepArray.h"
#include "BookArray.h"

using namespace std;

class Menu
{
	public:
		Menu();
		~Menu();

		int 	MainMenu();
		int 	PatronMenu(Name*);
		int 	AdminMenu();
		void 	ViewCollectionMenu(BookArray*);
		void 	viewPatronBookMenu(Name*, BookArray*);
		void	programEnd(BookArray*, PatronArray*);

		void	printBook(Book*);
		void 	listBooks(BookArray*);
		void 	listPatrons(PatronArray*);
		

		// Input
		Name* 			inputName();
		unsigned int 	inputAge();
		unsigned int 	inputBookID();
		Name*			inputParent();

		// Error
		void ErrorMessage(string);

	private:
		string	scan();
		int		scanInt();
		int		atoi(string*);
		
		int	enterChoice(string, string, string);
		int	enterChoice(string, string, string, string);

		void print(string);
		void println(string);
		void clearScreen();
};

#endif