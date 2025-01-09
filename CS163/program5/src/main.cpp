// Lian Zhu
// CS163 Program 5
// This is the main file for the geocache adjacency list program

//Includes
#include "graph.h"

// Using
using namespace std;


int main(void)
{
	table list; // Adjacency list
	geocache to_add, an_entry; // Geocache entries
	string location, description, history; // Geocache members
	string connected, display_connections; // A string that will connect two vertices
// 	string bfs_input; // Key for where to start in the bfs
	float distance {0.0}; // Distance for the edges
	int num_displayed {0}; // Number of geocache objects in graph
	int connection_displayed {0}; // Number of connections
// 	int explored {0}; // Number of vertexes explored in bfs
	// Add items to the geocache and create vertexes
	do
	{

		cout << "Please enter a location: "; 
		cin >> location; cin.ignore(100,'\n');
		cout << "Please enter a description: ";
		cin >> description; cin.ignore(100, '\n');
		cout << "Please enter the geocache's history: ";
		cin >> history; cin.ignore(100, '\n');
		try
		{
			to_add.create_entry(location, description, history);
			list.insert_vertex(to_add);
			cout << "\nInserted vertex!\n";
		}
		catch (EMPTY_GEOCACHE)
		{
			cerr << "Error: " << endl;
		}

	} while (again());
	
	// Create connections
	do 
	{
		cout << "Enter the first title that is connected: ";
		cin >> location; cin.ignore(100, '\n');
		cout << "Enter the title that " << location << " is connected to: ";
		cin >> connected; cin.ignore(100, '\n');
		cout << "Enter the distance between " << location << " and " << connected << " in miles: ";
		cin >> distance; cin.ignore(100, '\n');

		list.insert_edge(location, connected, distance);

		cout << "\nInserted edge!\n";
		

	} while (again());

	cout << "\nDisplaying direct connections\n";
	do
	{

		cout << "\nEnter the vertex name that you'd like to display direct connections: ";
		cin >> display_connections; cin.ignore(100, '\n');
		connection_displayed = list.display_adjacent(display_connections);
		if (connection_displayed == 0) cout << "\nNone to display!\n";

	} while (again());

	cout << "\nDisplaying the adjacency list\n";
	num_displayed =	list.display_all();
	cout << "\nDisplayed " << num_displayed << " vertices\n";
	
/* 	cout << "\nBFS\n";
	do
	{
		cout << "Enter a geocache name and explore all discoverable geocaches through that one!\n";
		cin >> bfs_input; cin.ignore(100, '\n');
		explored = list.bfs(bfs_input);	
		cout << "\nExplored " << explored << " nodes!\n";
	} while (again());
*/
	return 0;
}



