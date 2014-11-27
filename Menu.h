#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "Name.h"
#include "Book.h"
#include "PDeque.h"

using namespace std;

class Menu
{
	public:
		Menu();
		~Menu();

		int 	MainMenu();
		int 	PatronMenu(Name*);
		int 	AdminMenu();
		void 	ViewCollectionMenu(vector<Book*>*);
		void 	viewPatronBookMenu(Name*, vector<Book*>*);
		void	programEnd(vector<Book*>*, PDeque*);

		void	printBook(Book*);
		void 	listBooks(vector<Book*>*);
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