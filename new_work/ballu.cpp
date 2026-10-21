#include <iostream>
using namespace std;

// Celsius to Fahrenheit
double cf(double C)
{
    return (C * 9.0 / 5.0) + 32;
}

// Fahrenheit to Celsius
double fc(double F)
{
    return (F - 32) * 5.0 / 9.0;
}

int main()
{
    int choose = -1;
    double F, C;

    while (choose != 0)
    {
        cout << "\n\n===== Temperature Converter =====\n";
        cout << "1. Celsius to Fahrenheit\n";
        cout << "2. Fahrenheit to Celsius\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            cout << "Enter temperature in Celsius: ";
            cin >> C;
            cout << C << " °C = " << cf(C) << " °F\n";
            break;

        case 2:
            cout << "Enter temperature in Fahrenheit: ";
            cin >> F;
            cout << F << " °F = " << fc(F) << " °C\n";
            break;

        case 0:
            cout << "Thank you for using the Temperature Converter!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}