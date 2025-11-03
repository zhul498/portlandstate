// Lian Zhu
// CS302
// main.cpp for program 2

#include "maze.h"
#include "DLL.h"
#include "obstacle.h"
#include <iostream>

using namespace std;

int main()
{
    char playAgain = 'y';
    
    cout << "========================================\n";
    cout << "   HAUNTED HOUSE MAZE GAME\n";
    cout << "========================================\n\n";
    
    while (playAgain == 'y' || playAgain == 'Y')
    {
        int levelChoice;
        int numObstacles;
        
        cout << "\nSelect your difficulty level:\n";
        cout << "1. Kid-Friendly Corn Maze\n";
        cout << "2. Scary Haunted House (Teen)\n";
        cout << "3. Horror Survival (Adult)\n";
        cout << "Enter choice (1-3): ";
        cin >> levelChoice;
        
        cout << "\nHow many obstacles? (5-20 recommended): ";
        cin >> numObstacles;
        
        if (numObstacles < 5) numObstacles = 5;
        if (numObstacles > 30) numObstacles = 30;
        
        switch (levelChoice)
        {
            case 1:
            {
                Maze<KidObstacle> kidMaze(KID, numObstacles);
                kidMaze.playGame();
                break;
            }
            case 2:
            {
                Maze<TeenObstacle> teenMaze(TEEN, numObstacles);
                teenMaze.playGame();
                break;
            }
            case 3:
            {
                Maze<AdultObstacle> adultMaze(ADULT, numObstacles);
                adultMaze.playGame();
                break;
            }
            default:
                cout << "Invalid choice! Defaulting to Kid mode.\n";
                Maze<KidObstacle> kidMaze(KID, numObstacles);
                kidMaze.playGame();
        }
        
        cout << "\n\nWould you like to play again? (y/n): ";
        cin >> playAgain;
    }
    
    cout << "\n\nThank you for playing the Haunted Maze Game!\n";
    
    return 0;
}
