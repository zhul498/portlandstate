// Lian Zhu
// CS302 Prog 2
// maze.tpp

#include <iostream>
using namespace std;

// Constructor
template <typename T>
Maze<T>::Maze(GameLevel level, int numObstacles) 
    : gameLevel(level), currentPosition(0), totalObstacles(numObstacles), 
      movesCount(0), gameWon(false)
{
    srand(static_cast<unsigned int>(time(0)));
    generateObstacles(numObstacles);
}

// Destructor
template <typename T>
Maze<T>::~Maze()
{
    obstacleList.clear();
}

// Generate random obstacles and insert into the DLL
template <typename T>
void Maze<T>::generateObstacles(int count)
{
    for (int i = 0; i < count; ++i)
    {
        T obstacle = createRandomObstacle(i);
        obstacleList.insert(obstacle);
    }
}

// Get random names based on obstacle type
template <typename T>
string Maze<T>::getRandomName(int type) const
{
    // Kid-friendly names
    if (gameLevel == KID)
    {
        string names[] = {"Pumpkin Patch", "Candy Corn", 
                         "Ghost", "Smiling Jack-o-Lantern"};
        return names[rand() % 4];
    }
    // Teen scary names
    else if (gameLevel == TEEN)
    {
        string names[] = {"Skeleton", "Giant Spider",  
                         "Cursed Doll", "Banshee", "Creepy Doll"};
        return names[rand() % 5];
    }
    // Adult horror names
    else
    {
        string names[] = {"Asylum Patient",  
                         "Serial Killer", "Tortured Soul",
                         "Nightmare Incarnate"};
        return names[rand() % 4];
    }
}

// Get random messages based on obstacle type
template <typename T>
string Maze<T>::getRandomMessage(int type) const
{
    if (gameLevel == KID)
    {
        string messages[] = {
            "Move forward 2 spaces! You found a shortcut!",
            "Go back 1 space. Oops, wrong turn!",
            "Jump to the start! The scarecrow got confused!",
            "Move forward 3 spaces! The pumpkin helps you!",
            "Go back to the beginning! Time to try again!",
        };
        return messages[rand() % 5];
    }
    else if (gameLevel == TEEN)
    {
        string messages[] = {
            "The skeleton's curse sends you back 3 spaces!",
            "Spider web trap! Go back 2 spaces!",
            "You found a secret passage! Jump ahead 5 spaces!",
            "Cursed doll laughs at you. Stay where you are!",
            "The banshee's wail pushes you forward 2 spaces!",
        };
        return messages[rand() % 5];
    }
    else
    {
        string messages[] = {
            "Asylum nightmare! Return to the start!",
            "Chainsaw roar propels you forward 5 spaces!",
            "You escaped the killer! Advance 6 spaces!",
            "Tortured soul guides you forward 3 spaces!",
            "Death spares you this time. Forward 4 spaces!"
        };
        return messages[rand() % 5];
    }
}

// Get random difficulty
template <typename T>
int Maze<T>::getRandomDifficulty() const
{
    if (gameLevel == KID)
        return rand() % 3 + 1; // 1-3
    else if (gameLevel == TEEN)
        return rand() % 5 + 3; // 3-7
    else
        return rand() % 6 + 5; // 5-10
}

// Generic createRandomObstacle (fallback)
template <typename T>
T Maze<T>::createRandomObstacle(int index)
{
    string name = getRandomName(0);
    string message = getRandomMessage(0);
    int difficulty = getRandomDifficulty();
    
    T obstacle;
    return obstacle;
}

// Start the game
template <typename T>
void Maze<T>::startGame()
{
    cout << "\n========================================\n";
    cout << "     WELCOME TO THE HAUNTED MAZE!\n";
    cout << "========================================\n";
    
    if (gameLevel == KID)
        cout << "Level: Kid-Friendly Corn Maze\n";
    else if (gameLevel == TEEN)
        cout << "Level: Scary Haunted House\n";
    else
        cout << "Level: Horror Survival\n";
    
    cout << "Total Obstacles: " << totalObstacles << "\n";
    cout << "Goal: Reach the end of the maze!\n";
    cout << "========================================\n\n";
    
    currentPosition = 0;
    movesCount = 0;
    gameWon = false;
}

// Main game loop
template <typename T>
void Maze<T>::playGame()
{
    startGame();
    
    while (!isGameOver())
    {
        displayGameStatus();
        displayCurrentObstacle();
        
        cout << "\nChoose your action:\n";
        cout << "1. Move Forward\n";
        cout << "2. Move Backward\n";
        cout << "3. View All Obstacles\n";
        cout << "4. Jump to Start\n";
        cout << "5. Quit Game\n";
        cout << "Enter choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                moveForward();
                break;
            case 2:
                moveBackward();
                break;
            case 3:
                displayAllObstacles();
                break;
            case 4:
                jumpToStart();
                break;
            case 5:
                cout << "\nThanks for playing! Goodbye!\n";
                return;
            default:
                cout << "\nInvalid choice! Try again.\n";
        }
        
        movesCount++;
    }
    
    if (gameWon)
    {
        cout << "\n========================================\n";
        cout << "   CONGRATULATIONS! YOU WON!\n";
        cout << "========================================\n";
        cout << "Total moves: " << movesCount << "\n";
        cout << "You've escaped the haunted maze!\n";
        cout << "========================================\n";
    }
}

