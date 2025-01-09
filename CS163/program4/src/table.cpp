// Lian Zhu
// CS163 Program 4
// This is the table implementation file

// Includes
#include "table.h"

// Constructor
table::table() 
{
	root = nullptr;
}

// Destructor
table::~table()
{
	destroy();
}

// Destroy wrapper
int table::destroy(void)
{
	return destroy(root);
}

// Destroy recursive
int table::destroy(node * & root)
{
	if (!root) return 0;
	int left_count = destroy(root->left);
	int right_count = destroy(root->right);
	delete root;
	return left_count + right_count + 1;
}


// Insert wrapper
int table::insert(etsy & to_add)
{	
	return insert(root, to_add);
}

// Insert recursive
int table::insert(node * & root, etsy & to_add)
{
	if (!root)
	{
		root = new node;
		root->left = nullptr; root->right = nullptr;
		root->etsy_object.copy_entry(to_add);
		return 1;
	}
	if (strcmp(root->etsy_object.get_title(), to_add.get_title()) >= 0)
	{
		return insert(root->right, to_add);
	}
	return insert(root->left, to_add);
}

// Display wrapper
int table::display(void) const
{
	return display(root);
}

// Display recursive
int table::display(node * root) const
{

	if (!root) return 0;
	// In order -- Do not need to + 1 because root->etsy_object.display() returns 1 for success
	return display(root->left) + root->etsy_object.display() + display(root->right);
}


// Remove wrapper
int table::remove(char title[])
{
	if (!root)
	{
		EMPTY_LIST empty;
		empty.function_name = "remove";
		throw empty;
	}
	if (!title) return 0;
	return remove(root, title);
}

// Remove recursive
int table::remove(node * & root, char title[])
{
	if (!root) return 0;
	if (strcmp(root->etsy_object.get_title(), title) > 0)
	{
		return remove(root->right, title);
	}
	else if (strcmp(root->etsy_object.get_title(), title) < 0)
	{
		return remove(root->left, title);
	}
	// Found match
	if (strcmp(root->etsy_object.get_title(), title) == 0)
	{
		// If it is a leaf node
		if (!root->left && !root->right)
		{
			delete root;
			root = nullptr;
			return 1;
		}

		// If it is not a leaf node but only 1 child
		// Right child
		else if (!root->left && root->right)
		{
			node * hold = root->right;
			delete root;
			root = hold;
			return 1;
		}
		// Left child
		else if (root->left && !root->right)
		{
			node * hold = root->left;
			delete root;
			root = hold;
			return 1;
		}
		// Two children
		else 
		{
			// Find IOS
			node * curr = root->right;
			while (curr->left)
			{
				curr = curr->left;
			}
			// Swap data & deallocate curr
			root->etsy_object.destroy();
			root->etsy_object.copy_entry(curr->etsy_object);
			auto title = curr->etsy_object.get_title();
			char temp[strlen(title) + 1];
			strcpy(temp, title);
			return remove(root->right, temp);
		}
		
	}
	return 0;
}

// Retrieve wrapper
int table::retrieve(char title[], etsy & to_retrieve)
{
	if (!root)
	{
		EMPTY_LIST empty;
		empty.function_name = "retrieve";
		throw empty;
	}
	return retrieve(root, title, to_retrieve);
}

// Retrieve recursive
int table::retrieve(node * root, char title[], etsy & to_retrieve)
{
	if (!root) return 0;
	if (strcmp(root->etsy_object.get_title(), title) > 0)
	{
		return retrieve(root->right, title, to_retrieve);
	}
	else if (strcmp(root->etsy_object.get_title(), title) < 0)
	{
		return retrieve(root->left, title, to_retrieve);
	}
	// Match found
	if (strcmp(root->etsy_object.get_title(), title) == 0)
	{
		to_retrieve.copy_entry(root->etsy_object);
		return 1;
	}
	return 0;
}

// Height wrapper
int table::find_height(void) const
{
	// Its okay to return 0 for height -- don't error check for empty list
	if (!root) return 0;
	return find_height(root);
}

// Height recursive
int table::find_height(node * root) const
{
	if (!root) return 0;
	int left = find_height(root->left);
	int right = find_height(root->right);
	return max(left, right) + 1;
}

// Range wrapper
int table::display_range(float low, float high) const
{
	// Its okay to return 0 for range -- don't error check for empty list
	if (!root) return 0;
	return display_range(root, low, high);
}

// Range recursive
int table::display_range(node * root, float low, float high) const
{
	if (!root) return 0;
	int count {0};		
	// Left subtree
	count += display_range(root->left, low, high);
	// Root
	if (root->etsy_object.get_price() >= low && root->etsy_object.get_price() <= high)
	{
		root->etsy_object.display();
		++count;
	}
	// Right subtree
	count += display_range(root->right, low, high);
	return count;
}



