#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursively(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRecursively(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursively(node->right, value);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteRecursively(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = deleteRecursively(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRecursively(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRecursively(node->right, temp->data);
        }
        return node;
    }

    Node* searchRecursively(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchRecursively(node->left, value);
        } else {
            return searchRecursively(node->right, value);
        }
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->data << " ";
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Function to insert an element into the BST
    void insert(int value) {
        root = insertRecursively(root, value);
    }

    // Function to delete an element from the BST
    void remove(int value) {
        root = deleteRecursively(root, value);
    }

    // Function to search for an element in the BST
    Node* search(int value) {
        return searchRecursively(root, value);
    }

    // Function to display elements of the BST in preorder traversal
    void displayPreorder() {
        std::cout << "Preorder Traversal: ";
        preorderTraversal(root);
        std::cout << std::endl;
    }

    // Function to display elements of the BST in inorder traversal
    void displayInorder() {
        std::cout << "Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

    // Function to display elements of the BST in postorder traversal
    void displayPostorder() {
        std::cout << "Postorder Traversal: ";
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Display elements in different traversal orders
    bst.displayPreorder();
    bst.displayInorder();
    bst.displayPostorder();

    // Search for an element in the BST
    int searchValue = 40;
    Node* searchResult = bst.search(searchValue);
    if (searchResult != nullptr) {
        std::cout << "Element " << searchValue << " found in the BST." << std::endl;
    } else {
        std::cout << "Element " << searchValue << " not found in the BST." << std::endl;
    }

    // Delete an element from the BST
    int deleteValue = 30;
    bst.remove(deleteValue);

    // Display elements after deletion
    bst.displayInorder();

    return 0;
}
