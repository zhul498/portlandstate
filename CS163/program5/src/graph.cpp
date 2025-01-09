// Lian Zhu
// CS163 Program 5
// This is the implementation file for the adjacency list

// Includes
#include "graph.h"

// Using
using namespace std;

// Constructor
table::table(int size)
{
	adjacency_list = new vertex[size];
	for (int i {0}; i < size; ++i)
	{
		adjacency_list[i].entry = nullptr;
		adjacency_list[i].head = nullptr;
	}
	list_size = size;
}

// Destructor
table::~table(void)
{
	destroy();
}

// Destroy 
int table::destroy(void)
{
	for (int i {0}; i < list_size; ++i)
	{
		if (adjacency_list[i].head)
		{
			delete adjacency_list[i].entry;		
			delete adjacency_list[i].head;
		}
	}
	return 1;
}

// Insert vertex
int table::insert_vertex(const geocache & to_add)
{
	for (int i {0}; i < list_size; ++i)
	{
		if (!adjacency_list[i].entry)
		{
			geocache * temp = new geocache;
			temp->copy_entry(to_add);
			adjacency_list[i].entry = temp;
			return 1;
		}
	}
	return 0;
}

// Find a location
int table::find_location(string key) 
{
	for (int i {0}; i < list_size; ++i)
	{
		if (adjacency_list[i].entry->compare_location(key)) return i;
	}
	return -1;
}

// Insert edge
int table::insert_edge(string current_vertex, string to_attach, float distance_add)
{
	int current_index = find_location(current_vertex);
	int attach_index = find_location(to_attach);

	node * temp = new node;
	temp->distance = distance_add;
	temp->adjacent = &adjacency_list[attach_index];
	temp->next = adjacency_list[current_index].head;
	adjacency_list[current_index].head = temp;
	return 1;
}

// Display all adjacent vertices to key
int table::display_adjacent(string key)
{
	int index = find_location(key);
	if (index == -1) return 0;

	node * curr = adjacency_list[index].head;
	while (curr)
	{
		curr->adjacent->entry->display();
		cout << "Distance between: " << curr->distance << " miles\n";
		curr = curr->next;
	}
	return 1;

}

// Display all
int table::display_all(void) const
{
	int count {0};
	for (int i {0}; i < list_size; ++i)
	{
		if (adjacency_list[i].entry)
		{
			cout << "Vertex: " << adjacency_list[i].entry->display(); 
			++count;
		}
	}
	return count;
}

// BFS wrapper
/*
int table::bfs(string key)
{
	vector<bool> visited(list_size, false); // vector of bools for visited flags of size list, all initialized to false
	int start = find_location(key);
	if (start == -1) return 0;
	return bfs(start, visited);
}

// BFS Recursive
int table::bfs(int index, vector<bool> & visited)
{
	if (visited[index]) return 0;
	visited[index] = true;
	int count {1};

	// Traverse connected and BFS through neighbors
	node * curr = adjacency_list[index].head;
	while (curr)
	{
		int adjacent_index = find_location(curr->adjacent->entry->location);
		count += bfs(adjacent_index, visited);
		curr = curr->next;
	}
	return count;
}
*/

