// TASK 01
//Deletion at Beginning and End 
#include <iostream>
using namespace std;
struct Node {
 int data;
 Node* next;
 Node* prev;
};
Node* head = NULL;
void insert(int n) {
 Node* newNode = new Node;
 newNode->data = n;
 newNode->next = head;
 newNode->prev = NULL;
 if (head != NULL) {
 head->prev = newNode;
 }
 head = newNode;
}
void deleteAtBeginning() {
 if (head == NULL) {
 cout << "List is empty, there is no element to delete" << endl;
 return;
 }
 Node* temp = head;
 head = temp->next;
 if (head != NULL) {
 head->prev = NULL;
 }
 delete temp;
}
void deleteAtEnd() {
 if (head == NULL) {
 cout << "List is empty, there is no element to delete" << endl;
 return;
 }
 Node* temp = head;
 if (temp->next == NULL) { 
 delete temp;
 head = NULL;
 return;
 }
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->prev->next = NULL;
 delete temp;
}
void print() {
 cout << "Elements in the list are: " << endl;
 Node* temp = head;
[20:50, 26/10/2024] ...: while (temp != NULL) {
 cout << temp->data << " ";
 temp = temp->next;
 }
 cout << endl;
}
int main() {
 int numNodes, value, choice;
 cout << "Enter the number of initial nodes to insert: ";
 cin >> numNodes;
 for (int i = 0; i < numNodes; i++) {
 cout << "Enter value for node " << i + 1 << ": ";
 cin >> value;
 insert(value);
 }
 while (true) {
 cout << "Choose an option:\n1. Delete at beginning\n2. Delete at end\n3. Exit\n";
 cin >> choice;
 switch (choice) {
 case 1:
 deleteAtBeginning();
 print();
 break;
 case 2:
 deleteAtEnd();
 print();
[20:50, 26/10/2024] ...: case 3:
 return 0;
 default:
 cout << "Invalid choice, please try again.\n";
 }
 }
}
