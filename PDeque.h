#include "Patron.h"

class PDeque
{
public:
	PDeque();
	~PDeque();
};

class PDequeNode{
	friend class PDeque;

	private:
		Patron* data;
		PDequeNode* next;
};