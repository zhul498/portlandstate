// Lian Zhu
// CS163 Program 5
// This is the implementation file for geocache.h

// Includes
#include "geocache.h"

// Using
using namespace std;

// Constructor
geocache::geocache(void)
{
	
}

// Destructor
geocache::~geocache(void)
{
	// No manual destructor needed since string class has its own
}

// Create an entry
int geocache::create_entry(string location_add, string description_add, string history_add)
{
	// Error check
	if (location_add.empty() || description_add.empty() || history_add.empty())
	{
		EMPTY_GEOCACHE empty;
		empty.function_name = "create_entry";
		throw empty;
	}

	location = location_add;
	description = description_add;
	history = history_add;
	return 1;
}

// Copy entry
int geocache::copy_entry(const geocache & copy_from)
{
	// Error check
	if (copy_from.location.empty() || copy_from.description.empty() || copy_from.history.empty())
	{
		EMPTY_GEOCACHE empty;
		empty.function_name = "copy_entry";
		throw empty;
	}

	location = copy_from.location;
	description = copy_from.description;
	history = copy_from.history;
	return 1;

}

// Retrieve
int geocache::retrieve(string location_retrieve, geocache & found) const
{
	if (location == location_retrieve)
	{
		found.location = location;
		found.description = description;
		found.history = history;
		return 1;
	}
	return 0;

}

// Compare
bool geocache::compare_location(string to_compare) const
{
	return location == to_compare;
}

// Display
int geocache::display(void) const
{
	cout << "#### GEOCACHE INFORMATION ####\n";
	cout << "Location: " << location << "\n" << "Description: " << description << "\n" << "History: " << history << "\n";
	return 1;
}

bool again(void)
{
	char choice {'0'};
	cout << "Would you like to go again? (Y/N): ";
	cin >> choice; cin.ignore(100, '\n');
	if (choice == 'Y' || choice == 'y') return true;
	else return false;

}



