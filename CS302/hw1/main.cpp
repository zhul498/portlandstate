// Lian Zhu
// main.cpp
#include "CLL.h"
#include "LLL.h"
#include "vendors.h"

using namespace std;
const int MAX_NAME_SIZE = 100;

void manageEntertainers(CLL& entertainers);
void manageCuisines(LLL& cuisines);
void manageTrinkets(vector<Trinket>& trinkets);

int main()
{
    CLL entertainers;
    LLL cuisines;
    vector<Trinket> trinkets;

    int choice = 0;

    do
    {
        cout << "\n------------ MAIN MENU ------------\n";
        cout << "(1) Manage Entertainers (CLL)\n";
        cout << "(2) Manage Cuisines (LLL)\n";
        cout << "(3) Manage Trinkets (vector)\n";
        cout << "(0) Exit program\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(100, '\n');

        switch (choice)
        {
            case 1:
                manageEntertainers(entertainers);
                break;
            case 2:
                manageCuisines(cuisines);
                break;
            case 3:
                manageTrinkets(trinkets);
                break;
            case 0:
                cout << "\nThank you for using the program!\n";
                break;
            default:
                cout << "\nInvalid input... Please try again.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}

void manageEntertainers(CLL& entertainers)
{
    int subChoice = 0;
    do
    {
        cout << "\n----- ENTERTAINERS -----\n";
        cout << "(1) Add an Entertainer\n";
        cout << "(2) Display all Entertainers\n";
        cout << "(3) Remove an Entertainer by name\n";
        cout << "(4) Retrieve and view an Entertainer\n";
        cout << "(5) Retrieve and update Entertainer info\n";
        cout << "(6) Retrieve and change Entertainer rating\n";
        cout << "(7) Compare ratings between two Entertainers\n";
        cout << "(0) Go back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> subChoice;
        cin.ignore(100, '\n');

        switch (subChoice)
        {
            case 1: // Add an Entertainer
            {
                char name[MAX_NAME_SIZE] = "";
                string type = "";
                int audience = 0;
                double rating = 0.0;

                cout << "Enter entertainer name: ";
                cin.getline(name, MAX_NAME_SIZE);
                cout << "Enter performance type: ";
                getline(cin, type);
                cout << "Enter audience size: ";
                cin >> audience;
                cout << "Enter rating: ";
                cin >> rating;
                cin.ignore(100, '\n');

                Entertainer e;
                e.updateName(name);
                e.changeGroupName(name);
                e.updateInfo(type, audience);
                e.changeRating(rating);

                C_Node node(e);
                entertainers.insert(node);
                cout << "Entertainer added!\n";
                break;
            }
            case 2: // Display all
            {
                if (!entertainers.displayAll())
                    cout << "No entertainers to display.\n";
                break;
            }
            case 3: // Remove by name
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter entertainer name to remove: ";
                cin.getline(name, MAX_NAME_SIZE);
                if (entertainers.remove(name))
                    cout << "Entertainer removed.\n";
                else
                    cout << "Entertainer not found.\n";
                break;
            }
            case 4: // Retrieve and view
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter entertainer name to retrieve: ";
                cin.getline(name, MAX_NAME_SIZE);
                
                C_Node* toRetrieve = nullptr;
                if (entertainers.retrieve(toRetrieve, name))
                {
                    cout << "\nEntertainer found:\n";
                    toRetrieve->displayInfo();
                }
                else
                    cout << "Entertainer not found.\n";
                break;
            }
            case 5: // Retrieve and update info
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter entertainer name: ";
                cin.getline(name, MAX_NAME_SIZE);
                
                C_Node* toRetrieve = nullptr;
                if (entertainers.retrieve(toRetrieve, name))
                {
                    cout << "\nCurrent info:\n";
                    toRetrieve->checkInfo();
                    
                    string newType;
                    int newSize;
                    cout << "\nEnter new performance type: ";
                    getline(cin, newType);
                    cout << "Enter new audience size: ";
                    cin >> newSize;
                    cin.ignore(100, '\n');
                    
                    if (toRetrieve->updateInfo(newType, newSize))
                        cout << "Info updated successfully!\n";
                    else
                        cout << "Failed to update info.\n";
                }
                else
                    cout << "Entertainer not found.\n";
                break;
            }
            case 6: // Retrieve and change rating
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter entertainer name: ";
                cin.getline(name, MAX_NAME_SIZE);
                
                C_Node* toRetrieve = nullptr;
                if (entertainers.retrieve(toRetrieve, name))
                {
                    cout << "Current rating: ";
                    toRetrieve->displayInfo();
                    
                    double newRating;
                    cout << "\nEnter new rating: ";
                    cin >> newRating;
                    cin.ignore(100, '\n');
                    
                    if (toRetrieve->changeRating(newRating))
                        cout << "Rating updated successfully!\n";
                    else
                        cout << "Failed to update rating.\n";
                }
                else
                    cout << "Entertainer not found.\n";
                break;
            }
            case 7: // Compare ratings
            {
                char name1[MAX_NAME_SIZE] = "";
                char name2[MAX_NAME_SIZE] = "";
                cout << "Enter first entertainer name: ";
                cin.getline(name1, MAX_NAME_SIZE);
                cout << "Enter second entertainer name: ";
                cin.getline(name2, MAX_NAME_SIZE);
                
                C_Node* e1 = nullptr;
                C_Node* e2 = nullptr;
                if (entertainers.retrieve(e1, name1) && entertainers.retrieve(e2, name2))
                {
                    if (e1->hasHigherRatingThan(*e2))
                        cout << name1 << " has a higher rating than " << name2 << "\n";
                    else if (e2->hasHigherRatingThan(*e1))
                        cout << name2 << " has a higher rating than " << name1 << "\n";
                    else
                        cout << "Both entertainers have the same rating.\n";
                }
                else
                    cout << "One or both entertainers not found.\n";
                break;
            }
            case 0:
                break;
            default:
                cout << "\nInvalid input... Please try again.\n";
                break;
        }

    } while (subChoice != 0);
}

