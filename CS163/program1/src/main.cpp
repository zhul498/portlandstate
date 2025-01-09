// Lian Zhu
// 10/2/2024
// CS163
// Program 1
// The purpose of .cpp file is to implement and apply everything

#include "list.h"
const int CHARSIZE {50};

int main ()
{
	char name[CHARSIZE]; // Character array for name input
	char desc[CHARSIZE]; // Character array for desc. input
	char hours[CHARSIZE]; // Character array for hours input
	char owner[CHARSIZE]; // Character array for owner input
	char venueName[CHARSIZE]; // Character array for name input
	char activityName[CHARSIZE]; // Character array for activity input
	char activityRules[CHARSIZE]; // Character array for the rules input
	char activityPrice[CHARSIZE]; // Character array for the price input
	char checkActivity[CHARSIZE]; // Charcter array to see the activities of a venue
	char checkDay[CHARSIZE]; // Character array to see the days of a venue
	char removeVenue[CHARSIZE]; // Character array to remove a venue
	int count {0}; // Count for displaying 
	bool add {false}; // Bool catcher for adding a venue
	bool addActivity {false}; // Bool catcher for adding an activity
	bool activityCheck {false}; // Bool catcher for checking activities
	bool dayCheck {false}; // Bool catcher for checking days
	bool removeCheck {false}; // Bool catcher for removing a venue
	int choice {0}; // Main Menu choice
	list list; // List object for list of venues 
	
	
	// Main menu
	do
	{
		std::cout << "------------ MAIN MENU -----------------\n\n";
		std::cout << "(1) Enter a new venue\n";
		std::cout << "(2) Display all venues\n";
		std::cout << "(3) Add an activity to a venue\n";
		std::cout << "(4) Display a venue's activities\n";
		std::cout << "(5) Display all places that are open on a particular day\n";
		std::cout << "(0) Quit\n\n\n";
		std::cin >> choice;
		std::cin.ignore(100, '\n');
		switch(choice)
		{
			case 1:
				std::cout << "\n\n\nENTERING A VENUE\n\n\n";
				std::cout << "Enter name: ";
				std::cin.get(name, 100, '\n');
				std::cin.ignore(100, '\n');
				std::cout << "Enter desc: ";
				std::cin.get(desc, 100, '\n');
				std::cin.ignore(100, '\n');
				std::cout << "Enter the day that the venue is open (e.g. Monday): ";
				std::cin.get(hours, 100, '\n');
				std::cin.ignore(100, '\n');
				std::cout << "Enter owner: ";
				std::cin.get(owner, 100, '\n');
				std::cin.ignore(100, '\n');
				add = list.add(name, desc, hours, owner);
				if (!add) std::cout << "\n\n\nInvalid information entered or venue already exists\n\n\n";
				else std::cout << "\n\n\nVenue added successfully\n\n\n";
				break;
			case 2: 
				std::cout << "\n\n\nDISPLAYING ALL VENUES\n\n\n";
				count = list.displayVenues();
				std::cout << "Found " << count << " venue(s)\n\n\n";
				break;
			case 3:
				std::cout << "\n\n\nENTERING AN ACTIVITY\n\n\n";
				std::cout << "Enter venue name: ";
				std::cin.get(venueName, 100, '\n');
				std::cin.ignore(100, '\n');
				std::cout << "Enter activity name: ";
				std::cin.get(activityName, 100, '\n');
				std::cin.ignore(100, '\n');
				std::cout << "Enter activity rules: ";
				std::cin.get(activityRules, 100, '\n');
				std::cin.ignore(100, '\n');
				std::cout << "Enter activity price: ";
				std::cin.get(activityPrice, 100, '\n');
				std::cin.ignore(100, '\n');
				addActivity = list.addActivity(venueName, activityName, activityRules, activityPrice);
				if (!addActivity) std::cout << "\n\n\nInvalid information entered or venue does not exist!\n\n\n";
				else std::cout << "\n\n\nActivity added successfully\n\n\n";
				break;
			case 4:
				std::cout << "\n\n\nFINDING AN ACTIVITY\n\n\n";
				std::cout << "Enter the name of the venue you'd like to see the activities for: ";
				std::cin.get(checkActivity, 100, '\n');
				std::cin.ignore(100, '\n');
				activityCheck = list.displayActivities(checkActivity);
				if (!activityCheck) std::cout << "Venue name invalid or no activities found!\n\n\n";
				break;
			case 5: 
				std::cout << "\n\n\nFINDING VENUES SPECIFIED ON DAY OF OPENING\n\n\n";
				std::cout << "Enter the day that you would like to see open venues (e.g. Monday): ";
				std::cin.get(checkDay, 100, '\n');
				std::cin.ignore(100, '\n');
				dayCheck = list.displayOpen(checkDay);
				if (!dayCheck) std::cout << "\n\n\nInvalid day input or none exist!\n\n\n";
				break;
			case 6:
				std::cout << "\n\n\nDELETING A VENUE\n\n\n";
				std::cout << "Enter the name of the venue you'd like to remove: ";
				std::cin.get(removeVenue, 100, '\n');
				std::cin.ignore(100, '\n');
				removeCheck = list.removeVenue(removeVenue);
				if (!removeCheck) std::cout << "\n\n\nVenue not found\n\n\n";
				else std::cout << "\n\n\nVenue removed successfully!\n\n\n";
				break;

			case 0: 
				std::cout << "Thank you for using my program!\n\n\n";
				break;
			default:
				std::cout << "Invalid choice... Please try again\n\n";
				break;
		}
	} while (choice != 0);

	return 0;
}

