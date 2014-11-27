#ifndef PLSCONTROL_H
#define PLSCONTROL_H

#include <vector>

#include "Library.h"
#include "Menu.h"
#include "Book.h"
#include "Patron.h"
#include "AdultPatron.h"
#include "ChildPatron.h"
#include "PDeque.h"

class PLSControl
{
public:
	PLSControl();
	~PLSControl();

	void Start();

private:
	Library* library;
	Menu* menu;

	// Admin
	void AdminMode();
	void AddPatron();
	void DeletePatron();

	// Patron
	void PatronMode();
	void CheckInBook(Patron*);
	void CheckOutBook(Patron*);
};

#endif