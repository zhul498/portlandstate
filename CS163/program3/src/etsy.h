// Lian Zhu
// CS163 Program 3
// This is the header file for the etsy


// Includes
#include <iostream>
#include <cstring>
#include <cctype>

// Constants
const int CHARSIZE {250};

// Guards
#ifndef ETSY_H
#define ETSY_H

// ***************************** ETSY CLASS *********************************
class etsy
{
	public:
		etsy(); // Constructor
		~etsy(); // Destructor
		bool destroy(void);
		/* Description:
		 * 	Destroys, destructor will call this function
		 *
		 * Arguments: 
		 * 	None
		 *
		 * Returns:
		 * 	Success or failure
		 */
	
		const char* get_category() const;
		
		const int get_id() const;

		int create_entry(char title[], char description[], char category[], char type[], float price, int quantity, int seller_id, char name_shop[],
				bool sold_flag);
		/* Description:
		 * 	Will create an entry 
		 *
		 * Arguments: 
		 * 	The private member functions needed to insert an entry
		 *
		 * Returns:
		 * 	Success or failure
		 */
		
		int copy_entry(const etsy & copy_from);
		/* Description:
		 * 	Copies and entry and fills it from copy_from
		 *
		 * Arguments: 
		 * 	The entry to copy from
		 *
		 * Returns:
		 * 	Success or failure
		 */
		int retrieve(char matching_title[], etsy & found) const;
		/* Description:
		 * 	Fills the found entry with an etsy product corresponding to the matching title
		 *
		 * Arguments: 
		 * 	The matching title to search for, and the found etsy object
		 *
		 * Returns:
		 * 	Success or failure
		 */
		
		int display (void) const;
		/* Description:
		 * 	Displays the object
		 *
		 * Arguments: 
		 * 	None
		 *
		 * Returns:
		 * 	Success or failure
		 */

	private:
		char * title; // Name of the product (input)	
		char * description; // Detailed description 
		char * category; // Used for browsing/filtering (otherwise the key)
		char * type; // Vintage, handmade, craft, supplies, etc.
		float price; // Price of the object
		int quantity; // Quantity available
		int seller_id; // A unique identifier representing the seller
		char * name_shop; // Name of the shop offering the product
		bool sold_flag; // Whether the product was sold or not

		friend class table; // Allows for table to access etsy's data members
};
// ***************************** ETSY CLASS *********************************
#endif

