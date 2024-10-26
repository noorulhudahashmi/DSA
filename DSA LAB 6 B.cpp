
//insrtion in doubly circular linked list


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

void insert(int n) {
    Node *newNode = new Node;
    newNode->data = n;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node *last = head->prev; 
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode; 
    }
}
void insertAtStart(int n) {
    Node *newNode = new Node;
    newNode->data = n;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node *last = head->prev; 
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode; 
    }
}


void insertAtEnd(int n) {
    Node *newNode = new Node;
    newNode->data = n;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node *last = head->prev; 
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
}


void insertAtPosition(int n, int position) {
    Node *newNode = new Node;
    newNode->data = n;

    if (position == 1) {
        insertAtStart(n);
        return;
    }

    if (head == NULL) {
        cout << "List is empty. Cannot insert at position " << position << "." << endl;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
   temp->next = newNode;
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
         cout << "1. Insert nodes\n";
        cout << "2. Insert node at start\n";
        cout << "3. Insert node at end\n";
        cout << "4. Insert node at specific position\n";
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
                cout << "Enter value to insert at start: ";
                cin >> value;
                insertAtStart(value);
                  print();
                break;
            case 3:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(value);
                  print();
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                insertAtPosition(value, position);
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