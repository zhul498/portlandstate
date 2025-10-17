// Lian Zhu
// LS 302 Program 1
// List.cpp
// Implementation file for LLL.h

#include "LLL.h"

// --------------------------- L_Node IMPLEMENTATION -------------------------------- 
L_Node::L_Node() : next(nullptr)
{

}
L_Node::L_Node(const Cuisine & source) : Cuisine(source), next(nullptr)
{

}

L_Node::L_Node(const L_Node & source) : Cuisine(source), next(nullptr)
{
	// deep copy
	if (source.next) next = new L_Node(*source.next);
	else next = nullptr;
}

L_Node& L_Node::operator=(const L_Node & source)
{
	if (this == &source) return *this;
	Cuisine::operator=(source);
	if (next) delete next;
	if (source.next) next = new L_Node(*source.next);
	else next = nullptr;
	return *this;

}

L_Node::~L_Node()
{
	delete next;
	next = nullptr;
}
void L_Node::set_next(L_Node* next)
{
	this->next = next;
}
L_Node* & L_Node::get_next()
{
	return next;	
}
// --------------------------- L_Node IMPLEMENTATION -------------------------------- 


// --------------------------- LLL IMPLEMENTATION -------------------------------- 

LLL::LLL() : head(nullptr), tail(nullptr)
{
}
LLL::LLL(const LLL & source) : head(nullptr), tail(nullptr)
{
	if (!source.head) return;
	head = new L_Node(*source.head);
	tail = head;
	while (tail->get_next()) tail = tail->get_next();

}
LLL& LLL::operator=(const LLL & source)
{
	if (this == &source) return *this;
	L_Node* curr = head;
	while (curr)
	{
		L_Node* temp = curr;
		delete curr;
		curr = temp;
	}
	head = tail = nullptr;

	if (source.head) 
	{
		head = new L_Node(*source.head);
		tail = head;
		while (tail->get_next()) tail = tail->get_next();
	}
	return *this;
}
LLL::~LLL()
{
	L_Node* curr = head;
	while (curr)
	{
		L_Node* temp = curr->get_next();
		delete curr;
		curr = temp;
	}
	head = tail = nullptr;
}

int LLL::retrieve(L_Node* & toRetrieve, char* groupName)
{
    if (!groupName || !head) return 0;
    return retrieve(head, toRetrieve, groupName);
}

int LLL::retrieve(L_Node* head, L_Node* & toRetrieve, char* groupName)
{
    if (!head) return 0;
    if (head->compareName(groupName))
    {
        toRetrieve = head;
        return 1;
    }
    return retrieve(head->get_next(), toRetrieve, groupName);
}

int LLL::remove(char* groupName)
{
	if (!head) return 0;
	return remove(head, groupName);
}
int LLL::remove(L_Node* & head, char* groupName)
{
	if (!head) return 0;
	if (head->compareName(groupName))
	{
		L_Node* temp = head;
		head = head->get_next();
		delete temp;
		if (!head) tail = nullptr;
		return 1;
	}
	int removed = remove(head->get_next(), groupName);

	if (!head->get_next()) tail = head;
	return removed;
}
int LLL::insert(const Cuisine& toAdd)
{
	L_Node* newNode = new L_Node(toAdd);
	if (!head)
	{
		head = tail = newNode;
		return 1;
	}
	tail->set_next(newNode);
	tail = newNode;
	return 1;
}

int LLL::displayAll() const
{
	if (!head) return 0;
	return displayAll(head);
}
int LLL::displayAll(L_Node* head) const
{
	if (!head) return 0;
	head->displayItems();
	return displayAll(head->get_next()) + 1;
}
// --------------------------- LLL IMPLEMENTATION -------------------------------- 