// Display current game status
template <typename T>
void Maze<T>::displayGameStatus() const
{
    cout << "\n--- Game Status ---\n";
    cout << "Current Position: " << currentPosition + 1 << " / " << totalObstacles << "\n";
    cout << "Moves Made: " << movesCount << "\n";
    cout << "-------------------\n";
}

// Display current obstacle
template <typename T>
void Maze<T>::displayCurrentObstacle() const
{
    cout << "\nYou are at obstacle #" << currentPosition + 1 << "\n";
    cout << "Use the menu to navigate through the maze.\n";
}

// Check if game is over
template <typename T>
bool Maze<T>::isGameOver() const
{
    return gameWon || currentPosition >= totalObstacles - 1;
}

// Move forward in the maze
template <typename T>
void Maze<T>::moveForward(int steps)
{
    currentPosition += steps;
    if (currentPosition >= totalObstacles - 1)
    {
        currentPosition = totalObstacles - 1;
        gameWon = true;
        cout << "\nYou've reached the end of the maze!\n";
    }
    else
    {
        cout << "\nMoved forward " << steps << " step(s).\n";
    }
}

// Move backward in the maze
template <typename T>
void Maze<T>::moveBackward(int steps)
{
    currentPosition -= steps;
    if (currentPosition < 0)
    {
        currentPosition = 0;
        cout << "\nYou're back at the start!\n";
    }
    else
    {
        cout << "\nMoved backward " << steps << " step(s).\n";
    }
}

// Jump to start of maze
template <typename T>
void Maze<T>::jumpToStart()
{
    currentPosition = 0;
    cout << "\nYou've been sent back to the beginning!\n";
}

// Jump to end of maze
template <typename T>
void Maze<T>::jumpToEnd()
{
    currentPosition = totalObstacles - 1;
    gameWon = true;
    cout << "\nYou've magically reached the end!\n";
}

// Display all obstacles in the maze
template <typename T>
void Maze<T>::displayAllObstacles() const
{
    cout << "\n=== All Obstacles in the Maze ===\n";
    obstacleList.displayAll();
    cout << "=================================\n";
}


// Specialized createRandomObstacle for KidObstacle
template <>
KidObstacle Maze<KidObstacle>::createRandomObstacle(int index)
{
    string name = getRandomName(0);
    string message = getRandomMessage(0);
    int difficulty = getRandomDifficulty();

    // Create rewards array
    array<string, 3> hints = {
        "Look for the friendly pumpkin!",
        "Follow the candy trail!",
        "The scarecrow knows the way!"
    };

    string rewards[] = {"Candy", "Toy", "Sticker", "Cookie", "Balloon"};
    string reward = rewards[rand() % 5];
    int maxAttempts = rand() % 3 + 2; // 2-4 attempts

    // Create the KidObstacle using arg constructor
    KidObstacle obstacle(reward.c_str(), hints, maxAttempts);

    // Set base class data using assignment operator
    Obstacle baseObstacle(name.c_str(), message, difficulty);
    Obstacle* basePtr = &obstacle;
    *basePtr = baseObstacle;

    return obstacle;
}

// Specialized createRandomObstacle for TeenObstacle
template <>
TeenObstacle Maze<TeenObstacle>::createRandomObstacle(int index)
{
    string name = getRandomName(1);
    string message = getRandomMessage(1);
    int difficulty = getRandomDifficulty();

    // Create hints vector
    vector<string> hints;
    hints.push_back("Beware of the shadows...");
    hints.push_back("The skeleton holds a secret.");
    hints.push_back("Listen to the ghostly whispers.");
    hints.push_back("Don't trust the mirrors.");

    string challengeTypes[] = {"Logic Puzzle", "Physical Challenge", "Riddle",
                               "Escape Room", "Memory Test"};
    string challengeType = challengeTypes[rand() % 5];

    // Create the TeenObstacle using arg constructor
    TeenObstacle obstacle(hints, challengeType);

    // Set base class data using assignment operator
    Obstacle baseObstacle(name.c_str(), message, difficulty);
    Obstacle* basePtr = &obstacle;
    *basePtr = baseObstacle;

    return obstacle;
}

// Specialized createRandomObstacle for AdultObstacle
template <>
AdultObstacle Maze<AdultObstacle>::createRandomObstacle(int index)
{
    string name = getRandomName(2);
    string message = getRandomMessage(2);
    int difficulty = getRandomDifficulty();

    // Create hints vector
    vector<string> hints;
    hints.push_back("Time is running out...");
    hints.push_back("Your sanity is slipping...");
    hints.push_back("There is no escape from this nightmare.");
    hints.push_back("Face your deepest fears.");
    hints.push_back("The darkness is closing in.");

    bool isTimed = (rand() % 2 == 0); // 50% chance of being timed

    // Create the AdultObstacle using arg constructor
    AdultObstacle obstacle(hints, isTimed);

    // Set base class data using assignment operator
    Obstacle baseObstacle(name.c_str(), message, difficulty);
    Obstacle* basePtr = &obstacle;
    *basePtr = baseObstacle;

    return obstacle;
}

// Explicit template instantiations
template class Maze<KidObstacle>;
template class Maze<TeenObstacle>;
template class Maze<AdultObstacle>;
