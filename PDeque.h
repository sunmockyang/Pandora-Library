#include "Patron.h"

class PDeque
{
public:
	PDeque();

	void push(Patron*);
	void popFront();
	void popBack();
	Patron* front();
	Patron* back();

	~PDeque();
};

class PDequeNode{
	friend class PDeque;

	private:
		Patron* data;
		PDequeNode* next;
};