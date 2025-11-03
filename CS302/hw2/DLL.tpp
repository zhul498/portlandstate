// Lian Zhu
// CS302
// DLL.tpp

#include <iostream>
using namespace std;
// constructor
template<typename T>
Node<T>::Node() : next(nullptr), prev(nullptr) {}

// arg constructor
template<typename T>
Node<T>::Node(const T & src) : data(src), next(nullptr), prev(nullptr) {}

// copy constructor
template<typename T>
Node<T>::Node(const Node<T> & src) : data(src.data), next(nullptr), prev(nullptr) {}

// destructor
template<typename T>
Node<T>::~Node()
{
	if (next) next = nullptr;
	if (prev) prev = nullptr;
}

// get_next
template<typename T>
Node<T>* & Node<T>::get_next() 
{ 
	return next;
}

// get_prev
template<typename T>
Node<T>* & Node<T>::get_prev()
{
	return prev;
}

// get data
template<typename T>
T & Node<T>::get_data()
{
	return data;
}


// set next
template<typename T>
void Node<T>::set_next(node_ptr & nextNode)
{
	this->next = nextNode;
}

// set prev
template<typename T>
void Node<T>::set_prev(node_ptr & prevNode)
{
	this->prev = prevNode;
}

// display the node
template<typename T>
void Node<T>::display() const
{
	cout << "\n" << data << "\n";
}


// DLL Constructor
template<typename T>
DLL<T>::DLL() : head(nullptr), tail(nullptr) {}

// Destructor
template<typename T>
DLL<T>::~DLL()
{
	if (head) 
	{
		clear(head);
	}
}

// clear list
template<typename T>
void DLL<T>::clear()
{
	if (!head) return;
	return clear(head);
}

// recursive clear list
template<typename T>
void DLL<T>::clear(node_ptr & curr)
{
	if (!curr) return;
	node_ptr temp = curr->get_next();
	delete curr;
	curr = temp;
	clear(curr);
}

// wrapper copylist
template<typename T>
void DLL<T>::copyList(const DLL & source)
{
	if (!source || !source.head || !source.tail)
	{
		head = tail = nullptr;	
		return;
	}
	copyList(head, source.head);
}

// recursive copylist
template<typename T>
void DLL<T>::copyList(node_ptr & curr,  node_ptr & source)
{
	if (!source) return;
	node_ptr newNode = new Node<T>(source->get_data());
	
	// last node
	if (!source->get_next())
	{
		tail = curr;
		curr->set_next(nullptr);
		return;
	}
	
	copyList(curr->get_next(), source->get_next());
	
	// set previouses on the way back
	if (curr->get_next())
	{
		node_ptr next = curr->get_next();
		next->set_prev(curr);
	}

}

// wrapper insert
template<typename T>
bool DLL<T>::insert(const T& data)
{
	return insert(head, data);
}

// recursive insert
template<typename T>
bool DLL<T>::insert(node_ptr & head, const T& data)
{
	node_ptr temp = new Node<T>(data);
	// no node
	if (!head) 
	{
		head = tail = temp;
		return true;
	}
	// just insert at tail
	else
	{
		tail->set_next(temp);
		temp->set_prev(tail);
		tail = temp;
		return true;
	}

	return false;
}

// wrapper remove
template<typename T>
bool DLL<T>::remove(const T & data)
{
	return remove(head, data);
}

// recursive remove
template<typename T>
bool DLL<T>::remove(node_ptr& curr, const T& data)
{
	if (!curr) return false;
	if (curr->get_data() == data)
	{
		// if head
		if (curr == this->head)
		{
			head = curr->get_next();
			if (head)
			{
				node_ptr nullNode = nullptr;
				head->set_prev(nullNode);
			}
			delete curr;
			curr = nullptr;
			return true;
		}
		// if tail
		if (curr == this->tail)
		{
			tail = curr->get_prev();
			if (tail)
			{
				node_ptr nullNode = nullptr;
				tail->set_next(nullNode);
			}
			delete curr;
			curr = nullptr;
			return true;
		}
		// otherwise attach properly
		node_ptr prev = curr->get_prev();
		node_ptr next = curr->get_next();
		prev->set_next(next);
		next->set_prev(prev);
		delete curr;
		curr = nullptr;
		return true;
	}
	return remove(curr->get_next(), data);
}

// wrapper retrieve
template<typename T>
bool DLL<T>::retrieve(const T& data, T& result) const
{
	return retrieve(head, data, result);
}

// recursive retrieve
template<typename T>
bool DLL<T>::retrieve(const node_ptr & curr, const T& data, T& result) const
{
	if (!curr) return false;
	if (curr->get_data() == data)
	{
		result = curr->get_data();
		return true;
	}
	return retrieve(curr->get_next(), data, result);
}

// wrapper display
template<typename T>
void DLL<T>::displayAll() const
{
	if (!head || !tail) return;
	displayAll(head);
}

// recursive display
template<typename T>
void DLL<T>::displayAll(const node_ptr & curr) const
{
	if (!curr) return;
	curr->display();
	displayAll(curr->get_next());
}
