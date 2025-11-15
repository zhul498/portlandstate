// Lian Zhu
// CS302
// main.cpp

#include "tree.h"

int main()
{
  try 
  {
    Tree tree;
    int racer_choice = 4;
    
    // ADD THIS WHILE LOOP
    while (racer_choice != 0)
    {
      cout << "\nSelect a Racer\n(1) Human\n(2) Dog\n(3) Robot\n(4) Display all Racers\n(5) Race all\n(6) Celebrate all\n(0) EXIT: ";
      cin >> racer_choice;
      cin.ignore(100, '\n');
      
      // error
      if (racer_choice < 0 || racer_choice > 6)
      {
        BadArgument e("You did not select a valid option from the menu");
        throw(e);
      }
      // display 
      if (racer_choice == 4)
      {
        cout << "\n===== ALL RACERS =====\n";
        int count = tree.display();
        if (count == 0) cout << "No racers in the system yet\n";
        cout << "======================\n";
      }
      // race everyone
      else if (racer_choice == 5)
      {
        cout << "\n===== RACE TIME =====\n";
        int count = tree.race_all();
        if (count == 0) cout << "No racers to race yet.\n";
        else cout << "\nTotal racers who competed: " << count << "\n";
        cout << "=====================\n";
      }
      // celebrate everyone
      else if (racer_choice == 6)
      {
        cout << "\n===== CELEBRATE TIME =====\n";
        int count = tree.celebrate_all();
        if (count == 0) cout << "No racers to celebrate yet.\n";
        else cout << "\nTotal racers who celebrated: " << count << "\n";
        cout << "==========================\n";
      }
      // create a racer so != 0 
      else if (racer_choice != 0)
      {
        cout << "\n--- Creating New Racer ---\n";
        if (racer_choice == 1)
        {
          Racer* human = new Human;
          human->input();
          int rest_time = 0;
          cout << "\nHow many minutes should this racer rest before competing? ";
          cin >> rest_time;
          cin.ignore(100, '\n');
          if (!human->rest(rest_time))
          {
            delete human;
            BadArgument e("Failed to rest properly");
            throw(e);
          }
          // display the racer
          human->display();
          human->race();
          human->celebrate();
          // use base for tree insertion
          tree.insert(human);
          cout << "\nHuman added successfully!\n";
        }
        // dog
        else if (racer_choice == 2)
        {
          Racer* dog = new Dog;
          dog->input();
          int rest_time = 0;
          cout << "\nHow many minutes should this dog rest before competing? ";
          cin >> rest_time;
          cin.ignore(100, '\n');
          dog->rest(rest_time);
          dog->display();
          dog->race();
          dog->celebrate();
          tree.insert(dog);
          cout << "Dog racer added successfully\n";
        }
        // Robot
        else if (racer_choice == 3)
        {
          Racer* robot = new Robot;
          robot->input();
          int rest_time = 0;
          cout << "\nHow many minutes should this robot rest before competing? ";
          cin >> rest_time;
          cin.ignore(100, '\n');
          robot->rest(rest_time);
          
          // RTTI demonstration
          Robot* robot_ptr = dynamic_cast<Robot*>(robot);
          if (robot_ptr)
          {
            cout << "\nWould you like to recharge to full battery? (1 = yes, 0 = no) ";
            int recharge_choice = 0;
            cin >> recharge_choice;
            cin.ignore(100, '\n');
            if (recharge_choice == 1)
              robot_ptr->recharge();
          }
          robot->display();
          robot->race();
          robot->celebrate();
          tree.insert(robot);
          cout << "Robot added successfully\n";
        }
      }
    } 
    
    cout << "\n===== Final Roster =====\n";
    tree.display();
    cout << "\n========================\n";
    
  } 
  catch (const BadArgument& e)
  {
    cout << "\nException caught: " << e.what() << endl;
  }
  return 0;
}
