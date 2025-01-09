// Lian Zhu
// 10/1/2024
// CS163
// Program 1
// The purpose of this .h file is to create an ADT that contains a LLL of a LLL of fun activities around town

// Includes
#include <iostream>
#include <cctype>
#include <cstring>

// ******************** ACTIVITY STRUCT ******************************
struct activity 
{
	char * name; // Name of the activity
	char * rules; // Rules for the activity
	char * price; // Price for the activity 
	activity * next; // Pointer to the next activity
};
// ******************** ACTIVITY STRUCT ******************************


// ******************** ACTIVITY NODE STRUCT *************************
struct activityNode
{
	activity anActivity;
	activityNode * next;
};
// ******************** ACTIVITY NODE STRUCT *************************

// ******************** VENUE STRUCT *********************************
struct venue
{
	char * name; // Name of the venue
	char * description; // Description of what they are known for
	char * hours; // Hours of operation (e.g Venue is open Wednesday through Sunday)
	char * owner; // The current owner of the venue
};
// ******************** VENUE STRUCT *********************************

// ******************** VENUE NODE STRUCT ****************************
struct venueNode
{
	venue aVenue; // Venue
	activityNode * head; // Beginning of a list of activities
	venueNode * next; // Pointer to the next venue
};
// ******************** VENUE NODE STRUCT ****************************

// ******************** LIST CLASS ***********************************
class list
{
	public:
		list();
		~list(); 

		bool add(char nameToAdd[], char descToAdd[], char hoursToAdd[], char ownerToAdd[]);
		/* Description:
		 *    Adds a venue to the list of venues  
		 *
		 * Arguments:
		 *    The name to add, the description to add, the hours to add, and the owner to add
		 *
		 * Returns:
		 *    0 if this venue already exists, therefore error
		 *
		 */
		bool addActivity(char venueName[], char nameToAdd[], char rulesToAdd[], char priceToAdd[]); 
		/* Description:
		 *    Adds an activity to a venue
		 *
		 * Arguments:
		 *    The name to add, the description to add, the rules to add, and the price to add
		 *
		 * Returns:
		 *    False if venue doesn't exist, True otherwise 
		 *
		 */
		bool removeVenue(char venueName[]);
		/* Description:
		 *    Removes a venue from the list, freeing all memory (and the activities memory)
		 *
		 * Arguments:
		 *    Venue name in order to find which venue we are looking for  
		 *
		 * Returns:
		 *    Bool, whether or not venue exists
		 *
		 */

		int displayVenues() const;
		/* Description:
		 *    Wrapper function, displays all of the venues recursively
		 *
		 * Arguments:
		 *    None
		 *
		 * Returns:
		 *    0 if this venue already exists, therefore error, otherwise number of venues
		 *
		 */

		bool displayActivities(char venueName[]) const;
		/* Description:
		 *    Displays activities for a venue
		 *
		 * Arguments:
		 *    Venue name in order to find which activities we are looking for 
		 *
		 * Returns:
		 *    Bool, whether or not activities were found (or if venue exists)
		 *
		 */

		bool displayOpen(char day[]) const; 
		/* Description:
		 *    Displays the open venues for a specific day
		 *
		 * Arguments:
		 *    Day of the week that the user has asked for 
		 *
		 * Returns:
		 *    Bool, whether or not the day was a valid day of the week 
		 *
		 */

	private:
		int displayVenues(venueNode * head) const;
		/* Description:
		 *    Displays all of the venues recursively, therefore head->next must be passed
		 *
		 * Arguments: 
		 *    Head
		 *   
		 * Returns:
		 *    The amount of venues displayed, if it returns 0 main will output no venues to display
		 *
		 */
		venueNode * head; // Head of the venue list
};
// ******************** LIST CLASS ***********************************


