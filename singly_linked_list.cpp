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

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Function to insert an element at the beginning of the linked list
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }
    

    // Function to insert an element at the i-th position in the linked list
    void insertAtPosition(int x, int position) {
        if (position <= 0) {
            std::cout << "Invalid position!" << std::endl;
            return;
        }

        Node* newNode = new Node(x);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                std::cout << "Invalid position!" << std::endl;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to remove an element from the beginning of the linked list
    void removeFromBeginning() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            std::cout << "List is empty. No element to remove." << std::endl;
        }
    }

    // Function to remove an element from the i-th position in the linked list
    void removeFromPosition(int position) {
        if (position <= 0 || head == nullptr) {
            std::cout << "Invalid position or empty list!" << std::endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        if (position == 1) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 1; i < position && temp != nullptr; ++i) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == nullptr) {
                std::cout << "Invalid position!" << std::endl;
                return;
            }

            prev->next = temp->next;
            delete temp;
        }
    }

    // Function to search for an element and return its pointer
    Node* search(int x) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == x) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        std::cout << "Linked List: ";
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    SinglyLinkedList myList;

    // Inserting elements at the beginning and specific positions
    std::cout << "At beginning\n";
    myList.display();
    
    
    myList.insertAtBeginning(5);
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(15);
    std::cout << "After insertion at front\n";
    myList.display();
    
    
    myList.insertAtPosition(20, 2);
    std::cout << "After insertion at i-th position\n";
    myList.display();

    // Removing elements from the beginning and specific positions
    myList.removeFromBeginning();
    std::cout << "After removing from beginning\n";
    myList.display();
    
    
    myList.removeFromPosition(3);
    std::cout << "After removing from i-th position\n";
    myList.display();

    // Searching for an element
    Node* searchResult = myList.search(10);
    if (searchResult != nullptr) {
        std::cout << "Element found: " << searchResult->data << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
