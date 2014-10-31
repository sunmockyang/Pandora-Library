#include "Patron.h"

class PDeque
{

private:
	class PDequeNode{
		friend class PDeque;

		private:
			Patron* data;
			PDequeNode* next;
	};

public:
	PDeque();

	void push(Patron*);
	void popFront();
	void popBack();
	Patron* front();
	Patron* back();

	~PDeque();

private:
	PDequeNode* head;
};