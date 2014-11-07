#ifndef PDEQUE_H
#define PDEQUE_H

#include "Patron.h"

class Patron;
class PDequeNode;
class PDeque
{

private:

public:
	PDeque();

	int count();
	bool contains(Patron*);
	// bool canAdd();

	Patron* front();
	Patron* back();
	Patron* get(int);
	Patron* get(Name*);
	Patron* set(Patron*);

	void push(Patron*);
	void popFront();
	void popBack();

	Patron* remove(int);
	Patron* remove(Patron*);
	void clear();

	void update(Patron*);

	~PDeque();

private:
	int n;
	PDequeNode* head;

	// Helpers
	PDequeNode* findNode(int);
	PDequeNode* findNode(Name*);
	PDequeNode* findNode(Patron*);
	PDequeNode* findPrevNode(Patron*);
	void		insertNode(PDequeNode*);
};

class PDequeNode{
	friend class PDeque;

	public:
		PDequeNode();
		~PDequeNode();

	private:
		Patron* data;
		PDequeNode* next;
};

#endif