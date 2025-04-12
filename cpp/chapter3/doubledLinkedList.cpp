#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};


//adds a new value to the left of the list
Node* MakeListLeft(int value, Node* rest) {
    Node* newNode = new Node(value);
    if (rest != nullptr) {
        newNode->next = rest;
        rest->prev = newNode;
    }
    return newNode;
}


//adds a new value to the right of the list
Node* MakeListRight(int value, Node* rest) {
    Node* newNode = new Node(value);
    if (rest == nullptr)
        return newNode;

    Node* curr = rest;
    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = newNode;
    newNode->prev = curr;
    return rest;
}


//checks if the list is empty.
bool isEmpty(Node* list) {
    return list == nullptr;
}

//the left most element of list
int firstLeft(Node* list) {
    if (isEmpty(list)) {
        throw runtime_error("List is empty!");
    }
    return list->data;
}

//returns the list excluding the left element

Node* restLeft(Node* list) {
    if (isEmpty(list)) return nullptr;
    Node* rest = list->next;
    if (rest != nullptr) rest->prev = nullptr;
    delete list;
    return rest;
}

//return the right most element of list

int firstRight(Node* list) {
    if (isEmpty(list)) {
        throw runtime_error("List is empty!");
    }
    Node* curr = list;
    while (curr->next != nullptr)
        curr = curr->next;
    return curr->data;
}

//return the list excluding the right element
Node* restRight(Node* list) {
    if (isEmpty(list)) return nullptr;

    Node* curr = list;
    while (curr->next != nullptr)
        curr = curr->next;

    if (curr->prev != nullptr) {
        curr->prev->next = nullptr;
    } else {
        // only one element
        list = nullptr;
    }

    delete curr;
    return list;
}

//prints out the list on the screen

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next)
            cout << " <-> ";
        curr = curr->next;
    }
    cout <<endl;
}



// Returns the number of nodes in the list
int getCount(Node* head) {
    int count = 0;
    Node* curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

// Deletes the first occurrence of a node with the given value
Node* deleteItem(Node* head, int value) {
    Node* curr = head;
    while (curr) {
        if (curr->data == value) {
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next; // head deleted

            if (curr->next)
                curr->next->prev = curr->prev;

            delete curr;
            break;
        }
        curr = curr->next;
    }
    return head;
}

// Deletes entire list to free memory
void deleteList(Node* head) {
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {

    Node* list = nullptr;

    cout << "Is Empty: " << (isEmpty(list) ? "Yes" : "No") <<endl;


    list = MakeListLeft(3,
        MakeListLeft(1,
            MakeListLeft(4,
                MakeListLeft(2,
                    MakeListLeft(5, nullptr)))));
    printList(list);

    Node* list1 = MakeListRight(5,
        MakeListRight(2,
            MakeListRight(4,
                MakeListRight(1,
                    MakeListRight(3, nullptr)))));
                    
    printList(list1);

    Node* list2 = MakeListLeft(3,
        MakeListLeft(1,
            MakeListRight(5,
                MakeListRight(2,
                    MakeListLeft(4, nullptr)))));

    printList(list2); 

    //these are the selectors

    cout<<"First Left: "<<firstLeft(list)<<endl;
    list = restLeft(list);
    cout<<"Rest left of the list : ";
    printList(list);

    //call first right function
    cout<<"First Right : "<<firstRight(list)<<endl;

    //call the rest right function.
    list = restRight(list);
    cout<<"Rest right of the list : ";
    printList(list);

    cout << "Is Empty: " << (isEmpty(list) ? "Yes" : "No") <<endl;

    //get the number of elements in the list
    cout << "Length: "<<getCount(list) <<endl;

    //deleting an element of the array.
    cout<<"Deleting value 4..."<<endl;
    list = deleteItem(list, 4);
    printList(list);

    //deleting the entire list
    cout<<"Deleting list from memory..."<<endl;
    deleteList(list);



    return 0;
}
