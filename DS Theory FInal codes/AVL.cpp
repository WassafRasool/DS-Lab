#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        key = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
public:
    // Get height of node
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    // Get balance factor
    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Right rotate subtree rooted with x
    Node* rightRotate(Node* x) {
        Node* y = x->left;
        Node* T2 = y->right;

        y->right = x;
        x->left = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y; // new root
    }

    // Left rotate subtree rooted with x
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y; // new root
    }

    // Insert a key in AVL
    Node* insert(Node* root, int key) {
        if (!root) return new Node(key);

        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        else
            return root; // duplicate keys not allowed

        // Update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Check balance
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && key < root->left->key)
            return rightRotate(root);

        // Right Right Case
        if (balance < -1 && key > root->right->key)
            return leftRotate(root);

        // Left Right Case
        if (balance > 1 && key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Find node with minimum key (used in deletion)
    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    // Delete a key from AVL
    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Node with one or zero child
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } 
            else {
                Node* temp = findMin(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root) return root;

        // Update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Check balance
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Search in AVL
    Node* search(Node* root, int key) {
        if (!root || root->key == key) return root;
        return key < root->key ? search(root->left, key) : search(root->right, key);
    }

    // Inorder traversal
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
};

int main() {
    AVL tree;
    Node* root = nullptr;

    // Insert nodes
    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);
    root = tree.insert(root, 25);

    cout << "AVL Inorder Traversal: ";
    tree.inorder(root);
    cout << endl;

    // Delete a node
    cout << "Deleting 40\n";
    root = tree.deleteNode(root, 40);
    cout << "After Deletion: ";
    tree.inorder(root);
    cout << endl;

    // Search for a node
    int key = 30;
    Node* found = tree.search(root, key);
    cout << "Key " << key << (found ? " found in AVL.\n" : " not found in AVL.\n");

    return 0;
}
