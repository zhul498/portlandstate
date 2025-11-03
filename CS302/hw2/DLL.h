// Lian Zhu
// CS302
// DLL.H 

#pragma once
template <typename T>
class Node
{
	public:
		typedef Node<T>* node_ptr;
		
		Node<T>(); // constructor
		Node<T>(const T & ); // arg constructor
		Node<T>(const Node<T> & src); // copy constructor
		~Node(); // destructor

		// getters
		node_ptr & get_next();
		node_ptr & get_prev();
		T & get_data();

		// setters
		void set_next(node_ptr & nextNode);
		void set_prev(node_ptr & prevNode); 
		
		// funcs
		void display() const;

	protected:
		T data; 
		node_ptr next;
		node_ptr prev;
};

template <typename T>
class DLL
{
	public:
		typedef Node<T>* node_ptr;


		DLL(); // constructor
		DLL(const DLL &); // copy constructor
		DLL &operator=(const DLL &); // assignment op
		~DLL(); // destructor

		void clear(); 
		void copyList(const DLL & source);		
		bool insert(const T& data); 
		bool remove(const T& data); 
		bool retrieve(const T& data, T& result) const; 
		void displayAll() const;


	protected:
		void clear(node_ptr & head); 
		void copyList(node_ptr & head, node_ptr & source);
		bool insert(node_ptr & head, const T& data); 
		bool remove(node_ptr & head, const T& data); 
		bool retrieve(const node_ptr & head, const T& data, T& result) const; 
		void displayAll(const node_ptr & head) const;

		node_ptr head;
		node_ptr tail;
};

#include "DLL.tpp"
