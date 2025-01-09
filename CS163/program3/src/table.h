// Lian Zhu
// CS163 Program 3
// This is the header file that will contain the class for the hash table

// Includes
#include "etsy.h"
#include <fstream>


// ***************************** NODE STRUCT *********************************
struct node 
{
	etsy etsy_object; // An etsy object
	node * next; // Next node
};
// ***************************** NODE STRUCT *********************************


// ***************************** TABLE CLASS *********************************
class table
{
	public:
		table(int size = 11); // Constructor
		// Takes "size" as an argument, and constructs a hash table of that size
		
		~table(); // Destructor
		

      		int load(void);
		/* Description:
		 * 	Loads from data.txt
		 *
		 * Arguments: 
		 * 	None
		 *
		 * Returns:
		 * 	The amount loaded
		 */
		int insert(char key_value[], const etsy & to_add);
		/* Description:
		 * 	Inserts a node to add in a linear linked list
		 *
		 * Arguments: 
		 * 	The etsy object to add
		 *
		 * Returns:
		 * 	Success or failure
		 */

		int retrieve(char category[], char title[], etsy & to_retrieve) const; 
		/* Description:
		 * 	Retrieves a specific product
		 *
		 * Arguments:
		 * 	Char array to the category, char array for the title, 
		 * 	and a to_retrieve etsy object to fill
		 *
		 * Returns:
		 * 	Success or failure
		 */

		int display_category(char category[]);
		/* Description:
		 * 	Displays all in a category
		 *
		 * Arguments:
		 * 	Char array to the category
		 *
		 * Returns:
		 * 	Success or failure
		 */
		int display_all(void) const;
		/* Description:
		 * 	Displays all
		 *
		 * Arguments: 
		 * 	None
		 *
		 * Returns:
		 * 	Success or failure
		 */

		 int remove_entry(int seller_id);
		/* Description:
		 * 	Removes an entry
		 *
		 * Arguments: 
		 * 	Seller ID
		 *
		 * Returns:
		 * 	Success or failure
		 */
		
		int buy(char title_buy[], etsy & to_buy);
		/* Description:
		 * 	Buys an entry
		 *
		 * Arguments: 
		 * 	Title
		 *
		 * Returns:
		 * 	Success or failure
		 */


	private:
		node ** hash_table;
		int hash(char category[]) const;
		/* Description:
		 *	Hashes the "category" into an integer
		 * Arguments:
		 *	A pointer to a char, the key
		 * Returns:
		 *	The index of the array to access	
		 */
		int hash_table_size; // Size of the hash table
			
};
// ***************************** TABLE CLASS *********************************


