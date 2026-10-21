#include <iostream>
using namespace std;

float mtk(float m)
{
    return m / 1000;
}

float mtc(float m)
{
    return m * 100;
}

float ctk(float cm)
{
    return cm / 100000;
}

float ctm(float cm)
{
    return cm / 100;
}

float ktm(float km)
{
    return km * 1000;
}

float ktc(float km)
{
    return km * 100000;
}

int main()
{
    int choose = -1;
    float value;

    while (choose != 0)
    {
        cout << "\n============================\n";
        cout << "\nWelcome to Unit Converter\n";
        cout << "\n============================\n";

        cout << "1. Convert meter to kilometer\n";
        cout << "2. Convert meter to centimeter\n";
        cout << "3. Convert centimeter to kilometer\n";
        cout << "4. Convert centimeter to meter\n";
        cout << "5. Convert kilometer to meter\n";
        cout << "6. Convert kilometer to centimeter\n";
        cout << "0. To Exit\n\n";

        cout << "Choose your Option : ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            cout << "Enter value in meters: ";
            cin >> value;
            cout << value << " meter = " << mtk(value) << " kilometer\n";
            break;

        case 2:
            cout << "Enter value in meters: ";
            cin >> value;
            cout << value << " meter = " << mtc(value) << " centimeter\n";
            break;

        case 3:
            cout << "Enter value in centimeters: ";
            cin >> value;
            cout << value << " centimeter = " << ctk(value) << " kilometer\n";
            break;

        case 4:
            cout << "Enter value in centimeters: ";
            cin >> value;
            cout << value << " centimeter = " << ctm(value) << " meter\n";
            break;

        case 5:
            cout << "Enter value in kilometers: ";
            cin >> value;
            cout << value << " kilometer = " << ktm(value) << " meter\n";
            break;

        case 6:
            cout << "Enter value in kilometers: ";
            cin >> value;
            cout << value << " kilometer = " << ktc(value) << " centimeter\n";
            break;

        case 0:
            cout << "\nThank You\n";
            cout << "===================\n\n";
            break;

        default:
            cout << "\nInvalid option! Please choose between 0 and 6.\n";
            break;
        }
    }

    return 0;
}