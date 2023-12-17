#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert an element in the circular linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself for circularity
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to remove an element from the circular linked list
    void remove(int value) {
        if (head == nullptr) {
            std::cout << "List is empty. No element to remove." << std::endl;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        // If head contains the value to be removed
        if (curr->data == value) {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            if (temp == head) { // If there's only one element
                head = nullptr;
            } else {
                temp->next = head->next;
                head = head->next;
            }
            delete curr;
            return;
        }

        // Search for the element to be removed
        while (curr->next != head) {
            prev = curr;
            curr = curr->next;
            if (curr->data == value) {
                prev->next = curr->next;
                delete curr;
                return;
            }
        }

        // If the element was not found
        std::cout << "Element not found in the list." << std::endl;
    }

    // Function to search for an element and return its pointer
    Node* search(int value) {
        Node* temp = head;
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return nullptr;
        }

        do {
            if (temp->data == value) {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);

        std::cout << "Element not found in the list." << std::endl;
        return nullptr;
    }

    // Function to display the circular linked list
    void display() {
        Node* temp = head;
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        std::cout << "Circular Linked List: ";
        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << "Head" << std::endl;
    }
};

int main() {
    CircularLinkedList myList;

    // Inserting elements in the circular linked list
    myList.insert(5);
    myList.insert(10);
    myList.insert(15);

    // Displaying the circular linked list
    myList.display();

    // Removing an element from the circular linked list
    myList.remove(10);

    // Displaying the modified circular linked list
    myList.display();

    // Searching for an element in the circular linked list
    Node* searchResult = myList.search(5);
    if (searchResult != nullptr) {
        std::cout << "Element found: " << searchResult->data << std::endl;
    }

    return 0;
}
