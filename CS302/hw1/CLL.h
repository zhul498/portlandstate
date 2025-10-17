// Lian Zhu
// CS302 Program 1
// CLL.h
// Header file for a CLL class.

#pragma once
using namespace std;
#include "vendors.h"

// Node
class C_Node : public Entertainer
{
	public:
		C_Node(); // Constructor
		C_Node(const Entertainer &); // Argumentt constructort
		C_Node(const C_Node &); // Copy constructor
		C_Node &operator=(const C_Node &); // Assignment op
		~C_Node(); // destructor
		
		void set_next(C_Node* next); // set next
		C_Node* & get_next(); // ->next
	private:
		C_Node* next;

};


// List for entertainers
class CLL
{
	public:
		CLL(); // Constructor
		CLL(const CLL &); // Copy constructor
		CLL &operator=(const CLL &); // Assignment op
		~CLL(); // Destructor

		
		int retrieve(C_Node* & toRetrieve, char* groupName);
		/*
			Function to retrieve a node 
			Fills toRetrieve with what entertainer we are looking for
			Returns success/failure
		*/
		int remove(char* groupName);
		/*
			Wrapper function to remove a node	
			groupName to remove
			Returns success/failure
		*/
		int insert(const C_Node &); 
		/*
			Inserts a node into the CLL
			Takes in a Node
			Returns success/failure
		*/
		int displayAll() const;
		/*
			Wrapper to display all nodes
			No params
			Returns num displayed
		*/


	private:
		int retrieve(C_Node* curr, C_Node* & toRetrieve, char* groupName, C_Node* head);
		int remove(C_Node* & rear, C_Node* head, char* groupName);
		int displayAll(C_Node* rear, C_Node* head) const; // Recursive
		C_Node* rear;

};
