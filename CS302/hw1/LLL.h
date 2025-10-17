// Lian Zhu
// CS302 Program 1
// LLL.h
// Header file for a LLL class.


#pragma once
using namespace std;
#include "vendors.h"

// Node
class L_Node : public Cuisine
{
	public:
		L_Node(); // Constructor
		L_Node(const Cuisine& ); // arg constructor
		L_Node(const L_Node &); // Copy constructor
		L_Node &operator=(const L_Node &); // Assignment op
		~L_Node(); // Destructor

		void set_next(L_Node* next); // set next
		L_Node* & get_next(); // ->next


	private:
		L_Node* next;
};

// LLL for Cuisine vendors
class LLL 
{
	public:
		LLL(); // Constructor
		LLL(const LLL &); // Copy constructor
		LLL &operator=(const LLL &); // Assignment op
		~LLL(); // Destructor

		int retrieve(L_Node* & toRetrieve, char* groupName);
		/*
			Function to retrieve a node 
			Fills toRetrieve with what cuisine we are looking for
			Returns success/failure
		*/
		int remove(char* groupName);
		/*
			Wrapper function to remove a node	
			groupName is a param
			Returns success/failure
		*/
		int insert(const Cuisine &); 
		/*
			Inserts a node into the LLL
			Takes in a cuisine
			Returns success/failure
		*/
		int displayAll() const;
		/*
			Wrapper to display all nodes
			No params
			Returns num displayed
		*/

	private:
		int retrieve(L_Node* head, L_Node* & toRetrieve, char* groupName);
		int remove(L_Node* & head, char* groupName);
		int displayAll(L_Node* head) const;

		L_Node* head;
		L_Node* tail;

};

