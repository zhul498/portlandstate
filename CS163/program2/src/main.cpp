// Lian Zhu
// CS163 Program 2
// This is the main file that will hold the client program

// Includes
#include "stack.h"
#include "queue.h"

// Using
using namespace std;

// Constants
const int CHARSIZE {50};

int main ()
{
	stack gameStack; // Stack object
	queue gameQueue; // Queue object
	gameEntry toAdd, anEntry; // Objects for a game entry
	char title[CHARSIZE]; // Character array for title input	
	char platform[CHARSIZE]; // Character array for platform input	
	char genre[CHARSIZE]; // Character array for genre input	
	char progression[CHARSIZE]; // Character array for progression input	
	char achievements[CHARSIZE]; // Character array for achievements input	
	char price[CHARSIZE]; // Character array for price input	
	char seriesName[CHARSIZE]; // Character array for the series name input
	int year {0}; // Input for the year that the series came out
	int choice {0}; // Main Menu choice 
	int displayStack {0}; // Number of items displayed in the stack
	int displayQueue {0}; // Number of items displayed in the queue
	// Main Menu
	do 
	{
		cout << "------------- MAIN MENU --------------\n\n";	
		cout << "(1) Push a game onto the stack\n";
		cout << "(2) Display the stack\n";
		cout << "(3) Pop from the stack\n";
		cout << "(4) Peek from the stack\n";
		cout << "(5) Enqueue the top of the game stack onto the queue (Add a series)\n";
		cout << "(6) Dequeue a series from the queue\n";
		cout << "(7) Peek from the queue\n";
		cout << "(8) Display the queue\n";
		cout << "(0) Quit the program\n\n\n";
		cin >> choice;
		cin.ignore(100, '\n');
		switch (choice)
		{
			case 1: // Push onto stack
				toAdd.destroy(); // deallocate whats already there
				cout << "\n\n\nENTERING A GAME\n\n\n";
				cout << "Enter title: ";
				cin.get(title, 100, '\n');
				cin.ignore(100, '\n');
				cout << "Enter platform (e.g. PS5): ";
				cin.get(platform, 100, '\n');
				cin.ignore(100, '\n');
				cout << "Enter genre (e.g. Horror): ";
				cin.get(genre, 100, '\n');
				cin.ignore(100, '\n');
				cout << "Enter progression (e.g. Linear): ";
				cin.get(progression, 100, '\n');
				cin.ignore(100, '\n');
				cout << "Enter achievements (e.g. Percentage): ";
				cin.get(achievements, 100, '\n');
				cin.ignore(100, '\n');
				cout << "Enter price: ";
				cin.get(price, 100, '\n');
				cin.ignore(100, '\n');
				if (!toAdd.createEntry(title, platform, genre, progression, achievements, price)) cout << "\nInvalid information entered!\n";
				// Push onto stack
				try
				{
					gameStack.push(toAdd);
					cout << "\n\nEntered an entry\n\n";
				}	
				catch (BAD_ENTRY)
				{
					cerr << "Failure: " << endl;
				}
				break;
			case 2: // Display stack
				cout << "\n\n\nDISPLAYING THE STACK\n\n\n";
				try 
				{
					displayStack = gameStack.display();
					cout << "\n\n\n" << displayStack << " items in the stack\n\n\n";
				}
				catch (BAD_ENTRY)
				{
					cerr << "Failure: " << endl;
				}
				break;
			case 3: // Pop from stack
				try
				{
					if (!gameStack.pop()) cout << "\n\n\nNothing to pop!\n\n\n";
					else cout << "\n\n\nPopped one item from the stack!\n\n\n";
				}
				catch (BAD_ENTRY)
				{
					cerr << "Failure: " << endl;
				}
				break;
			case 4: // Peek from stack
				try 
				{
					//gameEntry anEntry;
					if (!gameStack.peek(anEntry)) cout << "\n\n\nNothing to retrieve!\n\n\n";
					else cout << "\n\n\nRETRIEVED\n\n\n " << anEntry.display();
				}
				catch (BAD_ENTRY)
				{
					cerr << "Failure: " << endl;
				}
				break;
			case 5: // Enqueue
				cout << "\n\n\nENTERING A SERIES\n\n\n";
				cout << "Enter the series name: ";
				cin.get(seriesName, 100, '\n');
				cin.ignore(100, '\n');
				cout << "Enter the year that the series started: ";
				cin >> year;
				cin.ignore(100, '\n');
				if (!gameStack.peek(anEntry)) cout << "\nNothing to put in the queue!\n";
				if (!gameQueue.enqueue(seriesName, year, anEntry)) cout << "\nFailed to enqueue to the series " << seriesName << "\n";
				else cout << "\nEnqueued succesfully\n";
				break;
			case 6: // Dequeue
				cout << "\n\n\nDEQUEUEING\n\n\n";
				if (!gameQueue.dequeue()) cout << "\nCould not dequeue!\n";
				else cout << "\nDequeued\n";
				break;
			case 7: // Peek
				cout << "\n\n\nPEEKING FROM QUEUE\n\n\n";
				if (!gameQueue.peek(anEntry)) cout << "\n\n\nNothing to retrieve!\n\n\n";
				else cout << "\n\n\nRETRIEVED\n\n\n" << anEntry.display();
				break;
			case 8: // Display
				cout << "\n\n\nDISPLAYING THE QUEUE\n\n\n";
				displayQueue = gameQueue.display();
				cout << "\n\n\n" << displayQueue << " items in the queue\n\n\n";
				break;
			case 0: 
				cout << "\n\n\nThank you for using my program!\n\n\n";
				break;
			default: 
				cout << "\n\n\nInvalid input... Please try again...\n\n\n";
				break;
		}


	} while (choice != 0);	
	return 0;
}

