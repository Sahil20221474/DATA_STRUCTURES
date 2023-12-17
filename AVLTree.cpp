#include <iostream>
#include <algorithm>

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insertRecursively(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->key) {
            node->left = insertRecursively(node->left, value);
        } else if (value > node->key) {
            node->right = insertRecursively(node->right, value);
        } else {
            // Duplicate keys are not allowed in AVL trees
            return node;
        }

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->key) {
            return rotateRight(node);
        }
        // Right Right Case
        if (balance < -1 && value > node->right->key) {
            return rotateLeft(node);
        }
        // Left Right Case
        if (balance > 1 && value > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // Right Left Case
        if (balance < -1 && value < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* searchRecursively(Node* node, int value) {
        if (node == nullptr || node->key == value) {
            return node;
        }

        if (value < node->key) {
            return searchRecursively(node->left, value);
        } else {
            return searchRecursively(node->right, value);
        }
    }
    
    //To display AVL Tree
    
    /*void displayInorderRecursively(Node* node) {
        if (node == nullptr) {
            return;
        }
        displayInorderRecursively(node->left);
        std::cout << node->key << " ";
        displayInorderRecursively(node->right);
    }*/

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursively(root, value);
    }

    Node* search(int value) {
        return searchRecursively(root, value);
    }
    
    //To display AVL Tree ->
    
    /*void displayInorder() {
        std::cout << "AVL Tree (Inorder): ";
        displayInorderRecursively(root);
        std::cout << std::endl;
    }*/
};

int main() {
    AVLTree avl;

    // Insert elements into the AVL tree
    avl.insert(50);
    avl.insert(30);
    avl.insert(70);
    avl.insert(20);
    avl.insert(40);
    avl.insert(60);
    avl.insert(80);
    
    // To Display AVL tree using inorder traversal->
    //avl.displayInorder();
    

    // Search for an element in the AVL tree
    int searchValue = 40;
    Node* searchResult = avl.search(searchValue);
    if (searchResult != nullptr) {
        std::cout << "Element " << searchValue << " found in the AVL tree." << std::endl;
    } else {
        std::cout << "Element " << searchValue << " not found in the AVL tree." << std::endl;
    }

    return 0;
}

