// Lian Zhu
// CS302
// racer.cpp

#include "racer.h"

// exception handler constructor
BadArgument::BadArgument(const string & msg) : message(msg) {}

// exception handler destructor
BadArgument::~BadArgument() {}

// exception handler getter
const string & BadArgument::what() const
{
    return message;
}


// ============================================================
// Racer/Base Class
// ============================================================

// Default constructor
Racer::Racer() : name(""), speed(0), stamina(0)
{}

// Argument constructor
Racer::Racer(const string & name, int speed, int stamina)
    : name(name), speed(speed), stamina(stamina)
{}

// Destructor
Racer::~Racer()
{}

// get name
const string & Racer::get_name() const 
{ 
  return name;
}

// Default rest method for a racer
bool Racer::rest(int minutes)
{
    try
    {
        if (minutes < 0)
            throw BadArgument("Rest time cannot be negative");

        stamina += minutes / 2;
        return true;
    }
    catch (const BadArgument & e)
    {
        cerr << "Error: " << e.what() << endl;
        return false;
    }
}

// Default celebrate method for a racer
int Racer::celebrate() const
{
    cout << "\n" << name << " celebrates generically\n";
    return 1;
}

// Default racer display
int Racer::display() const
{
    cout << "\n-- Racer Info --\n"
         << "Name: " << name << "\n"
         << "Speed: " << speed << "\n"
         << "Stamina: " << stamina << "\n";
    return 1;
}

// Helper input function for generic racer
int Racer::input()
{
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter speed: ";
    cin >> speed;

    cout << "Enter stamina: ";
    cin >> stamina;

    cin.ignore(100, '\n');
    return 1;
}

// relational less than operator, compares names 
bool Racer::operator<(const Racer & op2) const
{
  return name < op2.name;
}

// equality operator, compares names
bool Racer::operator==(const Racer & op2) const
{
  return name == op2.name;
}

// ============================================================
// Human Class
// ============================================================

// Default constructor
Human::Human() : Racer(), motivation(""), hydration(0)
{}

// Argument constructor
Human::Human(const string & name, int speed, int stamina, const string & motivation, int hydration)
    : Racer(name, speed, stamina), motivation(motivation), hydration(hydration)
{}

// Destructor
Human::~Human()
{}

// How each human races
int Human::race()
{
    cout << name << " is sprinting, they're motivated because: " << motivation << "!\n";
    return 1;
}

// How each human rests
bool Human::rest(int minutes)
{
    try
    {
        if (minutes < 0)
            throw BadArgument("Rest time cannot be negative");

        stamina += minutes / 3;
        hydration += minutes / 2;
        return true;
    }
    catch (const BadArgument & e)
    {
        cerr << "Error: " << e.what() << endl;
        return false;
    }
}

// How each human celebrates
int Human::celebrate() const
{
    cout << name << " cheers loudly!\n";
    return 1;
}

// Display function for human
int Human::display() const
{
    Racer::display();
    cout << "Motivation: " << motivation << "\n"
         << "Hydration: " << hydration << "\n";
    return 1;
}

// Input function for human
int Human::input()
{
    Racer::input();

    cout << "Enter motivation: ";
    getline(cin, motivation);

    cout << "Enter hydration level: ";
    cin >> hydration;
    cin.ignore(100, '\n');

    return 1;
}


// ============================================================
// Dog Class
// ============================================================

// Default constructor
Dog::Dog() : Racer(), breed("Unknown"), needs_water(true)
{}

// Argument constructor
Dog::Dog(const string & name, int speed, int stamina, const string & breed, bool needs_water)
    : Racer(name, speed, stamina), breed(breed), needs_water(needs_water)
{}

// Destructor
Dog::~Dog()
{}

// How each dog races
int Dog::race()
{
    cout << name << " runs fast like a " << breed << "!\n";
    return 1;
}

// How each dog rests
bool Dog::rest(int minutes)
{
    try
    {
        if (minutes < 0)
            throw BadArgument("Rest time cannot be negative");

        stamina += minutes;
        if (needs_water)
            cout << name << " drinks water during rest.\n";
        return true;
    }
    catch (const BadArgument & e)
    {
        cerr << "Error: " << e.what() << endl;
        return false;
    }
}

// How each dog celebrates
int Dog::celebrate() const
{
    cout << name << " wags tail and barks\n";
    return 1;
}

// Display function for dog
int Dog::display() const
{
    Racer::display();
    cout << "Breed: " << breed << "\n"
         << "Needs Water: " << (needs_water ? "Yes" : "No") << "\n";
    return 1;
}

// Input function for dog
int Dog::input()
{
    Racer::input();

    cout << "Enter breed: ";
    cin.ignore(100, '\n');
    getline(cin, breed);

    cout << "Needs water? (1 = yes, 0 = no): ";
    cin >> needs_water;
    cin.ignore(100, '\n');

    return 1;
}


// ============================================================
// Robot Class
// ============================================================

// Default constructor
Robot::Robot() : Racer(), model(""), battery_level(100)
{}

// Argument constructor
Robot::Robot(const string & name, int speed, int stamina, const string & model, int battery_level)
    : Racer(name, speed, stamina), model(model), battery_level(battery_level)
{}

// Destructor
Robot::~Robot()
{}

// How each robot races
int Robot::race()
{
    cout << name << " moves mechanically" << "\n";
    return 1;
}

// How each robot rests
bool Robot::rest(int minutes)
{
    try
    {
        if (minutes < 0)
            throw BadArgument("Rest time cannot be negative");

        battery_level += minutes / 2;
        return true;
    }
    catch (const BadArgument & e)
    {
        cerr << "Error: " << e.what() << endl;
        return false;
    }
}

// How each robot celebrates
int Robot::celebrate() const
{
    cout << name << " does the robot\n";
    return 1;
}

// Display function for robot
int Robot::display() const
{
    Racer::display();
    cout << "Model: " << model << "\n"
         << "Battery Level: " << battery_level << "\n";
    return 1;
}

// Input function for robot
int Robot::input()
{
    Racer::input();

    cout << "Enter model: ";
    cin.ignore(100, '\n');
    getline(cin, model);

    cout << "Enter battery level: ";
    cin >> battery_level;
    cin.ignore(100, '\n');

    return 1;
}

// RTTI-only method for Robot
int Robot::recharge()
{
    battery_level = 100;
    cout << name << " has recharged to full\n";
    return 1;
}

