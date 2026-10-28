
#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_CHILDREN = 10;

struct Node {
    string name;
    Node* children[MAX_CHILDREN];
    int childCount;
};

Node* root = nullptr;

Node* createNode(const string& name) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->childCount = 0;

    for (int i = 0; i < MAX_CHILDREN; i++) {
        newNode->children[i] = nullptr;
    }

    return newNode;
}

Node* searchMember(Node* node, const string& name) {
    if (node == nullptr) {
        return nullptr;
    }

    if
