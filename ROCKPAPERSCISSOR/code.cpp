#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Used to generate different random choices
    srand(time(0));

    int userChoice;
    int computerChoice;

    // Game keeps running until the user chooses Exit
    while (true)
    {
        cout << "\n============================\n";
        cout << "    ROCK PAPER SCISSORS\n";
        cout << "============================\n";

        cout << "\nChoose an option:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "4. Exit Game\n";

        cout << "\nEnter your choice: ";
        cin >> userChoice;

        // Exit option
        if (userChoice == 4)
        {
            cout << "\nThanks for playing!\n";
            cout << "Game ended.\n";

            break;
        }

        // Check for invalid choice
        if (userChoice < 1 || userChoice > 4)
        {
            cout << "\nInvalid choice! Please choose 1, 2, 3, or 4.\n";
            continue;
        }

        // Computer randomly chooses 1, 2, or 3
        computerChoice = rand() % 3 + 1;

        // Display user's choice
        cout << "\nYou chose: ";

        if (userChoice == 1)
        {
            cout << "Rock";
        }
        else if (userChoice == 2)
        {
            cout << "Paper";
        }
        else if (userChoice == 3)
        {
            cout << "Scissors";
        }

        // Display computer's choice
        cout << "\nComputer chose: ";

        if (computerChoice == 1)
        {
            cout << "Rock";
        }
        else if (computerChoice == 2)
        {
            cout << "Paper";
        }
        else
        {
            cout << "Scissors";
        }

        cout << "\n";

        // Decide the winner
        if (userChoice == computerChoice)
        {
            cout << "\nResult: DRAW!\n";
        }
        else if (
            (userChoice == 1 && computerChoice == 3) ||
            (userChoice == 2 && computerChoice == 1) ||
            (userChoice == 3 && computerChoice == 2))
        {
            cout << "\nResult: YOU WIN!\n";
        }
        else
        {
            cout << "\nResult: COMPUTER WINS!\n";
        }
    }

    return 0;
}