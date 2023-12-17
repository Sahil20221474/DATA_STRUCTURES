#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert an element at the beginning of the doubly linked list
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert an element at the end of the doubly linked list
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to remove an element from the beginning of the doubly linked list
    void removeFromBeginning() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr; // If there was only one element
            }
            delete temp;
        } else {
            std::cout << "List is empty. No element to remove." << std::endl;
        }
    }

    // Function to remove an element from the end of the doubly linked list
    void removeFromEnd() {
        if (tail != nullptr) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr; // If there was only one element
            }
            delete temp;
        } else {
            std::cout << "List is empty. No element to remove." << std::endl;
        }
    }

    // Function to display the doubly linked list
    void display() {
        Node* temp = head;
        std::cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    DoublyLinkedList myList;

    // Inserting elements at the beginning and end of the doubly linked list
    
    std::cout << "At beginning\n";
    myList.display();

    myList.insertAtBeginning(5);
    myList.insertAtBeginning(3);
    std::cout << "After insertion at front\n";
    myList.display();

    myList.insertAtEnd(10);
    myList.insertAtEnd(15);
    std::cout << "After insertion at end\n";
    myList.display();

    // Removing elements from the beginning and end of the doubly linked list
    
    myList.removeFromBeginning();
    std::cout << "After removing from beginning\n";
    myList.display();

    myList.removeFromEnd();
    std::cout << "After removing from end\n";
    myList.display();

    return 0;
}