#include "Patron.h"

class PDequeNode;

class PDeque
{

private:

public:
	PDeque();

	Patron* front();
	Patron* back();
	void push(Patron*);
	void popFront();
	void popBack();

	~PDeque();

private:
	PDequeNode* head;
};

class PDequeNode{
	friend class PDeque;

	public:
		~PDequeNode();

	private:
		Patron* data;
		PDequeNode* next;
};