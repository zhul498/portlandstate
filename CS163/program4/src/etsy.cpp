// Lian Zhu
// CS163 Program 3
// This is the function implementation for the etsy class

// Includes
#include "etsy.h"

// Using
using namespace std;

// Constructor
etsy::etsy()
{
	title = nullptr;
	description = nullptr;
	category = nullptr;
	type = nullptr;
	price = 0.0;
	quantity = 0;
	seller_id = 0;
	name_shop = nullptr;
}

// Destructor
etsy::~etsy()
{
	destroy();	
}

// Destroy
bool etsy::destroy(void)
{
	delete [] title;
	delete [] description;
	delete [] category;
	delete [] type;
	delete [] name_shop;
	return 1;
}

// Create entry
int etsy::create_entry(char title_add[], char description_add[], char category_add[], char type_add[], float price_add, int quantity_add, 
		       int seller_id_add, char name_shop_add[])
{
	// Error check
	if (!title_add || !description_add || !category_add || !type_add || !name_shop_add) return 0;

	// Allocate memory for entry and copy it in
	else
	{
		// Allocate memory
		title = new char[strlen(title_add) + 1];
		description = new char[strlen(description_add) + 1];
		category = new char[strlen(category_add) + 1];
		type = new char[strlen(type_add) + 1];
		name_shop = new char[strlen(name_shop_add) + 1];

		strcpy(title, title_add);
		strcpy(description, description_add);
		strcpy(category, category_add);
		strcpy(type, type_add);
		strcpy(name_shop, name_shop_add);
		price = price_add;
		quantity = quantity_add;
		seller_id = seller_id_add;
		return 1;
	}
	return 0;

}
// Copy entry
int etsy::copy_entry(const etsy & copy_from)
{
	// Valid check
	if (!copy_from.title || !copy_from.description || !copy_from.category || !copy_from.type || !copy_from.name_shop) return 0;

	// Copy
	else
	{
		title = new char[strlen(copy_from.title) + 1];
		description = new char[strlen(copy_from.description) + 1];
		category = new char[strlen(copy_from.category) + 1];
		type = new char[strlen(copy_from.type) + 1];
		name_shop = new char[strlen(copy_from.name_shop) + 1];

		strcpy(title, copy_from.title);
		strcpy(description, copy_from.description);
		strcpy(category, copy_from.category);
		strcpy(type, copy_from.type);
		strcpy(name_shop, copy_from.name_shop);
		price = copy_from.price;
		quantity = copy_from.quantity;
		seller_id = copy_from.seller_id;
		return 1;
	}	
	return 0;
}


// Retrieve
int etsy::retrieve(char matching_title[], etsy & found) const 
{
	// Valid check
	if (!matching_title) return 0;

	if (strcasecmp(title, matching_title) != 0) return 0;

	// Allocate memory
	found.title = new char[strlen(title) + 1];
	found.description = new char[strlen(description) + 1];
	found.category = new char[strlen(category) + 1];
	found.type = new char[strlen(type) + 1];
	found.name_shop = new char[strlen(name_shop) + 1];

	// Copy
	strcpy(found.title, title);
	strcpy(found.description, description);
	strcpy(found.category, category);
	strcpy(found.type, type);
	strcpy(found.name_shop, name_shop);
	found.price = price;
	found.seller_id = seller_id;
	return 1;
}

// Display
int etsy::display(void) const
{
	// Valid check
	if (!title || !description || !category || !type || !name_shop) return 0;
 	cout << "#############\n" << "Title: " << title << '\n' << "Description: " << description << '\n' << "Category: " << category << '\n' 
	<< "Type: " << type << '\n' << "Price: $" << price << '\n' << "Quantity: " << quantity << '\n' << "Seller ID: " << seller_id << '\n' 
	<< "Name of the shop: " << name_shop << '\n';
	
	return 1;
};

const char* etsy::get_title(void) const
{
	return title;
}

const float etsy::get_price(void) const
{
	return price;
}

