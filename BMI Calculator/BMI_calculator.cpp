#include <iostream>
using namespace std;

int main()
{
    double weight;
    double height;
    double bmi;

    cout << "===== BMI CALCULATOR =====" << endl;

    cout << "Enter your weight in kg: ";
    cin >> weight;

    cout << "Enter your height in meters: ";
    cin >> height;

    bmi = weight / (height * height);   // logic to calculate BMI 

    cout << "Your BMI is: " << bmi << endl;

    if (bmi < 18.5)
    {
        cout << "Category: Underweight" << endl;
    }
    else if (bmi < 25)
    {
        cout << "Category: Normal weight" << endl;
    }
    else if (bmi < 30)
    {
        cout << "Category: Overweight" << endl;
    }
    else
    {
        cout << "Category: Obese" << endl;
    }

    return 0;
}