// Lian Zhu
// CS302
// maze.h
#pragma once
#include "DLL.h"
#include "obstacle.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Enum for game difficulty levels
enum GameLevel { KID, TEEN, ADULT };

// Template class for the Maze game
template <typename T>
class Maze
{
    public:
        Maze(GameLevel level, int numObstacles = 10);
        ~Maze();
        
        // Game functions
        void startGame();
        void playGame();
        void displayCurrentObstacle() const;
        bool isGameOver() const;
        
        // Movement functions
        void moveForward(int steps = 1);
        void moveBackward(int steps = 1);
        void jumpToStart();
        void jumpToEnd();
        
        // Display functions
        void displayGameStatus() const;
        void displayAllObstacles() const;
        
    private:
        DLL<T> obstacleList;
        GameLevel gameLevel;
        int currentPosition;
        int totalObstacles;
        int movesCount;
        bool gameWon;
        
        // Helper functions
        void generateObstacles(int count);
        T createRandomObstacle(int index);
        void processObstacleEffect(const T& obstacle);
        string getRandomName(int type) const;
        string getRandomMessage(int type) const;
        int getRandomDifficulty() const;
};

// Specialized template functions for different obstacle types
template <>
KidObstacle Maze<KidObstacle>::createRandomObstacle(int index);

template <>
TeenObstacle Maze<TeenObstacle>::createRandomObstacle(int index);

template <>
AdultObstacle Maze<AdultObstacle>::createRandomObstacle(int index);

#include "maze.tpp"
