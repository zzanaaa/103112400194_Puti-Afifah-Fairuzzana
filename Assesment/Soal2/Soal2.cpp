#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int value;
    Node* prev;
    Node* next;
};

// Function to insert a value at the end of the list
void insertLast(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {  // If the list is empty
        newNode->prev = nullptr;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete the last node
void deleteLast(Node*& head) {
    if (head == nullptr) return;  // Empty list

    if (head->next == nullptr) {  // Only one node
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }
}

// Function to view the list from front to back
void viewList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the list
void reverseList(Node*& head) {
    if (head == nullptr) return;  // Empty list

    Node* current = head;
    Node* temp = nullptr;
    
    // Reverse the pointers
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Adjust the head to the new first element
    if (temp != nullptr) {
        head = temp->prev;
    }
}

int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                insertLast(head, value);
                break;

            case 2:
                deleteLast(head);
                break;

            case 3:
                viewList(head);
                break;

            case 4:
                reverseList(head);
                cout << "List setelah di-reverse: ";
                viewList(head);
                break;

            case 0:
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 0);

    return 0;
}