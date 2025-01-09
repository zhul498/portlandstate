// Lian Zhu
// CS163 Program 2
// This is the header file for the game class that will store the info for a game

// Includes
#include <iostream>
#include <cstring>
#include <cctype>

#ifndef GAMES_H
#define GAMES_H
// ************************* ERROR CATCH STRUCT ********************
struct BAD_ENTRY
{
	int data;
};
// ************************* ERROR CATCH STRUCT ********************

// ************************* GAME CLASS ****************************
class gameEntry 
{
	public:
		gameEntry(); // Constructor
		~gameEntry(); // Destructor
		void destroy();
		int createEntry(char title[], char platform[], char genre[], char progression[], char achievements[], char price[]);
		/* Description:
		 * 	Creates an entry to put in the linear linked list of arrays into the stack
		 *
		 * Arguments: 
		 * 	Title of the game, platform (PC, XBOX, etc.), genre, progression (is it linear or an open-world), achievements, 
		 * 	and price of the game
		 *
		 * Returns: 
		 * 	1 for success, 0 for failure	
		 *    
		 */
		
		int copyEntry(const gameEntry & copyFrom);
		/* Description:
		 * 	Copies an entry and fills the newEntry 
		 * Arguments: 
		 * 	a gameEntry object 
		 * Returns: 
		 *   	1 for sucess, 0 for failure 
		 */

		int retrieve(char * matchingTitle, gameEntry & found) const;
		/* Description:
		 * 	Fills the gameEntry object with a game corresponding to the title
		 *    
		 * Arguments: 
		 * 	Title of the game, and a gameEntry object
		 *
		 * Returns: 
		 * 	1 for success, 0 for failure
		 */

		int display(void) const;
		/* Description:
		 * 	Displays the game entry
		 *    
		 * Arguments: 
		 *   	None 
		 * Returns: 
		 *   	1 for success, 0 for failure 
		 */
	private:
		char * title;
		char * platform;
		char * genre;
		char * progression;
		char * achievements;
		char * price;
};
// ************************* GAME CLASS ****************************
#endif

