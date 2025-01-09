// Lian Zhu
// CS163 Program 2
// This is the implementation file for the game entry class

// Includes
#include "games.h"
using namespace std;

// Constructor
gameEntry::gameEntry()
{
	title = nullptr;
	platform = nullptr;
	genre = nullptr;
	progression = nullptr;
	achievements = nullptr;
	price = nullptr;
}

// Destructor
gameEntry::~gameEntry()
{
	destroy();
}

void gameEntry::destroy()
{
	delete [] title;
	title = nullptr;
	delete [] platform;
	platform = nullptr;
	delete [] genre;
	genre = nullptr;
	delete [] progression;
	progression = nullptr;
	delete [] achievements;
	achievements = nullptr;
	delete [] price;
	price = nullptr;

}

// create entry
int gameEntry::createEntry(char titleToAdd[], char platformToAdd[], char genreToAdd[], char progressionToAdd[], char achievementsToAdd[], 
	char priceToAdd[])
{
	if (!titleToAdd || !platformToAdd || !genreToAdd || !progressionToAdd || !achievementsToAdd || !priceToAdd) return 0;
	
	
	// Allocate memory for entry and copy it in
	else
	{
		title = new char[strlen(titleToAdd) + 1];		
		platform = new char[strlen(platformToAdd) + 1];		
		genre = new char[strlen(genreToAdd) + 1];		
		progression = new char[strlen(progressionToAdd) + 1];		
		achievements = new char[strlen(achievementsToAdd) + 1];		
		price = new char[strlen(priceToAdd) + 1];		

		strcpy(title, titleToAdd);
		strcpy(platform, platformToAdd);
		strcpy(genre, genreToAdd);
		strcpy(progression, progressionToAdd);
		strcpy(achievements, achievementsToAdd);
		strcpy(price, priceToAdd);

		return 1;
	}

	return 0;
}

// copy entry
int gameEntry::copyEntry(const gameEntry & copyFrom)
{
	// Error handle
	if ((!copyFrom.title || !copyFrom.platform || !copyFrom.genre || !copyFrom.progression || !copyFrom.achievements || !copyFrom.price)) return 0;

	else
	{
		// Allocate memory for the copied entry
		title = new char[strlen(copyFrom.title) + 1];
		platform = new char[strlen(copyFrom.platform) + 1];
		genre = new char[strlen(copyFrom.genre) + 1];
		progression = new char[strlen(copyFrom.progression) + 1];
		achievements = new char[strlen(copyFrom.achievements) + 1];
		price = new char[strlen(copyFrom.price) + 1];		

		// Copy everything
		strcpy(title, copyFrom.title);
		strcpy(platform, copyFrom.platform);
		strcpy(genre, copyFrom.genre);
		strcpy(progression, copyFrom.progression);
		strcpy(achievements, copyFrom.achievements);
		strcpy(price, copyFrom.price);
	
		return 1;
	}

	return 0;
}

// retrieve an entry and fill found with it 
int gameEntry::retrieve(char * matchingTitle, gameEntry & found) const
{
	// Error handle	
	if (!title) return 0;
	
	// Nothing was found // invalid input
	if ((!matchingTitle) || !strcmp(title, matchingTitle)) return 0;

	// Retrieve
	found.title = new char[strlen(title) + 1];
	found.platform = new char[strlen(platform) + 1];
	found.genre = new char[strlen(genre) + 1];
	found.progression = new char[strlen(progression) + 1];
	found.achievements = new char[strlen(achievements) + 1];
	found.price = new char[strlen(price) + 1];		

	// Copy everything
	strcpy(found.title, title);
	strcpy(found.platform, platform);
	strcpy(found.genre, genre);
	strcpy(found.progression, progression);
	strcpy(found.achievements, achievements);
	strcpy(found.price, price);
	return 1;

}

// display all
int gameEntry::display(void) const
{
	if (!title || !platform || !genre || !progression || !achievements || !price)
	{
		return 0;
	}
	cout << "Title: " << title << '\n' << "Platform: " << platform << '\n' << "Genre: " << genre << '\n' << "Progresion: " << progression << '\n' 
	<< "Achievements: " << achievements << '\n' << "Price: " << price << "\n\n\n";
	return 1;
};


