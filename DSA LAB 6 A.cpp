//Deletion in singly circular linked list


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insert(int n) {
    Node *newNode = new Node;
    newNode->data = n;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteAtStart() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    Node *last = head;

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    delete temp;
}

void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }

    Node *last = temp->next;
    temp->next = head;
    delete last;
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (position == 1) {
        deleteAtStart();
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    

    temp->next=temp->next->next;
    delete temp->next;
}

void print() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int choice, value, position, numNodes;
    
    do {
        cout << "Menu:\n";
        cout << "1. Insert node\n";
        cout << "2. Delete node at start\n";
        cout << "3. Delete node at end\n";
        cout << "4. Delete node at specific position\n";
        cout << "5. Print list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
               cout << "Enter the number of initial nodes to insert: ";
                cin >> numNodes;

                for (int i = 0; i < numNodes; i++) {
                    cout << "Enter value for node " << i + 1 << ": ";
                    cin >> value;
                    insert(value);
                }
                print();
                break;
            case 2:
                deleteAtStart();
                print();
                break;
            case 3:
                deleteAtEnd();
                print();
                break;
            case 4:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteAtPosition(position);
                print();
                break;
            case 5:
                print();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}














































