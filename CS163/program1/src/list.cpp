// Lian Zhu
// 10/2/2024
// CS163
// Program 1
// The purpose of this .cpp file is to implement the functions in the list.h file

// Includes
#include "list.h"

// Constructor
list::list()
{
	head = nullptr;
}

// Destructor
list::~list()
{
	while (head)
	{
		venueNode * temp = head->next;
		activityNode * activityTemp = nullptr;
			
		// delete the activity nodes
		while (head->head)
		{
			activityTemp = head->head->next;
			delete [] head->head->anActivity.name;
			delete [] head->head->anActivity.rules;
			delete [] head->head->anActivity.price;
			delete head->head;
			head->head = activityTemp;
		}

		// delete the venue nodes
		delete [] head->aVenue.name;
		delete [] head->aVenue.description;
		delete [] head->aVenue.hours;
		delete [] head->aVenue.owner;
		delete head;
		head = temp;
	}
}


// Add a venue
bool list::add(char nameToAdd[], char descToAdd[], char hoursToAdd[], char ownerToAdd[])
{
	// if any part of toAdd is empty
	if (nameToAdd[0] == '\0' || descToAdd[0] == '\0' || hoursToAdd[0] == '\0' || ownerToAdd[0] == '\0') return false;


	// check if venue name already exists
	venueNode * temp = head;
	while (temp)
	{
		if (strcmp(temp->aVenue.name, nameToAdd) == 0) 
		{
			return false;
		}
		temp = temp->next;
	}	
	
	
	venueNode * newVenue = new venueNode;
	newVenue->aVenue.name = new char[strlen(nameToAdd) + 1];
	strcpy(newVenue->aVenue.name, nameToAdd);	

	newVenue->aVenue.description = new char[strlen(descToAdd) + 1];
	strcpy(newVenue->aVenue.description, descToAdd);	
	
	newVenue->aVenue.hours = new char[strlen(hoursToAdd) + 1];
	strcpy(newVenue->aVenue.hours, hoursToAdd);	

	newVenue->aVenue.owner = new char[strlen(ownerToAdd) + 1];
	strcpy(newVenue->aVenue.owner, ownerToAdd);	


	// Empty list
	if (!head) 
	{
		head = newVenue;
		newVenue->next = nullptr;
		return true;
	}

	// Add to end of list
	venueNode * curr = head;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = newVenue;
	newVenue->next = nullptr;
	return true;

}
// Add an activity to a venue function
bool list::addActivity(char venueName[], char nameToAdd[], char rulesToAdd[], char priceToAdd[])
{
	// empty list
	if (!head) return false;

	// if activity is missing information
	if (nameToAdd[0] == '\0' || rulesToAdd[0] == '\0' || priceToAdd[0] == '\0') return false;
		
	// find venue and add activity
	venueNode * temp = head;
	while (temp)
	{
		// find match, strccasecmp for case insensitivity
		if (strcasecmp(venueName, temp->aVenue.name) == 0) 
		{
			// add activity logic
			activityNode * newActivity = new activityNode;
			newActivity->next = nullptr;

			newActivity->anActivity.name = new char[strlen(nameToAdd) + 1];
			strcpy(newActivity->anActivity.name, nameToAdd);
			newActivity->anActivity.rules = new char[strlen(rulesToAdd) + 1];
			strcpy(newActivity->anActivity.rules, rulesToAdd);
			newActivity->anActivity.price = new char[strlen(priceToAdd) + 1];
			strcpy(newActivity->anActivity.price, priceToAdd);
			
			// insert sorted
			if (!temp->head || strcmp(newActivity->anActivity.name, temp->head->anActivity.name) < 0)
			{
				// insert at head
				newActivity->next = temp->head;
				temp->head = newActivity; 
			}
			// traverse to find the correct position
			else 
			{
				activityNode * curr = temp->head;
				while (curr->next && strcmp(newActivity->anActivity.name, curr->next->anActivity.name) > 0)
				{
					curr = curr->next;
				}
				// insert at correct position
				newActivity->next = curr->next;
				curr->next = newActivity;
			}
			return true;
		}
		temp = temp->next;
	}
	// no match found at the end of this loop, so return false
	return false;
}

// Remove a Venue
bool list::removeVenue(char venueName[])
{
	// invalid input
	if (venueName[0] == '\0') return false;
	
	// find venue
	venueNode * curr = head;
	venueNode * prev = nullptr;
	while (curr)
	{
		// if match found, case insensitive
		if (strcasecmp(venueName, curr->aVenue.name) == 0)
		{
			if (prev) // if it's not the head node
			{
				prev->next = curr->next;
			}
			else  // if it is the head node
			{
				head = curr->next;
			}
			delete [] curr->aVenue.name;
			delete [] curr->aVenue.description;
			delete [] curr->aVenue.hours;
			delete [] curr->aVenue.owner;
			delete curr;
			return true;
		}
		prev = curr;
		curr = curr->next;
	}	

	return false;
}

// Wrapper function to recursively display venues
int list::displayVenues() const
{
	if (!head) return 0;
	return displayVenues(head);
}


// Display Venues recursive function
int list::displayVenues(venueNode * head) const
{
	if (!head) return 0;
	std::cout << "\n\n\nName: " << head->aVenue.name << "\n" << "Description: " << head->aVenue.description << "\n" << "Hours: " << head->aVenue.hours
	       	  << "\n" << "Owner: " << head->aVenue.owner << "\n\n\n";
	return displayVenues(head->next) + 1;
}

// Display activites for a certain venue function
bool list::displayActivities(char venueName[]) const
{
	// if venueName is invalid
	if (venueName[0] == '\0') return false;

	// find venue
	venueNode * curr = head;
	while (curr)
	{
		// found match, case insensitive
		if (strcasecmp(venueName, curr->aVenue.name) == 0)
		{
			activityNode * activity = curr->head;
			// if no activities
			if (!activity) return false;
			while (activity)
			{
				std::cout << "\n\n\nActivity name: " << activity->anActivity.name << '\n';
				std::cout << "Activity rules: " << activity->anActivity.rules << '\n';
				std::cout << "Activity price: " << activity->anActivity.price << "\n\n\n";
				activity = activity->next;
			}
			return true;
		}
		curr = curr->next;
	}
	return false;
}


// display activities with open days of the week
bool list::displayOpen(char day[]) const
{
	// check if valid input
	if (!day[0]) return false;
	

	// check if valid day of the week
	if ((strcasecmp(day, "monday") != 0) && (strcasecmp(day, "tuesday") != 0) && (strcasecmp(day, "wednesday") != 0)
	   && (strcasecmp(day, "thursday") != 0) && (strcasecmp(day, "friday") != 0) && (strcasecmp(day, "saturday") != 0) 
	   && (strcasecmp(day, "sunday") != 0)) return false;

	// find venues open with that day
	venueNode * curr = head;
	while (curr)
	{
		// compare
		if (strcmp(day, curr->aVenue.hours) == 0)
		{
			std::cout << "Venue: " << curr->aVenue.name << '\n' << "Description: " << curr->aVenue.description << '\n' << "Hours: " << curr->aVenue.hours
				  << '\n' << "Owner: " << curr->aVenue.owner << "\n\n\n";
		}
		curr = curr->next;
	}
	return true;	
}


