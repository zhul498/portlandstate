// Lian Zhu
// CS302
// racer.h

#pragma once
#include <string>
#include <iostream>
using namespace std;


// exception handling -- bad argument
class BadArgument 
{
	public:
		BadArgument(const string& msg);
		~BadArgument();

		const string & what() const; // return the message

	private:
		string message;
};

// 
class Racer
{
	public:
		Racer(); // Default constructor
		Racer(const string & name, int speed, int stamina); // Argument constructor
		virtual ~Racer(); // Destructor
		
		// virtual methods for dynamic binding
		virtual int race() = 0; // How each racer races
		virtual bool rest(int minutes); // Rest for minutes minutes
		virtual int celebrate() const; // How each racer celebrates
		virtual int display() const;
		virtual int input();

    const string & get_name() const; // getter for Balanced Tree

    // comparison operator for inserting keys, only < needed 
    virtual bool operator<(const Racer & op2) const;

    // equliaty operator for finding keys in a node
    virtual bool operator==(const Racer & op2) const;

    
		

	protected:
		string name;
		int speed;
		int stamina;
		
};


class Human : public Racer
{
	public:
		Human(); // Default constructor
		Human(const string& name, int speed, int stamina, const string & motivation, int hydration); // Argument constructor
		~Human(); // copy constructor
		int race() override; // How each racer races
		bool rest(int minutes) override; // Rest for minutes minutes
		int celebrate() const override; // How each racer celebrates
		int display() const override; 
		int input() override;

	private:
		string motivation;
		int hydration;
};

class Dog : public Racer
{
	public:
		Dog(); // Default constructor
		Dog(const string & name, int speed, int stamina, const string & breed, bool needs_water); // Argument constructor
		~Dog(); // copy constructor
		int race() override; // How each racer races
		bool rest(int minutes) override; // Rest for minutes minutes
		int celebrate() const override; // How each racer celebrates
		int display() const override; 
		int input() override;
	private:
		string breed;
		bool needs_water;

};

class Robot : public Racer
{
	public:
		Robot(); // Default constructor
		Robot(const string & name, int speed, int stamina, const string & model, int battery_level); // Argument constructor
		~Robot(); // copy constructor
		int race() override; // How each racer races
		bool rest(int minutes) override; // Rest for minutes minutes
		int celebrate() const override; // How each racer celebrates
		int display() const override; 
		int input() override;

		int recharge(); // Extra method for RTTI
	private:
		string model;
		int battery_level;
};

