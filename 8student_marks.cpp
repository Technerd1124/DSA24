
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 10;

struct Student {
    int rollNo;
    float marks;
    bool occupied;
};

Student hashTable[SIZE];

int hashFunction(int rollNo) {
    return rollNo % SIZE;
}

void insertStudent(int rollNo, float marks) {
    int index = hashFunction(rollNo);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (hashTable[pos].occupied) {
            if (hashTable[pos].rollNo == rollNo) {
                cout << "Roll number already exists.\n";
                return;
            }
        } else {
            hashTable[pos].rollNo = rollNo;
            hashTable[pos].marks = marks;
            hashTable[pos].occupied = true;

            cout << "Student record inserted successfully.\n";
            return;
        }
    }

    cout << "Hash table is full!\n";
}

void searchStudent(int rollNo) {
    int index = hashFunction(rollNo);

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (!hashTable[pos].occupied) {
            cout << "Student record not found.\n";
            return;
        }

        if (hashTable[pos].rollNo == rollNo) {
            cout << "Roll Number: "
                 << hashTable[pos].rollNo << endl;
            cout << "Marks: "
                 << hashTable[pos].marks << endl;
            return;
        }
    }

    cout << "Student record not found.\n";
}

void displayStudents() {
    cout << "\nStudent Records:\n";
    cout << "-------------------------\n";

    bool found = false;

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i].occupied) {
            cout << "Roll Number: "
                 << hashTable[i].rollNo
                 << ", Marks: "
                 << hashTable[i].marks << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "No student records available.\n";
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].occupied = false;
    }

    int choice, rollNo;
    float marks;

    do {
        cout << "\n--- Student Marks Management System ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> rollNo;

                if (cin.fail() || rollNo < 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid roll number.\n";
                    break;
                }

                cout << "Enter Marks: ";
                cin >> marks;

                if (cin.fail() || marks < 0 || marks > 100) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid marks. Enter marks from 0 to 100.\n";
                    break;
                }

                insertStudent(rollNo, marks);
                break;

            case 2:
                cout << "Enter Roll Number to Search: ";
                cin >> rollNo;

                if (cin.fail() || rollNo < 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid roll number.\n";
                    break;
                }

                searchStudent(rollNo);
                break;

            case 3:
                displayStudents();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
