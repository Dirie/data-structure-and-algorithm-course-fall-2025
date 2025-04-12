#include <iostream>
using namespace std;

// Define a Node class to represent each element in the linked list
class Node {
public:
    int data; // The value of the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node with data and next pointer
    Node(int value, Node* next_node = nullptr) {
        data = value;
        next = next_node;
    }
};

// Function to construct the linked list
Node* makelist(int data, Node* next_node = nullptr) {
    return new Node(data, next_node);
}

// Define an empty list as nullptr (base case for recursion)
Node* emptylist = nullptr;

// Function to print the linked list
void printLinkedList(Node* node) {
    while (node) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "None" << endl; // To represent the end of the list
}

int main() {
    // Construct the linked list from the array A = [4, 5, 1, 2, 9]
    Node* linked_list = makelist(4, makelist(5, makelist(1, makelist(2, makelist(9, emptylist)))));

    // Output the constructed linked list
    printLinkedList(linked_list);

    return 0;
}
