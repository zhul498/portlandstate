// Lian Zhu
// CS163 Program 4
// This is the main file -- the "client program" for program 4

// Includes
#include "table.h"

int main (void)
{
	// Initialize variables
	table BST; // BST object
	etsy to_add, to_retrieve; // Etsy object / product
	char title[CHARSIZE]; // Name of the product (input)	
	char description[CHARSIZE]; // Detailed description 
	char category[CHARSIZE]; // Used for browsing/filtering (otherwise the key)
	char type[CHARSIZE]; // Vintage, handmade, craft, supplies, etc.
	float price {0.0}; // Price of the object
	int quantity {0}; // Quantity available
	int seller_id {0}; // A unique identifier representing the seller
	char name_shop[CHARSIZE]; // Name of the shop offering the product
	int choice {0}; // Main menu choice
	int num_display {0}; // Number of nodes displayed
	char title_remove[CHARSIZE]; // Title to remove
	char title_retrieve[CHARSIZE]; // Title to retrieve 
	int range_display {0}; // Number of nodes displayed in a range
	float low {0.0};  // Low price for display
	float high {0.0};  // High price for display
	int height {0}; // Height of tree

	// Main menu
	do
	{
		cout << "------------- MAIN MENU -------------\n\n";
		cout << "(1) Insert a product into the BST\n";
		cout << "(2) Display the BST\n";
		cout << "(3) Remove an item from the BST\n";
		cout << "(4) Retrieve an item from the BST\n";
		cout << "(5) Display the height of the tree\n";
		cout << "(6) Display all products within a range of prices\n";
		cout << "(0) Quit the program\n";
		cin >> choice; cin.ignore(100, '\n');
		switch (choice)
		{
			case 1: // Insert a product
				to_add.destroy();
				// Get input
				cout << "Enter title of product: ";
				cin.get(title, 250, '\n'); cin.ignore(250, '\n');
				cout << "Enter the description of the product: ";
				cin.get(description, 250, '\n'); cin.ignore(250, '\n');
				cout << "Enter the category of the product: ";
				cin.get(category, 250, '\n'); cin.ignore(250, '\n');
				cout << "Enter type of the product: ";
				cin.get(type, 250, '\n'); cin.ignore(250, '\n');
				cout << "Enter the price of the object: ";
				cin >> price; cin.ignore(100, '\n');
				cout << "Enter the quantity available: ";
				cin >> quantity; cin.ignore(100, '\n');
				cout << "Enter the seller ID: ";
				cin >> seller_id; cin.ignore(100, '\n');
				cout << "Enter the name of the shop that is selling the product: ";
				cin.get(name_shop, 250, '\n'); cin.ignore(250, '\n');
				try
				{
					if (to_add.create_entry(title, description, category, type, price, quantity, seller_id, name_shop))
					{
						cout << "\nCreated entry\n";
					}
					if (BST.insert(to_add)) 
					{
						cout << "\nInserted into BST!\n";
					}
				}
				catch (EMPTY_LIST)
				{
					cerr << "Error";
				}
				break;
			case 2: // Display
				num_display = BST.display();
				cout << "\nDisplayed " << num_display << " nodes\n";
				break;
			case 3: // Remove an item
				cout << "Enter title of the product you'd like to remove: ";
				cin.get(title_remove, 250, '\n'); cin.ignore(250, '\n');
				try
				{
					if (BST.remove(title_remove))
					{
						cout << "\nRemoved from BST!\n";
					}
					else cout << "\nCould not find item in BST!\n";
				}
				catch (EMPTY_LIST)
				{
					cerr << "Error";
				}
				break;
			case 4: // Retrieve an item
				to_retrieve.destroy();
				cout << "Enter title of the product you'd like to retrieve: ";
				cin.get(title_retrieve, 250, '\n'); cin.ignore(250, '\n');
				try 
				{
					if (BST.retrieve(title_retrieve, to_retrieve))
					{
						cout << "\nRetrieved!\n";
						to_retrieve.display();
					}
					else cout << "\nCould not find item in BST!\n";
				}
				catch (EMPTY_LIST)
				{
					cerr << "Error";
				}
				break;
			case 5: // Display height
				height = BST.find_height();
				cout << "\nHeight of tree: " << height << "\n";
				break;
			case 6: // Display range
				cout << "Enter the minimum price that you'd like to display: ";
				cin >> low; cin.ignore(100, '\n');
				cout << "Enter the maximum price that you'd like to display: ";
				cin >> high; cin.ignore(100, '\n');
				range_display = BST.display_range(low, high);
				cout << "\nDisplayed " << range_display << " nodes\n";
				break;
			case 0: // Quit
				cout << "\nThank you for using my program!\n";
				break;
			default: // Invalid input
				cout << "\nInvalid input.. Please try again.\n";
				break;
		}
	} while (choice != 0);
	return 0;
}

