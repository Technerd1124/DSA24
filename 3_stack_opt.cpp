#include <iostream>
using namespace std;

const int MAX = 100;
int stackArr[MAX];
int top = -1;

// Push an element onto the stack
void push() {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Cannot push element.\n";
        return;
    }

    int value;
    cout << "Enter value to push: ";
    cin >> value;

    stackArr[++top] = value;
    cout << "Element pushed successfully.\n";
}

// Pop an element from the stack
void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }

    cout << "Popped element: " << stackArr[top--] << "\n";
}

// Display the top element
void peek() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Top element: " << stackArr[top] << "\n";
}

// Display all stack elements from top to bottom
void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack elements (top to bottom):\n";

    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << "\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n----- STACK OPERATIONS MENU -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
