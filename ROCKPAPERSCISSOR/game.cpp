#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int choice;
    char playAgain = 'y';

    // Seed the random generator once at the very beginning outside the loop
    srand(time(0));

    cout << "Welcome to Rock Paper Scissor Game." << endl;

    // Milestone 4: Loop for Replayability
    while (playAgain == 'y' || playAgain == 'Y')
    {
        cout << "\nPlease Enter your choice:" << endl;
        cout << "0. Rock" << endl;
        cout << "1. Paper" << endl;
        cout << "2. Scissor" << endl;
        cin >> choice;
        cout << "You : " << choice;

        cout << endl;
        int computerChoice = rand() % 3;
        cout << "Computer : " << computerChoice;

        cout << endl;

        // Game Logic: Checking for Tie, Win, or Loss (0 = Rock, 1 = Paper, 2 = Scissor)
        if (choice == computerChoice)
        {
            cout << "It's a Tie!" << endl;
        }
        // Player winning conditions:
        // Rock (0) beats Scissor (2)
        // Paper (1) beats Rock (0)
        // Scissor (2) beats Paper (1)
        else if ((choice == 0 && computerChoice == 2) ||
                 (choice == 1 && computerChoice == 0) ||
                 (choice == 2 && computerChoice == 1))
        {
            cout << "Congratulations, You Win!" << endl;
        }
        else
        {
            cout << "Computer Wins! Better luck next time." << endl;
        }

        cout << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing!" << endl;

    return 0;
}