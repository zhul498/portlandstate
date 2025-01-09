// Lian Zhu
// CS163 Program 4
// This is the table header file for the BST

// Includes
#include "etsy.h"
#include <algorithm>


// ***************************** ERROR HANDLE STRUCT ***********************
struct EMPTY_LIST
{
	string function_name;
};
// ***************************** ERROR HANDLE STRUCT ***********************

// ***************************** NODE STRUCT *******************************
struct node 
{
	etsy etsy_object;
	node * left;
	node * right;
};
// ***************************** NODE STRUCT *******************************

// ***************************** TABLE CLASS *******************************
class table
{
	public:
		table(); // Constructor
		~table(); // Destructor
		int destroy(void); // Wrapper function to destroy
		int insert(etsy & to_add); // Wrapper function for insertion
		int display(void) const; // Wrapper function to display
		int remove(char title[]); // Wrapper function to remove
		int retrieve(char title[], etsy & to_retrieve); // Wrapper function to retrieve
		int find_height(void) const; // Wrapper function to find height
		int display_range(float low, float high) const; // Wrapper function to display all within a range between two prices

	private:
		node * root; // Root of the tree
		int destroy(node * & root); 
		/* Description
		*	Destroys the tree
		*
		*  Arguments
		*	Root
		*
		*  Returns
		*	Num destroyed
		*/

		int insert(node * & root, etsy & to_add);
		/* Description
		*	Inserts an etsy object
		*
		*  Arguments
		*	Root, and the object to add
		*
		*  Returns
		*	Success or failure
		*/

		int display(node * root) const;
		/* Description
		*	Displays the BST
		*
		*  Arguments
		*	Root
		*
		*  Returns
		*	Number of nodes displayed
		*/

		int remove(node * & root, char title[]);
		/* Description
		*	Removes a node
		*
		*  Arguments
		*	Root, and the title of object to remove
		*
		*  Returns
		*	Success or failure
		*/

		int retrieve(node * root, char title[], etsy & to_retrieve);
		/* Description
		*	Retrieves an object
		*
		*  Arguments
		*	Root, title of the object, and to_retrieve to fill up
		*
		*  Returns
		*	Success or failure
		*/

		int find_height(node * root) const;
		/* Description
		*	Finds height of the tree
		*
		*  Arguments
		*	Root
		*
		*  Returns
		*	Height
		*/

		int display_range(node * root, float low, float high) const;
		/* Description
		*	Displays all etsy products within a range of price
		*
		*  Arguments
		*	Root, and the two prices as range
		*
		*  Returns
		*	Number of nodes displayed
		*/

};
// ***************************** TABLE CLASS *******************************

