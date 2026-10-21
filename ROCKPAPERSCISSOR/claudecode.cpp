#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

// ---------- Constants and types ----------
// enum gives names to numbers, so the code reads like English.
enum Move { ROCK = 0, PAPER = 1, SCISSOR = 2 };
enum Result { TIE, PLAYER_WIN, COMPUTER_WIN };

const int QUIT = -1; // special value meaning "player wants to stop"

// struct groups related variables together.
struct Stats
{
    int playerWins = 0;
    int computerWins = 0;
    int ties = 0;
    int rounds = 0;
    int currentStreak = 0; // current win streak of the player
    int bestStreak = 0;
};

// ---------- Small helper functions ----------
string getName(int move)
{
    if (move == ROCK) return "Rock";
    if (move == PAPER) return "Paper";
    return "Scissor";
}

int getComputerMove()
{
    return rand() % 3; // 0, 1 or 2
}

Result getWinner(int player, int computer)
{
    if (player == computer)
        return TIE;

    // Rock beats Scissor, Paper beats Rock, Scissor beats Paper
    if ((player == ROCK && computer == SCISSOR) ||
        (player == PAPER && computer == ROCK) ||
        (player == SCISSOR && computer == PAPER))
        return PLAYER_WIN;

    return COMPUTER_WIN;
}

// Reads a whole line. Returns false if input has ended (Ctrl+D / Ctrl+Z).
// getline reads everything the user typed, so bad input like "abc"
// can never put cin into a broken state.
bool readLine(string &line)
{
    return static_cast<bool>(getline(cin, line));
}

// Keeps asking until the player gives a valid move.
// Accepts: 0/1/2 or r/p/s (any case). 'q' quits. Returns the move or QUIT.
int readPlayerMove()
{
    string line;
    while (true)
    {
        cout << "\nYour choice:" << endl;
        cout << "  0 or r = Rock" << endl;
        cout << "  1 or p = Paper" << endl;
        cout << "  2 or s = Scissor" << endl;
        cout << "  q      = Quit this game" << endl;
        cout << "> ";

        if (!readLine(line))
            return QUIT;

        if (line.size() == 1)
        {
            char c = tolower(line[0]);
            if (c == '0' || c == 'r') return ROCK;
            if (c == '1' || c == 'p') return PAPER;
            if (c == '2' || c == 's') return SCISSOR;
            if (c == 'q') return QUIT;
        }
        cout << "Invalid choice! Please try again." << endl;
    }
}

// Keeps asking until the player answers y or n.
bool askYesNo(const string &question)
{
    string line;
    while (true)
    {
        cout << question << " (y/n): ";
        if (!readLine(line))
            return false;

        if (line.size() == 1)
        {
            char c = tolower(line[0]);
            if (c == 'y') return true;
            if (c == 'n') return false;
        }
        cout << "Please type y or n." << endl;
    }
}

// ---------- Score handling ----------
void updateStats(Stats &stats, Result result)
{
    stats.rounds++;

    if (result == PLAYER_WIN)
    {
        stats.playerWins++;
        stats.currentStreak++;
        if (stats.currentStreak > stats.bestStreak)
            stats.bestStreak = stats.currentStreak;
    }
    else if (result == COMPUTER_WIN)
    {
        stats.computerWins++;
        stats.currentStreak = 0;
    }
    else
    {
        stats.ties++; // a tie does not break the streak
    }
}

void printStats(const Stats &stats)
{
    cout << "\n===== SCOREBOARD =====" << endl;
    cout << "Rounds played : " << stats.rounds << endl;
    cout << "You won       : " << stats.playerWins << endl;
    cout << "Computer won  : " << stats.computerWins << endl;
    cout << "Ties          : " << stats.ties << endl;
    cout << "Best streak   : " << stats.bestStreak << endl;

    if (stats.rounds > 0)
    {
        double winRate = 100.0 * stats.playerWins / stats.rounds;
        cout << "Win rate      : " << winRate << "%" << endl;
    }
    cout << "======================" << endl;
}

// ---------- One full game ----------
// winsNeeded = 0 means endless mode (play until the player quits).
// winsNeeded = 2 means best of 3, winsNeeded = 3 means best of 5.
void playGame(int winsNeeded, Stats &stats)
{
    int matchPlayer = 0;
    int matchComputer = 0;
    int roundNumber = 1;

    while (true)
    {
        // Stop when someone reached the required wins.
        if (winsNeeded > 0 && (matchPlayer == winsNeeded || matchComputer == winsNeeded))
            break;

        cout << "\n--- Round " << roundNumber << " ---" << endl;
        if (winsNeeded > 0)
            cout << "Match score -> You " << matchPlayer
                 << " : " << matchComputer << " Computer" << endl;

        int player = readPlayerMove();
        if (player == QUIT)
            break;

        int computer = getComputerMove();
        cout << "\nYou      : " << getName(player) << endl;
        cout << "Computer : " << getName(computer) << endl;

        Result result = getWinner(player, computer);
        updateStats(stats, result);

        if (result == TIE)
        {
            cout << "It's a Tie!" << endl;
        }
        else if (result == PLAYER_WIN)
        {
            cout << "Congratulations, You Win this round!" << endl;
            matchPlayer++;
        }
        else
        {
            cout << "Computer wins this round. Better luck next time." << endl;
            matchComputer++;
        }

        roundNumber++;
    }

    // Announce the match winner (only for best-of modes).
    if (winsNeeded > 0)
    {
        if (matchPlayer == winsNeeded)
            cout << "\n*** YOU WON THE MATCH! ***" << endl;
        else if (matchComputer == winsNeeded)
            cout << "\n*** COMPUTER WON THE MATCH! ***" << endl;
        else
            cout << "\nMatch ended early." << endl;
    }
}

// ---------- Main menu ----------
// Returns 1-5, or 0 if input ended.
int readMenuChoice()
{
    string line;
    while (true)
    {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Quick play (play until you quit)" << endl;
        cout << "2. Best of 3" << endl;
        cout << "3. Best of 5" << endl;
        cout << "4. View scoreboard" << endl;
        cout << "5. Exit" << endl;
        cout << "> ";

        if (!readLine(line))
            return 0;

        if (line.size() == 1 && line[0] >= '1' && line[0] <= '5')
            return line[0] - '0';

        cout << "Invalid choice! Enter a number from 1 to 5." << endl;
    }
}

int main()
{
    // Seed the random generator ONCE at the start.
    srand(time(0));

    Stats stats;

    cout << "Welcome to Rock Paper Scissor Game." << endl;

    bool running = true;
    while (running)
    {
        int menu = readMenuChoice();

        if (menu == 1)
        {
            playGame(0, stats);
        }
        else if (menu == 2)
        {
            playGame(2, stats);
        }
        else if (menu == 3)
        {
            playGame(3, stats);
        }
        else if (menu == 4)
        {
            printStats(stats);
        }
        else
        {
            running = false; // menu 5 or input ended
        }
    }

    if (stats.rounds > 0)
        printStats(stats);

    cout << "\nThanks for playing!" << endl;
    return 0;
}