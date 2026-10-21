#include <iostream>
using namespace std;
int main()
{
    float user_value, percent_value;
    cout << "\n\nWelcome to Percentage Calculator\n\n";
    cout << "=====================================\n";
    cout << "Enter the Value you want percentage for :";
    cin >> user_value;
    cout << "Enter the percentage you want to get:";
    cin >> percent_value;

    float percent = (user_value * percent_value) / 100;
    cout << "The result is: " << percent;
    return 0;
}