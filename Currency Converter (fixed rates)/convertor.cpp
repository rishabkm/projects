#include <iostream>
using namespace std;

// Exchange rates (example rates)
// 1 USD = 83 INR
// 1 EUR = 90 INR
// 1 GBP = 105 INR

float usdToInr(float usd)
{
    return usd * 83;
}

float inrToUsd(float inr)
{
    return inr / 83;
}

float eurToInr(float eur)
{
    return eur * 90;
}

float inrToEur(float inr)
{
    return inr / 90;
}

float gbpToInr(float gbp)
{
    return gbp * 105;
}

float inrToGbp(float inr)
{
    return inr / 105;
}

int main()
{
    int choose = -1;
    float value;

    while (choose != 0)
    {
        cout << "\n============================\n";
        cout << "\nWelcome to Currency Converter\n";
        cout << "\n============================\n";

        cout << "1. Convert USD to INR\n";
        cout << "2. Convert INR to USD\n";
        cout << "3. Convert EUR to INR\n";
        cout << "4. Convert INR to EUR\n";
        cout << "5. Convert GBP to INR\n";
        cout << "6. Convert INR to GBP\n";
        cout << "0. To Exit\n\n";

        cout << "Choose your Option : ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            cout << "Enter value in USD: ";
            cin >> value;
            cout << value << " USD = " << usdToInr(value) << " INR\n";
            break;

        case 2:
            cout << "Enter value in INR: ";
            cin >> value;
            cout << value << " INR = " << inrToUsd(value) << " USD\n";
            break;

        case 3:
            cout << "Enter value in EUR: ";
            cin >> value;
            cout << value << " EUR = " << eurToInr(value) << " INR\n";
            break;

        case 4:
            cout << "Enter value in INR: ";
            cin >> value;
            cout << value << " INR = " << inrToEur(value) << " EUR\n";
            break;

        case 5:
            cout << "Enter value in GBP: ";
            cin >> value;
            cout << value << " GBP = " << gbpToInr(value) << " INR\n";
            break;

        case 6:
            cout << "Enter value in INR: ";
            cin >> value;
            cout << value << " INR = " << inrToGbp(value) << " GBP\n";
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