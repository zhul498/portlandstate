// Lian Zhu
// CS302
// DLL.H 

#pragma once

template <typename T>
class Node
{
	public:
		Node(); // constructor
		Node(const T & ); // arg constructor
		Node(const Node &); // copy constructor
		Node<T> &operator=(const Node<T> &); // assignment operator
		~Node(); // destructor

	protected:
		T data; 
		Node<T>* next;
		Node<T>* previous;
};

template <typename T>
class DLL
{
	public:
		DLL(); // constructor
		DLL(const DLL<T> &); // copy constructor
		DLL &operator=(const DLL<T> &); // assignment op
		~DLL(); // destructor

		
		bool insert(const T& value); 
		bool remove(const T& value); 
		bool retrieve(const T& value, T& result) const; 
		void displayAll() const;
		void clear(); 


	protected:
		void copyList(const DLL<T> & source);
		bool insert(Node<T>* & head, Node<T>* & tail, const T& value); 
		bool remove(Node<T>* & head, const T& value); 
		bool retrieve(Node<T>* & head, const T& value, T& result) const; 
		void displayAll(Node<T>* & head) const;
		void clear(Node<T>* & head); 
		Node<T>* head;
		Node<T>* tail;
};

