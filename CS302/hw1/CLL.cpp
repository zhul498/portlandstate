// Lian Zhu
// CS 302 Program 1
// List.cpp
// Implementation file for CLL.h

#include "CLL.h"

// --------------------------- C_Node IMPLEMENTATION -------------------------------- 
C_Node::C_Node() : next(nullptr)
{

}

C_Node::C_Node(const Entertainer & source) : Entertainer(source), next(nullptr)
{

}

C_Node::C_Node(const C_Node & source) : Entertainer(source), next(nullptr)
{
	// deep copy
	if (source.next) next = new C_Node(*source.next);
	else next = nullptr;
}

C_Node& C_Node::operator=(const C_Node & source)
{
	if (this == &source) return *this;
	Entertainer::operator=(source);
	if (next) delete next;
	if (source.next) next = new C_Node(*source.next);
	else next = nullptr;
	return *this;
}

C_Node::~C_Node()
{
	next = nullptr;
}

void C_Node::set_next(C_Node* next)
{
	this->next = next;
}
C_Node* & C_Node::get_next()
{
	return next;
}
// --------------------------- C_Node IMPLEMENTATION -------------------------------- 


// --------------------------- CLL IMPLEMENTATION -------------------------------- 

CLL::CLL() : rear(nullptr)
{
}
CLL::CLL(const CLL & source) : rear(nullptr)
{
	if (!source.rear) return;

	// copy head
	C_Node* currSource = source.rear->get_next(); // head
	C_Node* prevNew = new C_Node(*currSource);
	C_Node* newHead = prevNew;

	currSource = currSource->get_next();
	while (currSource != source.rear->get_next())  // while we dont loop to beginning
	{
		C_Node* newNode = new C_Node(*currSource);
		prevNew->set_next(newNode);
		prevNew = newNode;
		currSource = currSource->get_next();
	}

	prevNew->set_next(newHead);
	this->rear = prevNew;

}
CLL& CLL::operator=(const CLL & source)
{
	if (this == &source) return *this;

	// delete existing
	if (rear)
	{
		C_Node* curr = rear->get_next();
		rear->set_next(nullptr); // turn into lll
		while (curr)
		{
			C_Node* temp = curr->get_next();
			delete curr;
			curr = temp;
		}
		rear = nullptr;
	}
	// basically cc
	if (!source.rear) return *this;

	// copy head
	C_Node* currSource = source.rear->get_next(); // head
	C_Node* prevNew = new C_Node(*currSource);
	C_Node* newHead = prevNew;

	currSource = currSource->get_next();
	while (currSource != source.rear->get_next())  // while we dont loop to beginning
	{
		C_Node* newNode = new C_Node(*currSource);
		prevNew->set_next(newNode);
		prevNew = newNode;
		currSource = currSource->get_next();
	}

	prevNew->set_next(newHead);
	rear = prevNew;
	
	return *this;
}
CLL::~CLL()
{
	if (!rear) return;

	C_Node* head = rear->get_next();
	rear->set_next(nullptr);
	while (head)
	{
		C_Node* temp = head->get_next();
		delete head;
		head = temp;
	}
	rear = nullptr;
}


int CLL::retrieve(C_Node* & toRetrieve, char* groupName)
{
	if (!rear || !groupName) return 0;	
	return retrieve(rear->get_next(), toRetrieve, groupName, rear->get_next());
}
int CLL::retrieve(C_Node* curr, C_Node* & toRetrieve, char* groupName, C_Node* head)
{
	if (!curr) return 0;
	if (curr->compareName(groupName))
	{
		toRetrieve = curr;
		return 1;
	}
	if (curr->get_next() == head) return 0;

	return retrieve(curr->get_next(), toRetrieve, groupName, head);
}


int CLL::remove(char* groupName)
{
	if (!rear || !groupName) return 0;
	// single node
	if (rear == rear->get_next() && rear->compareName(groupName)) 
	{
		delete rear;
		rear = nullptr;
		return 1;
	}
	return remove(rear->get_next(), rear->get_next(), groupName);
}


int CLL::remove(C_Node* & curr, C_Node* head, char* groupName)
{
	if (!curr || !head) return 0;

	// check if (curr->next->data) because we want to be able to connect nodes
	if (curr->get_next()->compareName(groupName)) 
	{
		C_Node* temp = curr->get_next();
		if (temp == rear) rear = curr;
		curr->set_next(temp->get_next());
		delete temp;
		return 1;
	}

	// if full loop
	if (curr->get_next() == head) return 0;

	return remove(curr->get_next(), head, groupName);

}


int CLL::insert(const C_Node & toInsert)
{
	// base case
	if (!rear) 
	{
		rear = new C_Node(toInsert);
		rear->set_next(rear);
		return 1;
	}
	else
	{
		C_Node* newNode = new C_Node(toInsert);
		newNode->set_next(rear->get_next());	
		rear->set_next(newNode);
		rear = newNode;
		return 1;
	}
	return 0;
	
}


int CLL::displayAll() const
{
	if (!rear) return 0;
	// single node
	if (rear == rear->get_next())
	{
		return rear->displayInfo();	
	}
	return displayAll(rear->get_next(), rear->get_next());
}

int CLL::displayAll(C_Node* rear, C_Node* head) const
{
	if (!rear || !head) return 0;
	rear->displayInfo();
	if (rear->get_next() == head) return 1;
	return displayAll(rear->get_next(), head) + 1;
}
// --------------------------- CLL IMPLEMENTATION -------------------------------- 

