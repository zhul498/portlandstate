// Lian Zhu
// CS163 Program 2
// This is the header file for the stack class that will control the stack

// Includes
#include "games.h"

// Constants
const int MAX = 5;

// ************************* NODE STRUCT ****************************
struct node
{
	gameEntry * entries; // A dynamically allocated array of game entries
	node * next;
};
// ************************* NODE STRUCT ****************************

// ************************* STACK CLASS ****************************
class stack
{
	public:
		stack(void); // Constructor
		~stack(void); // Destructor
		int push(const gameEntry & toAdd);
		void destroy();
		/* Description:
		 * 	Pushes a game entry to the stack
		 *
		 * Arguments:
		 * 	A game entry object
		 *
		 * Returns: 
		 * 	1 for success, 0 for failure	
		 *    
		 */

		int pop(void);
		/* Description:
		 * 	Removes a game entry from the stack
		 *
		 * Arguments:
		 * 	None
		 *
		 * Returns: 
		 * 	1 for success, 0 for failure	
		 *    
		 */

		int peek(gameEntry & toRetrieve) const;
		/* Description:
		 * 	Fills the toRetrieve object with the top game entry
		 *
		 * Arguments:
		 * 	A game entry object that will be filled
		 *
		 * Returns: 
		 * 	1 for success, 0 for failure	
		 *    
		 */

		int display(void) const;
		/* Description:
		 * 	Displays all of the stack
		 *
		 * Arguments:
		 * 	None
		 *
		 * Returns: 
		 * 	1 for success, 0 for failure	
		 *    
		 */

	private:
		node * head;
		int topIndex;

};
// ************************* STACK CLASS ****************************

