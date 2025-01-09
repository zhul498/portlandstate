// Lian Zhu
// CS163 Program 3
// This is the implementation file for table.h

// Includes
#include "table.h"

// Using
using namespace std;

// Construct the hash table, array of head pointers, and make sure each element is null
table::table(int size)
{
	hash_table = new node*[size];
	for (int i {0}; i < size; ++i)
	{
		hash_table[i] = nullptr;
	}
	hash_table_size = size;
}

// Destructor
table::~table()
{
	for (int i {0}; i < hash_table_size; ++i)
	{
		node * curr = hash_table[i];

		while (curr)
		{
			node * temp = curr;
			curr = curr->next;

			delete temp;

		}
	}

	delete [] hash_table;

}

// Hash function
int table::hash(char category[]) const
{
	int index {0};
	for (int i {0}; category[i] != '\0'; ++i)
	{
		index+=category[i];
	}
	return index %= hash_table_size;
}

// Insert into the table
int table::insert(char key_value[] , const etsy & to_add)
{
	// Hash the key_value
	int index = hash(key_value);
	
	// Hold head
	node * hold = hash_table[index];
	// Insert
	hash_table[index] = new node;
	hash_table[index]->etsy_object.copy_entry(to_add);
	hash_table[index]->next = hold;

	return 1;
}


// Load from data.txt
int table::load(void)
{
	// connect
	std::ifstream file_in;
	file_in.open("data.txt");

	// Count
	int counter {0};
	
	// Error
	if (!file_in) return 0;

	else
	{
		// Allocate data
		char title[CHARSIZE] {'\0'};
		char description[CHARSIZE] {'\0'};
		char category[CHARSIZE] {'\0'};
		char type[CHARSIZE] {'\0'};
		char name_shop[CHARSIZE] {'\0'};
		float price {0.0};
		int quantity {0};
		int seller_id {0}; 
		bool sold_flag {0};

		// Read -- (title | description | category | type | price | quant | seller id | name shop | sold_flag)
		while (file_in && !file_in.eof())
		{
			etsy object; 	

			file_in.getline(title, CHARSIZE, '|'); 

			file_in.getline(description, CHARSIZE, '|');

			file_in.getline(category, CHARSIZE, '|');

			file_in.getline(type, CHARSIZE, '|'); 

			file_in >> price; file_in.ignore(CHARSIZE, '|'); 

			file_in >> quantity; file_in.ignore(CHARSIZE, '|');

			file_in >> seller_id; file_in.ignore(CHARSIZE, '|');

			file_in.getline(name_shop, CHARSIZE, '|'); 

			file_in >> sold_flag; file_in.ignore(CHARSIZE, '\n');

			// Insert into table
			if (!object.create_entry(title, description, category, type, price, quantity,seller_id, name_shop, sold_flag)) return 0;
			if (!insert(category, object)) return 0;
			++counter;
		}
	}

	file_in.close();
	return counter;

}


// retrieve from the table
int table::retrieve(char category[], char title[], etsy & to_retrieve) const
{
	for (int i {0}; i < hash_table_size; ++i)
	{
		node * curr = hash_table[i];
		while (curr)
		{
			if (curr->etsy_object.retrieve(title, to_retrieve)) return 1;
			curr = curr->next;
		}
	}
	return 0;
}

// Display all in a specific category
int table::display_category(char category[])
{
	int count {0};
	for (int i {0}; i < hash_table_size; ++i)
	{
		node * curr = hash_table[i];
		while (curr)
		{
			if (strstr(curr->etsy_object.category, category))
			{
				curr->etsy_object.display();
				++count;
			}
			curr = curr->next;
		}

	}
	return count;

}

// Display all
int table::display_all(void) const
{
	int count {0};
	for (int i {0}; i < hash_table_size; ++i)
	{
		node * curr = hash_table[i];
		if (curr) std::cout << "\n\nChain #" << i + 1 << "\n\n";
		while (curr)
		{
			curr->etsy_object.display();
			curr = curr->next;
			++count;
		}
	}	
	return count;
}

int table::remove_entry(int seller_id)
{
	if (!seller_id) return 0;
	for (int i {0}; i < hash_table_size; ++i)
	{
		node * curr = hash_table[i];
		while (curr)
		{
			if (curr->etsy_object.seller_id == seller_id)
			{
				cout << "\nRemoving\n " << curr->etsy_object.display() << endl;
				node * hold = curr->next;
				hash_table[i] = hold;
				delete curr;
				return 1;
			}
			curr = curr->next;
		}
	}
	return 0;
}

int table::buy(char title_buy[], etsy & to_buy)
{
	if (!title_buy) return 0;
	for (int i {0}; i < hash_table_size; ++i)
	{
		node * curr = hash_table[i];
		while (curr)
		{
			if (strcmp(curr->etsy_object.title, title_buy) == 0)
			{
				curr->etsy_object.sold_flag = true;
				return 1;
			}
			curr = curr->next;
		}
	}
	return 0;
}

