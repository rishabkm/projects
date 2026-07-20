#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Functions
int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int divi(int a, int b)
{
    return a / b;
}

int mod(int a, int b)
{
    return a % b;
}

int main()
{
    vector<string> History;

    char again = 'Y';

    while (again == 'Y' || again == 'y')
    {
        int choice;
        int a, b;
        int result;
        string operation;

        cout << "\n===== Calculator =====" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Power" << endl;
        cout << "7. Square" << endl;
        cout << "8. Cube" << endl;
        cout << "9. Square Root" << endl;
        cout << "10. Average" << endl;
        cout << "11. Maximum" << endl;
        cout << "12. Minimum" << endl;
        cout << "13. Percentage" << endl;
        cout << "14. History" << endl;
        cout << "0. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Thank you for using the calculator!" << endl;
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter two numbers: ";
            cin >> a >> b;

            result = add(a, b);
            cout << "Answer = " << result << endl;

            operation = to_string(a) + "+" + to_string(b) + "=" + to_string(result);
            History.push_back(operation);
            break;

        case 2:
            cout << "Enter two numbers: ";
            cin >> a >> b;

            result = sub(a, b);
            cout << "Answer = " << result << endl;

            operation = to_string(a) + "-" + to_string(b) + "=" + to_string(result);
            History.push_back(operation);
            break;

        case 3:
            cout << "Enter two numbers: ";
            cin >> a >> b;

            result = mul(a, b);
            cout << "Answer = " << result << endl;

            operation = to_string(a) + "*" + to_string(b) + "=" + to_string(result);
            History.push_back(operation);
            break;

        case 4:
            cout << "Enter two numbers: ";
            cin >> a >> b;

            if (b != 0)
            {
                result = divi(a, b);
                cout << "Answer = " << result << endl;

                operation = to_string(a) + "/" + to_string(b) + "=" + to_string(result);
                History.push_back(operation);
            }
            else
            {
                cout << "Cannot divide by zero!" << endl;
            }

            break;

        case 5:
            cout << "Enter two numbers: ";
            cin >> a >> b;

            if (b != 0)
            {
                result = mod(a, b);
                cout << "Answer = " << result << endl;

                operation = to_string(a) + "%" + to_string(b) + "=" + to_string(result);
                History.push_back(operation);
            }
            else
            {
                cout << "Cannot perform modulus with zero!" << endl;
            }

            break;

        case 6:
        {
            cout << "Enter base and power: ";
            cin >> a >> b;

            double result = pow(a, b);

            cout << "Answer = " << result << endl;

            operation = to_string(a) + "^" + to_string(b) + "=" + to_string(result);
            History.push_back(operation);

            break;
        }

        case 7:
            cout << "Enter a number: ";
            cin >> a;

            result = a * a;

            cout << "Square = " << result << endl;

            operation = "Square(" + to_string(a) + ") = " + to_string(result);
            History.push_back(operation);

            break;

        case 8:
            cout << "Enter a number: ";
            cin >> a;

            result = a * a * a;

            cout << "Cube = " << result << endl;

            operation = "Cube(" + to_string(a) + ") = " + to_string(result);
            History.push_back(operation);

            break;

        case 9:
        {
            cout << "Enter a number: ";
            cin >> a;

            if (a >= 0)
            {
                double result = sqrt(a);

                cout << "Square Root = " << result << endl;

                operation = "sqrt(" + to_string(a) + ") = " + to_string(result);
                History.push_back(operation);
            }
            else
            {
                cout << "Square root of a negative number is not allowed." << endl;
            }

            break;
        }

        case 10:
        {
            cout << "Enter two numbers: ";
            cin >> a >> b;

            double result = (a + b) / 2.0;

            cout << "Average = " << result << endl;

            operation = "Average(" + to_string(a) + "," + to_string(b) + ") = " + to_string(result);
            History.push_back(operation);

            break;
        }

        case 11:
            cout << "Enter two numbers: ";
            cin >> a >> b;

            result = max(a, b);

            cout << "Maximum = " << result << endl;

            operation = "Max(" + to_string(a) + "," + to_string(b) + ") = " + to_string(result);
            History.push_back(operation);

            break;

        case 12:
            cout << "Enter two numbers: ";
            cin >> a >> b;

            result = min(a, b);

            cout << "Minimum = " << result << endl;

            operation = "Min(" + to_string(a) + "," + to_string(b) + ") = " + to_string(result);
            History.push_back(operation);

            break;

        case 13:
        {
            double marks, total;

            cout << "Enter obtained marks: ";
            cin >> marks;

            cout << "Enter total marks: ";
            cin >> total;

            if (total != 0)
            {
                double result = (marks / total) * 100;

                cout << "Percentage = " << result << "%" << endl;

                operation = "Percentage(" + to_string(marks) + "/" + to_string(total) + ") = " + to_string(result) + "%";
                History.push_back(operation);
            }
            else
            {
                cout << "Total marks cannot be zero!" << endl;
            }

            break;
        }

        case 14:
            if (History.empty())
            {
                cout << "No history available." << endl;
            }
            else
            {
                cout << "\n===== History =====" << endl;

                for (int i = 0; i < History.size(); i++)
                {
                    cout << History[i] << endl;
                }
            }

            break;

        default:
            cout << "Invalid choice!" << endl;
        }

        cout << "\n MENU (Y/N): ";
        cin >> again;
    }

    return 0;
}