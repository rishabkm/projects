#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Student{
    int ID;
    string name;
    int age;
    float marks;
};

void add(vector<Student> &students){
    Student newStudent;
    cout << "Enter ID: ";
    cin >> newStudent.ID;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].ID == newStudent.ID)
        {
            cout << "\nStudent with this ID already exists!\n";
            return; // Stops the function here so it doesn't add the student
        }
    }
    cout << "Enter the name of Student: ";
    cin.ignore(); // Clears the input buffer to prevent getline() from skipping
    getline(cin, newStudent.name);
    cout << "Enter age: ";
    cin >> newStudent.age;
    cout << "Enter total marks: ";
    cin >> newStudent.marks;

    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

auto view(vector<Student> &students){
    if (students.empty())
    {
        cout << "No Student record found in system.\n";
        return;
    }
    for (int i = 0; i < students.size(); i++)
    {
        cout << "\n--- Student " << i + 1 << " ---\n";
        cout << "ID: " << students[i].ID << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Age: " << students[i].age << "\n";
        cout << "Marks: " << students[i].marks << "\n";
    }
}

void Search(vector<Student> &students){
    if (students.empty())
    {
        cout << "No Student record found in system.\n";
        return;
    }

    int searchID;
    cout << "Enter the ID you want to search: ";
    cin >> searchID;

    bool found = false; // Flag to track if we found the student

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].ID == searchID)
        {
            cout << "\n--- Student Found ---\n";
            cout << "ID: " << students[i].ID << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Age: " << students[i].age << "\n";
            cout << "Marks: " << students[i].marks << "\n";

            found = true;
            break; // Stop searching once we find the match
        }
    }

    // If the loop finished and 'found' is still false, print not found
    if (!found)
    {
        cout << "Student with ID " << searchID << " not found.\n";
    }
}

void Delete(vector<Student> &students){
    if (students.empty())
    {
        cout << "No Student record found in system to delete.\n";
        return;
    }

    int deleteID;
    cout << "Enter the ID of the student you want to delete: ";
    cin >> deleteID;

    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].ID == deleteID)
        {
            // .erase() removes the element at the specified position
            students.erase(students.begin() + i);
            cout << "Student with ID " << deleteID << " deleted successfully!\n";
            found = true;
            break; // Exit the loop once deleted
        }
    }

    if (!found)
    {
        cout << "Student with ID " << deleteID << " not found.\n";
    }
}

void Update(vector<Student> &students){
    if (students.empty())
    {
        cout << "\nNo Student record found in system to update.\n";
        return;
    }

    int updateID;
    cout << "Enter the ID of Student to Update Information: ";
    cin >> updateID;

    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].ID == updateID)
        {
            cout << "\nStudent found! Enter new details:\n";

            cout << "Enter new name: ";
            cin.ignore(); // Clear the input buffer before getline
            getline(cin, students[i].name);

            cout << "Enter new age: ";
            cin >> students[i].age;

            cout << "Enter new total marks: ";
            cin >> students[i].marks;

            cout << "Student record updated successfully!\n";
            found = true;
            break; // Exit loop once updated
        }
    }

    if (!found)
    {
        cout << "Student with ID " << updateID << " not found.\n";
    }
}

void saveToFile(const vector<Student> &students)
{
    ofstream outFile("students.txt"); // Opens a file for writing
    for (int i = 0; i < students.size(); i++)
    {
        outFile << students[i].ID << "\n";
        outFile << students[i].name << "\n";
        outFile << students[i].age << "\n";
        outFile << students[i].marks << "\n";
    }
    outFile.close();
}

void loadFromFile(vector<Student> &students)
{
    ifstream inFile("students.txt"); // Opens a file for reading
    if (!inFile)
    {
        return; // If the file doesn't exist yet, just exit quietly
    }

    Student tempStudent;
    // Read data in the exact same order we saved it
    while (inFile >> tempStudent.ID)
    {
        inFile.ignore(); // clear newline left by cin
        getline(inFile, tempStudent.name);
        inFile >> tempStudent.age;
        inFile >> tempStudent.marks;

        students.push_back(tempStudent);
    }
    inFile.close();
}

int main(){

    cout << "\nWelcome to Student Management System !!!\n";
    int choice = -1; // Initialized to avoid undefined behavior in the while loop
    vector<Student> students;
    loadFromFile(students);

    while (choice != 0)
    {
        cout << "\n1.Add\n";
        cout << "2.View\n";
        cout << "3.Search\n";
        cout << "4.Delete\n";
        cout << "5.Update\n";
        cout << "0.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nAdd Students.\n";
            add(students); // Passed the vector to the add function
            break;
        case 2:
            cout << "\nView All Students.\n";
            view(students);
            break;
        case 3:
            cout << "\nSearch Students.\n";
            Search(students);
            break;
        case 4:
            cout << "Delete Students.\n";
            Delete(students);
            break;
        case 5:
            cout << "Update Students.\n";
            Update(students);
            break;
        case 0:
            cout << "\nExit.\n";
            saveToFile(students);
            break;
        default:
            cout << "\nInvalid!!!\n";
            break;
        }
    }

    return 0;
}