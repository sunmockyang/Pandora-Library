#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Name.h"
#include "Book.h"
#include "PDeque.h"
#include "BookArray.h"
#include "types.h"

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
		void	programEnd(BookArray*, PDeque*);

		void	printBook(Book*);
		void 	listBooks(BookArray*);
		void 	listPatrons(PDeque*);

		// Assignment 3 prints
		void 	printPatrons(PDeque*);
		void 	printPatronsBack(PDeque*);
		

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
		
		int	enterChoice(string[], int);

		void print(string);
		void println(string);
		void clearScreen();
};

#endif