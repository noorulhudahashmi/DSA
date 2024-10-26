//TASK 02
//Insertion at Beginning and End
#include <iostream>
using namespace std;
struct Node {
 int data;
 Node* prev;
 Node* next;
};
Node* head = NULL;
void print();
void insertAtBeginning(int n) {
 Node* newNode = new Node;
 newNode->data = n;
 newNode->next = head; 
 newNode->prev = NULL; 
 if (head != NULL) {
 head->prev = newNode; 
 }
 head = newNode; 
 print(); 
}
[20:50, 26/10/2024] ...: void insertAtEnd(int n) {
 Node* newNode = new Node;
 newNode->data = n;
 newNode->next = NULL;
 if (head == NULL) {
 newNode->prev = NULL;
 head = newNode;
 } else {
 Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
 newNode->prev = temp;
 }
 print(); 
}
void print() {
 Node* temp = head;
 cout << "Elements in the doubly linked list are: " << endl;
 while (temp != NULL) {
 cout << temp->data << " ";
 temp = temp->next;
 }
 cout << endl;
}
int main() {
 int choice, value;
[20:50, 26/10/2024] ...: while (true) {
 cout << "Choose an option:\n1. Insert at beginning\n2. Insert at end\n3. Exit\n";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter value to insert at beginning: ";
 cin >> value;
 insertAtBeginning(value);
 break;
 case 2:
 cout << "Enter value to insert at end: ";
 cin >> value;
 insertAtEnd(value);
 break;
 case 3:
 return 0;
 default:
 cout << "Invalid choice, please try again.\n";
 }
 }
}