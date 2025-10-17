// Lian Zhu
// CS302 Program 1
// vendors.h
// header file in for class hierarchy


#pragma once 

#include <utility> // pair
#include <vector> // vector
#include <string> // string
#include <cstring> // strcpy
#include <iostream>

using namespace std;


class Vendor
{
	public:
		Vendor(); // Constructor
		Vendor(const Vendor &); // Copy constructor
		Vendor& operator=(const Vendor &); // Assignment op
		~Vendor(); // Destructor
		
		int displayInfo() const;
		/*
			Displays a vendors name and rating
			No params
			Returns success/fail
		*/
		int updateName(const char* newName); 
		/*
			Changes the name of a vendor
			Takes in the new name
			Returns success/fail
		*/
		int changeRating(double newRating); 
		/*
			Changes the rating of a vendor
			Takes in the new rating 
			Returns success/fail
		*/
		bool hasHigherRatingThan(const Vendor& other) const;
		/*
			Checks to see if this vendor has a higher rating than another vendor
			Takes in the other vendor
			Returns true/false
		*/
		bool compareName(char* name) const;
		/*
			Compares the name with the calling object with passed object
			Takes in the other name
			Returns true/false
		*/


	protected:
		char* name; // Name of the vendor
		double rating; // Vendors rating
		

};

class Trinket : public Vendor
{
	public:
		Trinket(); // Constructor
		~Trinket(); // Destructor

		int displayItems() const;
		/*
			Displays all items + price
			No params
			Returns success/fail
		*/
		int buyItem(const string & item);
		/*
			Allows the user to buy an item
			Takes in the item to search for and purchase
			Returns success/fail
		*/
		int addItem(const string & itemName, double price);
		/*
			Vendor restocking
			Takes in item name + price
			Returns success/fail
		*/
		int setInfo(const string & location, int numEmployees); 
		/*
			Set the location, and num employees  of the vendor
			Takes in the new location, and new numEmployees
			Returns success/fail
		*/


	private:
		vector<pair<string, double>> items; // <item, price>
		string location; // Where located
		int numEmployees; // self explanatory
};



class Cuisine: public Vendor
{
	public:	
		Cuisine(); // Constructor
		~Cuisine(); // Destructor

		int displayItems() const;
		/*
			Displays all menu items + avg price at end
			No params
			Returns success/fail
		*/
		int setMenu(vector<string> & newMenu);
		/*
			Sets the menu
			Takes in the new menu list to set it to
			Returns success/fail
		*/

		int orderDish(const string & dish);
		/*
			Allows the user to order a dish
			Takes in the item to search for and purchase
			Returns success/fail
		*/
		int addDish(const string & dish);
		/*
			Adding in a dish to the menu
			Takes in dish name
			Returns success/fail
		*/

	private:
		vector<string> menu; // menu items
		string cuisineType; // german, american, etc
		double avgPrice; // average price
		
};



class Entertainer: public Vendor
{
	public:
		Entertainer(); // Constructor
		Entertainer(const Entertainer &); // copy constructor
		Entertainer& operator=(const Entertainer &); // Assignment op
		~Entertainer(); // Destructor

			
		int changeGroupName(const char* newName);
		/*
			Changes the entertainers group name
			Takes in the new name
			Returns success/fail
		*/
		int checkInfo() const;
		/*
			Checks current audience size + performanceType
			No params
			Returns sucess/fail
		*/
		int updateInfo(const string& newType, int newSize);
		/*
			Changes type + size
			New size
			Returns sucess/fail
		*/
		int displayInfo() const;


	private:
		char* groupName; // dynamically allocated char* array for group name
		int audienceSize; // audience size
		string performanceType; // comedy, genre, etc.
};
