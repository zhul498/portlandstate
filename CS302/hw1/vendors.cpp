// Lian Zhu
// CS302 Program 1
// vendors.cpp
// Implementation file for vendors.cpp

#include "vendors.h"

// --------------------------- VENDOR IMPLEMENTATION -------------------------------- 
// Constructor
Vendor::Vendor() : name(nullptr), rating(0.0)
{

}

// CC
Vendor::Vendor(const Vendor& source) : name(nullptr), rating(0.0)
{
	if (source.name)
	{
		this->name = new char[strlen(source.name) + 1];
		strcpy(this->name, source.name);
	}
	this->rating = source.rating;

}

// assignment op
Vendor& Vendor::operator=(const Vendor& source)
{
	if (this == &source) return *this;
	if (this->name) delete [] this->name;
	this->name = nullptr;

	if (source.name)
	{
		this->name = new char[strlen(source.name) + 1];
		strcpy(this->name, source.name);
	}
	this->rating = source.rating;
	return *this;

}


// Destructor
Vendor::~Vendor() 
{
	if (this->name) delete [] name;

}

// Display Info
int Vendor::displayInfo() const
{
	if (!name || rating < 0.0) return 0;
	cout << "\nName: " << name << "\nRating: " << rating << "\n";
	return 1;
}

// Update name
int Vendor::updateName(const char* newName)
{
	if (!newName) return 0;
	if (this->name) 
	{
		delete [] this->name;
	}
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
	return 1;
}

// Change rating
int Vendor::changeRating(double newRating)
{
	if (newRating < 0.0) return 0;
	this->rating = newRating;
	return 1;

}
// has higher rating
bool Vendor::hasHigherRatingThan(const Vendor& other) const
{
	if (this->rating > other.rating) return true;
	return false;

}

bool Vendor::compareName(char* name) const
{
	if (strcmp(this->name, name) == 0) return true;
	return false;
}


// --------------------------- VENDOR IMPLEMENTATION -------------------------------- 

// --------------------------- TRINKET IMPLEMENTATION -------------------------------- 
Trinket::Trinket() : items(), location(""), numEmployees(0)
{
}
Trinket::~Trinket()
{

}
int Trinket::displayItems() const
{
	if (!Vendor::displayInfo()) return 0;
	if (items.empty()) return 0;
	int count = 0;
	for (auto x : items) 
	{
		cout << x.first << ": $" << x.second << "\n"; 
		++count;
	}
	return count;
}
int Trinket::buyItem(const string & item)
{
	if (item.empty()) return 0;
	for (long unsigned int i = 0; i < items.size(); ++i)
	{
		if (items[i].first == item)
		{
			auto it = items.begin() + i;
			items.erase(it);
			return 1;	
		}
	}
	return 0;
}
int Trinket::addItem(const string & itemName, double price)
{
	if (itemName.empty() || price < 0.0) return 0;

	// if already exists
	for (const auto & x : items)
	{
		if (x.first == itemName) return 0;
	}
	items.push_back({itemName, price});
	return 1;

}

int Trinket::setInfo(const string & location, int numEmployees)
{
	if (location.empty() || numEmployees < 0) return 0;
	this->location = location;
	this->numEmployees = numEmployees;
	return 1;

}
// --------------------------- TRINKET IMPLEMENTATION -------------------------------- 


// --------------------------- CUISINE IMPLEMENTATION -------------------------------- 
Cuisine::Cuisine() : menu(), cuisineType(""), avgPrice(0.0)
{

}
Cuisine::~Cuisine()
{

}

int Cuisine::displayItems() const
{
	if (!Vendor::displayInfo()) return 0;
	if (menu.empty()) return 0;
	int count = 0;
	for (string x : menu)
	{
		cout << "Item #" << count + 1 << ": " << x << "\n";
		++count;
	}
	return count;

}
int Cuisine::setMenu(vector<string> & newMenu)
{
	if (newMenu.empty()) return 0;
	menu = newMenu;
	return newMenu.size();

}

int Cuisine::orderDish(const string & dish)
{
	for (const string & x : menu)
	{
		if (x == dish) return 1;
	}
	return 0;

}
int Cuisine::addDish(const string & dish)
{
	for (const string & x : menu)
	{
		if (x == dish) return 0;
	}
	menu.push_back(dish);
	return 1;
}
// --------------------------- CUISINE IMPLEMENTATION -------------------------------- 

// --------------------------- ENTERTAINER IMPLEMENTATION -------------------------------- 
Entertainer::Entertainer() : groupName(nullptr), audienceSize(0), performanceType("")
{
}


Entertainer::Entertainer(const Entertainer & source) : Vendor(source), groupName(nullptr), audienceSize(0), performanceType("")
{
	if (source.groupName)
	{
		this->groupName = new char[strlen(source.groupName) + 1];
		strcpy(this->groupName, source.groupName);
	}
	this->audienceSize = source.audienceSize;
	this->performanceType = source.performanceType;
}

Entertainer& Entertainer::operator=(const Entertainer & source)
{
	if (this == &source) return *this;
	if (this->groupName) delete [] this->groupName;
	this->groupName = nullptr;
	if (source.groupName)
	{
		this->groupName = new char[strlen(source.groupName) + 1];
		strcpy(this->groupName, source.groupName);
	}
	this->audienceSize = source.audienceSize;
	this->performanceType = source.performanceType;
	Vendor::operator=(source);
	return *this;
}

Entertainer::~Entertainer()
{
	if (groupName) delete [] groupName;
}

int Entertainer::changeGroupName(const char* newName)
{
	if (!newName) return 0;
	if (this->groupName) delete [] this->groupName;
	this->groupName = new char[strlen(newName) + 1];
	strcpy(this->groupName, newName);
	return 1;
	
}

int Entertainer::checkInfo() const
{
	if (!Vendor::displayInfo()) return 0;
	if (!groupName || audienceSize < 0 || performanceType.empty()) return 0;
	cout << "Group name: " << groupName << "\nAudience size: " << audienceSize << "\nPerformance type: " << performanceType << "\n";
	return 1;
}

int Entertainer::updateInfo(const string& newType, int newSize)
{
	if (newType.empty() || newSize < 0) return 0;
	this->performanceType = newType;
	this->audienceSize = newSize;
	return 1;
}

int Entertainer::displayInfo() const
{
	if (!Vendor::displayInfo()) return 0;
	cout << "Entertainer name: " << groupName << "\n";
	cout << "Audience size: " << audienceSize << "\n";
	cout << "Performance genre: " << performanceType << "\n";
	return 1;
}

// --------------------------- ENTERTAINER IMPLEMENTATION -------------------------------- 