void manageCuisines(LLL& cuisines)
{
    int subChoice = 0;
    do
    {
        cout << "\n----- CUISINES -----\n";
        cout << "(1) Add a Cuisine Vendor\n";
        cout << "(2) Display all Cuisine Vendors\n";
        cout << "(3) Remove a Cuisine Vendor by name\n";
        cout << "(4) Retrieve and view a Cuisine Vendor\n";
        cout << "(5) Retrieve and set menu\n";
        cout << "(6) Retrieve and add a dish\n";
        cout << "(7) Retrieve and order a dish\n";
        cout << "(8) Retrieve and change rating\n";
        cout << "(9) Compare ratings between two vendors\n";
        cout << "(0) Go back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> subChoice;
        cin.ignore(100, '\n');

        switch (subChoice)
        {
            case 1: // Add Cuisine
            {
                char name[MAX_NAME_SIZE] = "";
                string type = "";
                double avgPrice = 0.0;
                int numDishes = 0;
                vector<string> dishes;

                cout << "Enter cuisine vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);
                cout << "Enter cuisine type: ";
                getline(cin, type);
                cout << "Enter average price: ";
                cin >> avgPrice;
                cin.ignore(100, '\n');

                cout << "Enter number of dishes: ";
                cin >> numDishes;
                cin.ignore(100, '\n');

                for (int i = 0; i < numDishes; ++i)
                {
                    string dish = "";
                    cout << "Enter dish " << i + 1 << ": ";
                    getline(cin, dish);
                    dishes.push_back(dish);
                }

                Cuisine c;
                c.updateName(name);
                c.setMenu(dishes);
                c.changeRating(avgPrice);

                cuisines.insert(c);
                cout << "Cuisine vendor added!\n";
                break;
            }
            case 2: // Display all
            {
                if (!cuisines.displayAll())
                    cout << "No cuisine vendors to display.\n";
                break;
            }
            case 3: // Remove by name
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter cuisine vendor name to remove: ";
                cin.getline(name, MAX_NAME_SIZE);
                if (cuisines.remove(name))
                    cout << "Cuisine vendor removed.\n";
                else
                    cout << "Cuisine vendor not found.\n";
                break;
            }
            case 4: // Retrieve and view
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter cuisine vendor name to retrieve: ";
                cin.getline(name, MAX_NAME_SIZE);
                
                L_Node* toRetrieve = nullptr;
                if (cuisines.retrieve(toRetrieve, name))
                {
                    cout << "\nCuisine vendor found:\n";
                    toRetrieve->displayItems();
                }
                else
                    cout << "Cuisine vendor not found.\n";
                break;
            }
            case 5: // Retrieve and set menu
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter cuisine vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);
                
                L_Node* toRetrieve = nullptr;
                if (cuisines.retrieve(toRetrieve, name))
                {
                    int numDishes;
                    vector<string> newMenu;
                    cout << "Enter number of dishes for new menu: ";
                    cin >> numDishes;
                    cin.ignore(100, '\n');
                    
                    for (int i = 0; i < numDishes; ++i)
                    {
                        string dish;
                        cout << "Enter dish " << i + 1 << ": ";
                        getline(cin, dish);
                        newMenu.push_back(dish);
                    }
                    
                    if (toRetrieve->setMenu(newMenu))
                        cout << "Menu set successfully!\n";
                    else
                        cout << "Failed to set menu.\n";
                }
                else
                    cout << "Cuisine vendor not found.\n";
                break;
            }
            case 6: // Retrieve and add dish
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter cuisine vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);
                
                L_Node* toRetrieve = nullptr;
                if (cuisines.retrieve(toRetrieve, name))
                {
                    string dish;
                    cout << "Enter dish name to add: ";
                    getline(cin, dish);
                    
                    if (toRetrieve->addDish(dish))
                        cout << "Dish added successfully!\n";
                    else
                        cout << "Dish already exists in menu.\n";
                }
                else
                    cout << "Cuisine vendor not found.\n";
                break;
            }
            case 7: // Retrieve and order dish
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter cuisine vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);
                
                L_Node* toRetrieve = nullptr;
                if (cuisines.retrieve(toRetrieve, name))
                {
                    string dish;
                    cout << "Enter dish name to order: ";
                    getline(cin, dish);
                    
                    if (toRetrieve->orderDish(dish))
                        cout << "Dish is available! Order placed.\n";
                    else
                        cout << "Dish not found on menu.\n";
                }
                else
                    cout << "Cuisine vendor not found.\n";
                break;
            }
            case 8: // Retrieve and change rating
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter cuisine vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);
                
                L_Node* toRetrieve = nullptr;
                if (cuisines.retrieve(toRetrieve, name))
                {
                    double newRating;
                    cout << "Enter new rating: ";
                    cin >> newRating;
                    cin.ignore(100, '\n');
                    
                    if (toRetrieve->changeRating(newRating))
                        cout << "Rating updated successfully!\n";
                    else
                        cout << "Failed to update rating.\n";
                }
                else
                    cout << "Cuisine vendor not found.\n";
                break;
            }
            case 9: // Compare ratings
            {
                char name1[MAX_NAME_SIZE] = "";
                char name2[MAX_NAME_SIZE] = "";
                cout << "Enter first vendor name: ";
                cin.getline(name1, MAX_NAME_SIZE);
                cout << "Enter second vendor name: ";
                cin.getline(name2, MAX_NAME_SIZE);
                
                L_Node* v1 = nullptr;
                L_Node* v2 = nullptr;
                if (cuisines.retrieve(v1, name1) && cuisines.retrieve(v2, name2))
                {
                    if (v1->hasHigherRatingThan(*v2))
                        cout << name1 << " has a higher rating than " << name2 << "\n";
                    else if (v2->hasHigherRatingThan(*v1))
                        cout << name2 << " has a higher rating than " << name1 << "\n";
                    else
                        cout << "Both vendors have the same rating.\n";
                }
                else
                    cout << "One or both vendors not found.\n";
                break;
            }
            case 0:
                break;
            default:
                cout << "\nInvalid input... Please try again.\n";
                break;
        }

    } while (subChoice != 0);
}

