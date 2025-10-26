// Lian Zhu
// CS302 
// obstacle.cpp

#include "obstacle.h"

// Constructor
Obstacle::Obstacle() : name(nullptr), message(""), difficulty(0)
{

}

// Arg constructor
Obstacle::Obstacle(const char* name, const string & message, int difficulty) : name(nullptr), message(message), difficulty(difficulty)
{
	if (name)
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
	}
}

// Copy constructor
Obstacle::Obstacle(const Obstacle & source) : name(nullptr), message(source.message), difficulty(source.difficulty)
{
	if (source.name)
	{
		this->name = new char[strlen(source.name)+1];
		strcpy(this->name, source.name);
	}

}

// Destructor
Obstacle::~Obstacle()
{
	delete [] name;
	name = nullptr;
}


// assignment operator
Obstacle& Obstacle::operator=(const Obstacle& source)
{
	if (this == &source) return *this;
	if (this->name) delete [] this->name;
	this->name = nullptr;

	if (source.name)
	{
		this->name = new char[strlen(source.name)+1];
		strcpy(this->name, source.name);
	}
	this->message = source.message;
	this->difficulty = source.difficulty;
	return *this;
}


// arithmeti coperator +, moves difficult up
Obstacle Obstacle::operator+(const Obstacle& op2)
{
	return Obstacle(name, message, difficulty + op2.difficulty);

}

// arithmeti coperator +, moves difficult up
Obstacle Obstacle::operator+(int op2)
{
	return Obstacle(name, message, difficulty + op2);
}

// compount assignment operator (+=)
Obstacle & Obstacle::operator+=(const Obstacle & op2)
{
	difficulty += op2.difficulty;
	return *this;
}
Obstacle & Obstacle::operator+=(int op2)
{
	difficulty+=op2;
	return *this;
}

// insertion operator
ostream & operator << (ostream & out, const Obstacle & op)
{
	out << "Name: " << op.name << "\nMessage: " << op.message << "\nDifficulty: " << op.difficulty;
	return out;

}

// extraction operator
istream & operator >> (istream & in, Obstacle & op)
{
	string tempName;
	in >> ws;
	getline(in, tempName);
	getline(in, op.message);

	in >> op.difficulty;
	
	if (op.name)
	{
		delete [] op.name;
		op.name =  nullptr;
	}

	op.name = new char[tempName.length()+1];
	strcpy(op.name, tempName.c_str());

	return in;
}

// Equality operator, compares name
bool Obstacle::operator==(const Obstacle & op2)
{
	if (strcmp(name, op2.name) != 0) return false;
	if (message != op2.message) return false;
	if (difficulty != op2.difficulty) return false;
	return true;
}

// inequality operator
bool Obstacle::operator!=(const Obstacle & op2)
{
	return !(*this == op2);
}

// relational less than operator, compares difficulty
bool Obstacle::operator<(const Obstacle & op2)
{
	return difficulty < op2.difficulty;
}

bool Obstacle::operator<(int op2)
{
	return difficulty < op2;
}

// relational less than equal to operator, compares difficulty
bool Obstacle::operator<=(const Obstacle & op2)
{
	return difficulty <= op2.difficulty;
}

bool Obstacle::operator<=(int op2)
{
	return difficulty <= op2;
}


// relational greater than operator, compares difficulty
bool Obstacle::operator>(const Obstacle & op2)
{
	return difficulty > op2.difficulty;
}

bool Obstacle::operator>(int op2)
{
	return difficulty > op2;
}

// relational greater than equal to operator, compares difficulty
bool Obstacle::operator>=(const Obstacle & op2)
{
	return difficulty >= op2.difficulty;
}

bool Obstacle::operator>=(int op2)
{
	return difficulty >= op2;
}


// Constructor for kidobstacle derived
KidObstacle::KidObstacle() : reward(nullptr), hints({}), maxAttempts(0)
{

}

// Arg constructor
KidObstacle::KidObstacle(const char* reward, const array<string, 3> & hints, int maxAttempts) : reward(nullptr), hints(hints), maxAttempts(maxAttempts)
{
	if (reward)
	{
		this->reward= new char[strlen(reward)+1];
		strcpy(this->reward, reward);
	}
}

