#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;

// A customer has an ID number and a name
struct Customer {
    int id;
    string name;
};

Customer queueArr[MAX];
int front = -1;
int rear = -1;

// Function to add a new customer to the back of the queue
void addCustomer() {
    if (rear == MAX - 1) {
        cout << "Queue is full. Cannot add more customers.\n";
        return;
    }

    Customer c;

    cout << "Enter customer ID: ";
    cin >> c.id;

    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, c.name);

    if (front == -1) {
        front = 0;
    }

    rear = rear + 1;
    queueArr[rear] = c;

    cout << "Customer " << c.name
         << " added to the queue.\n";
}

// Function to serve (remove) the customer at the front
void serveCustomer() {
    if (front == -1 || front > rear) {
        cout << "No customers in queue.\n";
        front = -1;
        rear = -1;
        return;
    }

    cout << "Serving customer: "
         << queueArr[front].name
         << " (ID: " << queueArr[front].id << ")\n";

    front = front + 1;

    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

// Display all customers currently waiting
void displayQueue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Customers waiting:\n";

    for (int i = front; i <= rear; i++) {
        cout << i - front + 1 << ". "
             << queueArr[i].name
             << " (ID: " << queueArr[i].id << ")\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n----- BANK CUSTOMER QUEUE -----\n";
        cout << "1. Add Customer to Queue\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: serveCustomer(); break;
            case 3: displayQueue(); break;
            case 4: cout << "Exiting...\n"; break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
