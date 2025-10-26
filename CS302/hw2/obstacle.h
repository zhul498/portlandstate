// Lian Zhu
// CS302 Prog 2
// obstacle.h

#pragma once
#include <cstdlib> // rand 
#include <cstring>
#include <string> // std::string
#include <iostream> // i/o
#include <array>
#include <vector>

using namespace std;

class Obstacle
{
	public:
		Obstacle(); // constructor
		Obstacle(const char* name, const string & message, int difficulty); // arg constructor
		Obstacle(const Obstacle& other); // copy constructor
		~Obstacle(); // destructor

		Obstacle & operator=(const Obstacle & source); // Assignment operator

		// arithmetic operator +, moves difficulty up
		Obstacle operator+(const Obstacle & op2);
		Obstacle operator+(int op2);

		Obstacle & operator+=(const Obstacle & op2);
		Obstacle & operator+=(int steps);

		// insertion operator
		friend ostream & operator<<(ostream & out, const Obstacle & op); 

		// extraction operator
		friend istream & operator>>(istream & in, Obstacle & op); 

		// equality operator, compares everything
		bool operator==(const Obstacle & op2);

		// inequality operator, compares everything
		bool operator!=(const Obstacle & op2);

		// relational less than operator, compares difficulty
		bool operator<(const Obstacle & op2);
		bool operator<(int op2);

		// relational less than = to operator, compares difficulty
		bool operator<=(const Obstacle & op2);
		bool operator<=(int op2);

		// relational greater than operator, compares difficulty
		bool operator>(const Obstacle & op2);
		bool operator>(int op2);

		// relational greater than = to operator, compares difficulty
		bool operator>=(const Obstacle & op2);
		bool operator>=(int op2);

	protected:
		char* name; // dynamic memory, should be handled/owned by this class
		string message; // hint 
		int difficulty; // difficulty of level 
};

class KidObstacle : public Obstacle
{
	public:
		KidObstacle(); // constructor -- calls pickrandomhint to set the hint for the class.
		KidObstacle(const char* name, const array<string, 3> & hints, int maxAttempts); // arg constructro
		KidObstacle(const KidObstacle & source); // copy constructor
		KidObstacle & operator=(const KidObstacle & source); // assignment operator
		~KidObstacle(); // destructor

		// insertion operator
		friend ostream & operator<<(ostream & out, const KidObstacle & op); 

		// extraction operator
		friend istream & operator>>(istream & in, KidObstacle & op); 

	private:
		char* reward;
		array<string, 3> hints;
		int maxAttempts; 
	
};

class TeenObstacle: public Obstacle
{
	public:
		TeenObstacle(); // constructor -- calls pickrandomhint to set the hint for the class.
		TeenObstacle(vector<string> & hints, string & challengeType); // arg constructro

		// insertion operator
		friend ostream & operator<<(ostream & out, const TeenObstacle & op); 

		// extraction operator
		friend istream & operator>>(istream & in, TeenObstacle & op); 

	private:
		vector<string> hints;
		string challengeType; 

};

class AdultObstacle: public Obstacle
{
	public:
		AdultObstacle(); // constructor -- calls pickrandomhint to set the hint for the class.
		AdultObstacle(vector<string> & hints, bool isTimed); // arg constructro

		// insertion operator
		friend ostream & operator<<(ostream & out, const AdultObstacle & op); 

		// extraction operator
		friend istream & operator>>(istream & in, AdultObstacle & op); 

	private:
		vector<string> hints;
		bool isTimed; 

};

