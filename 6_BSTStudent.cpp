
#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Node {
    int rollNo;
    string name;
    Node* left;
    Node* right;
};

Node* createNode(int rollNo, string name) {
    Node* newNode = new Node();
    newNode->rollNo = rollNo;
    newNode->name = name;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int rollNo, string name) {
    if (root == nullptr) {
        return createNode(rollNo, name);
    }

    if (rollNo < root->rollNo) {
        root->left = insert(root->left, rollNo, name);
    } 
    else if (rollNo > root->rollNo) {
        root->right = insert(root->right, rollNo, name);
    } 
    else {
        cout << "Roll number already exists!\n";
    }

    return root;
}

Node* search(Node* root, int rollNo) {
    if (root == nullptr || root->rollNo == rollNo) {
        return root;
    }

    if (rollNo < root->rollNo) {
        return search(root->left, rollNo);
    }

    return search(root->right, rollNo);
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);

    cout << "Roll No: " << root->rollNo
         << "\tName: " << root->name << endl;

    inorder(root->right);
}

void freeTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int choice, rollNo;
    string name;

    do {
        cout << "\n--- Student BST ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> rollNo;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid roll number!\n";
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter Student Name: ";
                getline(cin, name);

                root = insert(root, rollNo, name);
                break;

            case 2: {
                cout << "Enter Roll Number to search: ";
                cin >> rollNo;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid roll number!\n";
                    break;
                }

                Node* result = search(root, rollNo);

                if (result != nullptr) {
                    cout << "\nStudent Found!\n";
                    cout << "Roll No: " << result->rollNo << endl;
                    cout << "Name: " << result->name << endl;
                } else {
                    cout << "Student record not found.\n";
                }
                break;
            }

            case 3:
                cout << "\nStudent Records:\n";

                if (root == nullptr) {
                    cout << "Tree is empty.\n";
                } else {
                    inorder(root);
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    freeTree(root);
    return 0;
}
