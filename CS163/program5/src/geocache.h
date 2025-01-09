// Lian Zhu
// CS163 Program 5
// This is the header file for the geocache stuff

// INCLUDES
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>

// **************************** ERROR HANDLE STRUCT ******************
struct EMPTY_GEOCACHE
{
	std::string function_name;
};
// **************************** ERROR HANDLE STRUCT ******************


// **************************** GEOCACHE CLASS ***********************
class geocache
{
	public:
		geocache(void); // Constructor
		~geocache(void); // Destructor

		int create_entry(std::string location, std::string description, std::string history);
		/*
		* Description: 
		* 	Creates an entry
		* Arguments: 
		*	The strings to enter
		* Returns: 
		*	Success or failure 
		*/

		int copy_entry(const geocache & copy_from);
		/*
		* Description: 
		* 	Copies an entry
		* Arguments: 
		*	The geocache to copy from	
		* Returns: 
		*	Success or failure 
		*/

		int retrieve(std::string location, geocache & found) const;
		/*
		* Description: 
		* 	Retrieves an entry
		* Arguments: 
		*	The string to find, and the geocache object to fill
		* Returns: 
		*	Success or failure 
		*/

		int retrieve(geocache & found) const;
		/*
		* Description: 
		* 	Copies an entry
		* Arguments: 
		*	The geocache to fill
		* Returns: 
		*	Success or failure 
		*/

		bool compare_location(std::string to_compare) const;
		/*
		* Description: 
		* 	Compares two strings
		* Arguments: 
		*	The string to compare
		* Returns: 
		*	True or false 
		*/
		
		int display(void) const;
		/*
		* Description: 
		* 	Displays the geocache
		* Arguments: 
		*	None
		* Returns: 
		*	Success or failure
		*/

	private:
		std::string location; // 
		std::string description; //
		std::string history; // 

	
};

// Again prototype
bool again(void);

