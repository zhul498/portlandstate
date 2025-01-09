// Lian Zhu
// CS163 Program 3
// This is the main file that will be the "client program"

// Includes
#include "table.h"

// Using
using namespace std;

// Main
int main (void) 
{
	// Initialize variables
	table hash_table; // Hash table object
	etsy to_add, to_retrieve; // Etsy object / Product
	int count {0}; // Count of the hash table
	int choice {0}; // Main Menu choice
	char title[CHARSIZE]; // Name of the product (input)	
	char description[CHARSIZE]; // Detailed description 
	char category[CHARSIZE]; // Used for browsing/filtering (otherwise the key)
	char type[CHARSIZE]; // Vintage, handmade, craft, supplies, etc.
	float price {0.0}; // Price of the object
	int quantity {0}; // Quantity available
	int seller_id {0}; // A unique identifier representing the seller
	char name_shop[CHARSIZE]; // Name of the shop offering the product
	bool sold_flag {false}; // Whether the product was sold or not
	int load_count {0}; // Count of the # of items loaded
	char find_category[CHARSIZE]; // Category find
	char category_retrieve[CHARSIZE]; // To retrieve
	char title_retrieve[CHARSIZE]; // to retrieve
	int category_count {0}; // Category count
	int id_remove {0}; // ID to remove
	char title_buy[CHARSIZE]; // Name to buy

	// Main menu
	do 
	{
		cout << "------------ MAIN MENU ----------\n\n";
		cout << "(1) Enter something into the hash table\n";
		cout << "(2) Display the hash table\n";
		cout << "(3) Load items into the hash table\n";
		cout << "(4) Find items by category\n";
		cout << "(5) Retrieve an item\n";
		cout << "(6) Remove an item\n";
		cout << "(0) Quit the program\n";
		cin >> choice;
		cin.ignore(100, '\n');
		switch (choice)
		{
			case 1: // Enter into the hash table
				// Clear the current values in to_add
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
				cout << "Enter whether or not this item has been sold out (1 FOR YES, 0 FOR NO): ";
				cin >> sold_flag; cin.ignore(100, '\n');

				// Attempt to create entry
				if (!to_add.create_entry(title, description, category, type, price, quantity, seller_id, name_shop, sold_flag)) 
				{	
					cout << "\nCould not insert!\n";
				}
				// Attempt to insert into hash_table
				if (!hash_table.insert(category, to_add)) cout << "\nCould not insert!\n";
				cout << "\nInserted!\n";
				break;
			case 2: // Display all
				cout << "\nDisplaying all in the hash table\n";
				if ((count = hash_table.display_all()) == 0) cout << "\nNothing to display!\n";
				cout << "\nDisplayed " << count << " items\n";
				break;
			case 3: // Load items
				if ((load_count = hash_table.load()) == 0) cout << "\nCould not load items!\n";	
				else cout << "\nLoaded " << load_count << " items\n";
				break;
			case 4: // Find by category
				cout << "Enter the category that you'd like to search for: ";
				cin.get(find_category, 250, '\n'); cin.ignore(250, '\n');
				if ((category_count = hash_table.display_category(find_category)) == 0) cout << "\nNone to display!\n";
				else cout << "\nDisplayed " << category_count << " items\n";
				break;
			case 5: // Retrieve
				to_retrieve.destroy();
				cout << "Enter the category that you'd like to retrieve: ";
				cin.get(category_retrieve, 250, '\n'); cin.ignore(250, '\n');
				cout << "Enter the title that you'd like to retrieve: ";
				cin.get(title_retrieve, 250, '\n'); cin.ignore(250, '\n');
				
				if (!hash_table.retrieve(category_retrieve, title_retrieve, to_retrieve)) cout << "\nCould not retrieve!\n";
				to_retrieve.display();
				break;
			case 6: // Remove an item
				cout << "Enter the seller ID that you'd like to remove: ";
				cin >> id_remove; cin.ignore(100, '\n');
				if (!hash_table.remove_entry(id_remove)) cout << "\nCould not remove!\n";
				break;
			case 7: // Buy an item
				to_retrieve.destroy();
				cout << "Enter the title that you'd like to buy: ";
				cin.get(title_buy, 250, '\n'); cin.ignore(250, '\n');
				if (!hash_table.buy(title_buy, to_retrieve)) cout << "Could not buy!";
				break;
			case 0: // Quit
				cout << "\nThank you for using my program!\n";
				break;
			default: // Invalid input
				cout << "\nInvalid input... Please try again.\n";
				break;
		}
	} while (choice != 0);

	return 0;
}

