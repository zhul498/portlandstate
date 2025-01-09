// Lian Zhu
// CS163 Program 5
// This is the header file for the adjacency list/graph

#include "geocache.h"

// ************************* VERTEX STRUCT ***********************
struct vertex
{
	geocache * entry;
	struct node * head;
};
// ************************* VERTEX STRUCT ***********************



// ************************* EDGE STRUCT *************************
struct node 
{
	vertex * adjacent;
	float distance; // Distance to the next geocache
	node * next;
};
// ************************* EDGE STRUCT *************************

// ************************* ADJACENCY LIST CLASS ****************
class table
{
	public:
		table(int size = 5); // Constructor
		~table(void); // Destructor
		int destroy(void); // Destroy function

		int insert_vertex(const geocache & to_add);
		int find_location(std::string key);
		int insert_edge(std::string current_vertex, std::string to_attach, float distance);
		int display_adjacent(std::string key);
		int display_all(void) const;
		// int bfs(std::string key);
		// int bfs(int index, std::vector<bool> & visited);
	private:
		
		vertex * adjacency_list;
		int list_size;

};
// ************************* ADJACENCY LIST CLASS ****************