void manageTrinkets(vector<Trinket>& trinkets)
{
    int subChoice = 0;
    do
    {
        cout << "\n----- TRINKETS -----\n";
        cout << "(1) Add a Trinket Vendor\n";
        cout << "(2) Display all Trinket Vendors\n";
        cout << "(3) Remove a Trinket Vendor by name\n";
        cout << "(4) Find and display a Trinket Vendor\n";
        cout << "(5) Find and add item to inventory\n";
        cout << "(6) Find and buy item\n";
        cout << "(7) Find and update vendor info\n";
        cout << "(8) Find and change rating\n";
        cout << "(9) Compare ratings between two vendors\n";
        cout << "(0) Go back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> subChoice;
        cin.ignore(100, '\n');

        switch (subChoice)
        {
            case 1: // Add Trinket
            {
                char name[MAX_NAME_SIZE] = "";
                string location = "";
                int numEmployees = 0;
                int numItems = 0;

                cout << "Enter trinket vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);
                cout << "Enter location: ";
                getline(cin, location);
                cout << "Enter number of employees: ";
                cin >> numEmployees;
                cin.ignore(100, '\n');
                cout << "Enter number of items: ";
                cin >> numItems;
                cin.ignore(100, '\n');

                Trinket t;
                t.updateName(name);
                t.setInfo(location, numEmployees);

                for (int i = 0; i < numItems; ++i)
                {
                    string itemName = "";
                    double price = 0.0;
                    cout << "Enter item name: ";
                    getline(cin, itemName);
                    cout << "Enter price: ";
                    cin >> price;
                    cin.ignore(100, '\n');
                    t.addItem(itemName, price);
                }

                trinkets.push_back(t);
                cout << "Trinket vendor added!\n";
                break;
            }
            case 2: // Display all
            {
                if (trinkets.empty())
                    cout << "No trinket vendors to display.\n";
                else
                {
                    for (auto & t : trinkets)
                        t.displayItems();
                }
                break;
            }
            case 3: // Remove by name
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter trinket vendor name to remove: ";
                cin.getline(name, MAX_NAME_SIZE);

                bool found = false;
                for (auto it = trinkets.begin(); it != trinkets.end(); ++it)
                {
                    if (it->compareName(name))
                    {
                        trinkets.erase(it);
                        found = true;
                        cout << "Trinket vendor removed.\n";
                        break;
                    }
                }

                if (!found)
                    cout << "Trinket vendor not found.\n";
                break;
            }
            case 4: // Find and display
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter trinket vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);

                bool found = false;
                for (auto & t : trinkets)
                {
                    if (t.compareName(name))
                    {
                        cout << "\nTrinket vendor found:\n";
                        t.displayItems();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Trinket vendor not found.\n";
                break;
            }
            case 5: // Find and add item
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter trinket vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);

                bool found = false;
                for (auto & t : trinkets)
                {
                    if (t.compareName(name))
                    {
                        string itemName;
                        double price;
                        cout << "Enter item name: ";
                        getline(cin, itemName);
                        cout << "Enter price: ";
                        cin >> price;
                        cin.ignore(100, '\n');

                        if (t.addItem(itemName, price))
                            cout << "Item added to inventory!\n";
                        else
                            cout << "Item already exists or invalid input.\n";
                        
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Trinket vendor not found.\n";
                break;
            }
            case 6: // Find and buy item
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter trinket vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);

                bool found = false;
                for (auto & t : trinkets)
                {
                    if (t.compareName(name))
                    {
                        cout << "\nCurrent inventory:\n";
                        t.displayItems();
                        
                        string itemName;
                        cout << "\nEnter item name to buy: ";
                        getline(cin, itemName);

                        if (t.buyItem(itemName))
                            cout << "Item purchased and removed from inventory!\n";
                        else
                            cout << "Item not found in inventory.\n";
                        
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Trinket vendor not found.\n";
                break;
            }
            case 7: // Find and update info
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter trinket vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);

                bool found = false;
                for (auto & t : trinkets)
                {
                    if (t.compareName(name))
                    {
                        string location;
                        int numEmployees;
                        cout << "Enter new location: ";
                        getline(cin, location);
                        cout << "Enter new number of employees: ";
                        cin >> numEmployees;
                        cin.ignore(100, '\n');

                        if (t.setInfo(location, numEmployees))
                            cout << "Vendor info updated!\n";
                        else
                            cout << "Invalid input.\n";
                        
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Trinket vendor not found.\n";
                break;
            }
            case 8: // Find and change rating
            {
                char name[MAX_NAME_SIZE] = "";
                cout << "Enter trinket vendor name: ";
                cin.getline(name, MAX_NAME_SIZE);

                bool found = false;
                for (auto & t : trinkets)
                {
                    if (t.compareName(name))
                    {
                        double newRating;
                        cout << "Enter new rating: ";
                        cin >> newRating;
                        cin.ignore(100, '\n');

                        if (t.changeRating(newRating))
                            cout << "Rating updated!\n";
                        else
                            cout << "Invalid rating.\n";
                        
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Trinket vendor not found.\n";
                break;
            }
            case 9: // Compare ratings
            {
                char name1[MAX_NAME_SIZE] = "";
                char name2[MAX_NAME_SIZE] = "";
                cout << "Enter first vendor name: ";
                cin.getline(name1, MAX_NAME_SIZE);
                cout << "Enter second vendor name: ";
                cin.getline(name2, MAX_NAME_SIZE);

                Trinket* v1 = nullptr;
                Trinket* v2 = nullptr;

                for (auto & t : trinkets)
                {
                    if (t.compareName(name1)) v1 = &t;
                    if (t.compareName(name2)) v2 = &t;
                }

                if (v1 && v2)
                {
                    if (v1->hasHigherRatingThan(*v2))
                        cout << name1 << " has a higher rating than " << name2 << "\n";
                    else if (v2->hasHigherRatingThan(*v1))
                        cout << name2 << " has a higher rating than " << name1 << "\n";
                    else
                        cout << "Both vendors have the same rating.\n";
                }
                else
                    cout << "One or both vendors not found.\n";
                break;
            }
            case 0:
                break;
            default:
                cout << "\nInvalid input... Please try again.\n";
                break;
        }

    } while (subChoice != 0);
}
