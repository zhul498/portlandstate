// Lian Zhu
// CS163 Program 2
// This is the implementation file for the stack

// Includes 
#include "stack.h"

// Constructor
stack::stack(void)
{
	head = nullptr;	
	topIndex = 0;
}

// Destructor
stack::~stack(void)
{
	destroy();
}

void stack::destroy()
{
	while (head)
	{
		node * temp = head->next;
		delete [] head->entries;
		delete head;
		head = temp;
	}
}

// Push onto the stack
int stack::push(const gameEntry & toAdd)
{
	// Error handle
	BAD_ENTRY error;
	if (topIndex < 0)
	{
		error.data = topIndex;
		throw error;
	}

	// Empty list or top > MAX
	if (!head || topIndex >= MAX)
	{
		node * newNode = new node;
		newNode->entries = new gameEntry[MAX];
		newNode->next = head;
		head = newNode;
		topIndex = 0;
	}
	head->entries[topIndex].copyEntry(toAdd);
	++topIndex;
	return 1;	
}

// Pop from the stack
int stack::pop(void)
{
	// Error handle
	BAD_ENTRY error;
	if (topIndex < 0)
	{
		error.data = topIndex;
		throw error;
	}
	
	// Empty list
	if (!head) return 0;

	// If top is at the start of an array
	if (topIndex == 0)
	{
		delete [] head->entries;
		node * temp = head->next;
		delete head;
		head = temp;
		temp = nullptr;
		topIndex = MAX - 1;
		return 1;
	}	

	--topIndex;

	return 1;
}

// Look at the top and fill toRetrieve with it
int stack::peek(gameEntry & toRetrieve) const
{
	// Error handle
	BAD_ENTRY error;
	if (topIndex < 0 || !head)
	{
		error.data = topIndex;
		throw error;
	}
	
	// Empty list
	if (!head) return 0;
	
	// if top is 0 we need to retrieve 4 of the next node
	if (topIndex == 0)
	{
		node * next = head->next;
		toRetrieve.copyEntry(next->entries[MAX - 1]);
		return 1;
	}

	// Retrieve
	toRetrieve.copyEntry(head->entries[topIndex - 1]);
	return 1;
}

int stack::display(void) const
{
	// Error handle
	BAD_ENTRY error;
	if (topIndex < 0)
	{
		error.data = topIndex;
		throw error;
	}

	// Empty list
	if (!head) return 0;

	// Display
	int count {0};
	int fakeTop = topIndex;
	node * curr = head;
	while (curr)
	{
		if (curr == head)
		{
			fakeTop = topIndex;
		}

		else
		{
			fakeTop = MAX;
		}

		for (int i = fakeTop - 1; i >= 0; --i)
		{
			curr->entries[i].display();
			++count;
		}

		curr = curr->next;
	}	

	return count;

}

