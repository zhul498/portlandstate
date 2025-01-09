// Lian Zhu
// CS163 Program 2
// This is the implementation file for the queue class 

// Includes
#include "queue.h"

// Constructor
queue::queue(void)
{
	rear = nullptr;
}

// Destructor
queue::~queue(void)
{
	// empty list
	if (!rear) return;

	q_node * head = rear->next;
	q_node * curr = head;
	// Turn the list into a LLL
	rear->next = nullptr;

	// Destructor for a LLL
	while (curr)
	{
		q_node * next = curr->next;
		delete curr;
		curr = next;
	}
	rear = nullptr;
}

// Enqueue
int queue::enqueue(char * seriesToAdd, int yearToAdd, gameEntry & toRetrieve)
{
	// Allocate memory for the node
	q_node * curr = new q_node;
	if (!curr->entry.copyEntry(toRetrieve)) return 0;

	curr->seriesName = new char[strlen(seriesToAdd) + 1];
	strcpy(curr->seriesName, seriesToAdd);
	curr->year = yearToAdd;
	// Empty list
	if (!rear)
	{
		rear = curr;
		rear->next = rear;
		return 1;
	}
	// Add
	else
	{
		curr->next = rear->next;
		rear->next = curr;
		rear = curr;
		return 1;
	}

	return 0;
}

// Dequeue
int queue::dequeue(void)
{
	// Empty list
	if (!rear) return 0;

	// One item list
	if (rear->next == rear)
	{
		delete rear;
		rear = nullptr;
		return 1;
	}
	// Multiple item list, delete at front
	else
	{
		q_node * toDelete = rear->next;
		q_node * hold = toDelete->next;
		delete toDelete;
		rear->next = hold;
		return 1;
	}

	return 0;	

}

// Peek
int queue::peek(gameEntry & toRetrieve) const
{
	// Empty list
	if (!rear) return 0;
	
	// otherwise peek
	q_node * first = rear->next;
	toRetrieve.copyEntry(first->entry);

	return 1;

}

// Display wrapper
int queue::display(void) const
{
	if (!rear) return 0;
	
	return display(rear);
}

// Display recursive
int queue::display(q_node * rear) const
{
	q_node * curr = rear->next;
	if (curr == this->rear)
	{
		std::cout << "SERIES: " << curr->seriesName << '\n';
		curr->entry.display();
		return 1;
	}

	std::cout << "SERIES: " << curr->seriesName << '\n';
	curr->entry.display();

	return display(rear->next) + 1;

}

