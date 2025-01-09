// Lian Zhu
// CS163 Program 2
// This is the header file for the queue class that will control the queue

// Includes
#include "games.h"


// ************************* NODE STRUCT ****************************
struct q_node
{
	gameEntry entry; // a game entry
	char * seriesName; // the series name 
	int year; // year that it's made
	q_node * next;	
};
// ************************* NODE STRUCT ****************************


// ************************* QUEUE CLASS ****************************
class queue
{
	public:
		queue(void); // Constructor
		~queue(void); // Destructor
		int enqueue(char * seriesName, int yearToAdd, gameEntry & toRetrieve);
		/* Description:
		 * 	Adds a game entry to the end of the queue, the toRetrieve
		 * 	argument will be filled by anEntry in main after found from the gameEntry function retrieve and copied and filled into toRetrieve
		 *
		 * Arguments:
		 * 	A game entry object, the series name, the year to add,
		 * 	and the gameName to retrieve and add it to the series
		 *
		 * Returns: 
		 * 	1 for success, 0 for failure	
		 *    
		 */

		int dequeue(void);
		/* Description:
		 * 	Removes an entry from the queue
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
		 * 	Displays the queue, wrapper function
		 *
		 * Arguments:
		 * 	None
		 *
		 * Returns: 
		 * 	1 for success, 0 for failure	
		 *    
		 */
	
	private:
		int display(q_node * rear) const;
		/* Description:
		 * 	Displays the queue, recursive function
		 *
		 * Arguments:
		 * 	Rear node
		 *
		 * Returns: 
		 * 	1 for success, 0 for failure	
		 *    
		 */

		q_node * rear; // last node of the queue

};
// ************************* QUEUE CLASS ****************************

