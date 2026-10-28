#include <iostream>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()

using namespace std;

int main()
{
    cout << "\nWelcome to Dice Simulator.\n";

    // Seed the random number generator so the sequence changes every time you run the app
    srand(static_cast<unsigned int>(time(0)));

    int choice = -1;
    while (choice != 0)
    {
        cout << "\n1. Roll The Dice\n";
        cout << "0. Exit\n";
        cout << "Enter your choice here: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Generate a random number between 1 and 6
            int roll = (rand() % 6) + 1;
            cout << "\n--------------------\n";
            cout << "🎲 You rolled a: " << roll << "!\n";
            cout << "--------------------\n";
            break;
        }
        case 0:
            cout << "\nExiting Dice Simulator. Goodbye!\n";
            break;

        default:
            cout << "\nInvalid choice! Please enter 1 or 0.\n";
            break;
        }
    }
    cout << endl;

    return 0;
}