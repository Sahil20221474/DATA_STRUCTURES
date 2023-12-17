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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue (insert) an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No element to dequeue." << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr; // If the queue becomes empty after dequeue
        }
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Assuming -1 represents an empty queue
        }

        return front->data;
    }

    // Function to display the queue elements
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* temp = front;
        std::cout << "Queue: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue myQueue;

    // Enqueue elements into the queue
    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);

    // Display the queue
    myQueue.display();

    // Dequeue an element from the queue
    myQueue.dequeue();

    // Display the modified queue
    myQueue.display();

    // Get the front element of the queue
    int frontElement = myQueue.getFront();
    if (frontElement != -1) {
        std::cout << "Front element: " << frontElement << std::endl;
    }

    return 0;
}