// Copy constructor
KidObstacle::KidObstacle(const KidObstacle & source) : Obstacle(source), reward(nullptr), hints(source.hints), maxAttempts(source.maxAttempts)
{
	if (source.reward)
	{
		reward = new char[strlen(source.reward)+1];
		strcpy(reward, source.reward);
	}
	else reward = nullptr;
}


// assignment operator
KidObstacle & KidObstacle::operator=(const KidObstacle & source)
{
	if (this == &source) return *this;
	if (this->reward) delete [] this->reward;
	this->reward= nullptr;

	if (source.reward)
	{
		this->reward= new char[strlen(source.reward)+1];
		strcpy(this->reward, source.reward);
	}
	this->hints = source.hints;
	this->maxAttempts = source.maxAttempts;
	return *this;
}

// destructor
KidObstacle::~KidObstacle()
{
	delete [] reward;
	reward = nullptr;
}

// insertion operator
ostream & operator<<(ostream & out, const KidObstacle & op)
{
	// base class
	out << static_cast<const Obstacle&>(op);
	// the rest
	out << "\nReward: " << (op.reward ? op.reward : "None");
	out << "\nMaxAttempts: " << op.maxAttempts;
	out << "\nHints: ";
	for (const auto & x : op.hints)
	{
		out << x << "\n";
	}
	return out;
}

// extraction operator
istream & operator>>(istream & in, KidObstacle& op)
{
	in >> static_cast<Obstacle&>(op);

	string tempReward;
	in >> ws;
	getline(in, tempReward);
	if (op.reward) delete [] op.reward;
	if (!tempReward.empty())
	{
		op.reward = new char[tempReward.length()+1];
		strcpy(op.reward, tempReward.c_str());
	} 
	else op.reward = nullptr;

	in >> op.maxAttempts;
	
	for (auto & x : op.hints)
	{
		in >> ws;
		getline(in, x);
	}

	return in;
}


//Constructor 
TeenObstacle::TeenObstacle() : hints({}), challengeType("")
{
	
}

// arg constructor
TeenObstacle::TeenObstacle(vector<string> & hints, string & challengeType) : hints(hints), challengeType(challengeType)
{

}

// insertion operator
ostream & operator<<(ostream & out, const TeenObstacle & op)
{
	// base class
	out << static_cast<const Obstacle&>(op);
	// the rest
	out << op.hints.size() << "\n";
	for (const auto & x : op.hints)
	{
		out << x << "\n";
	}
	out << op.challengeType << "\n";
	return out;
}

// extraction operator
istream & operator>>(istream & in, TeenObstacle& op)
{
	in >> static_cast<Obstacle&>(op);

	string tempChallenge;
	in >> ws;
	getline(in, tempChallenge);
	in.ignore(100, '\n'); // newline skip
	op.challengeType = tempChallenge;
	int nHints = 0;
	in >> nHints;
	
	op.hints.clear();
	for (int i = 0; i < nHints; ++i)
	{
		string hint;
		getline(in, hint);
		op.hints.push_back(hint);
	}
	return in;
}

// constructor for Adultobsacle derived class
AdultObstacle::AdultObstacle() : hints({}), isTimed(false)
{
	
}

// arg constructor
AdultObstacle::AdultObstacle(vector<string> & hints, bool isTimed) : hints(hints), isTimed(isTimed)
{
	
}

// insertion 
ostream & operator<<(ostream & out, const AdultObstacle & op)
{
	// base class
	out << static_cast<const Obstacle&>(op);
	// the rest
	for (const auto & x : op.hints)
	{
		out << x << "\n";
	}
	out << "Is timed?: " << op.isTimed;
	return out;
}

// extraction
istream & operator>>(istream & in, AdultObstacle & op)
{
	in >> static_cast<Obstacle&>(op);

	in >> op.isTimed;
	in.ignore(100, '\n');

	int nHints = 0;
	in >> nHints;
	in.ignore(100, '\n'); 
	
	op.hints.clear();
	for (int i = 0; i < nHints; ++i)
	{
		string hint;
		getline(in, hint);
		op.hints.push_back(hint);
	}
	return in;

}
