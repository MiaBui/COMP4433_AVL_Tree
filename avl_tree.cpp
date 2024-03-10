#include "avl_tree.h"
#include <iostream>
#include <algorithm>

template<typename T>
int AVLTree<T>::height(Node<T>* node) {
    if (node == nullptr) return 0;
    return node->height;
}

template<typename T>
int AVLTree<T>::balanceFactor(Node<T>* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

template<typename T>
Node<T>* AVLTree<T>::rightRotate(Node<T>* y) {
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

template<typename T>
Node<T>* AVLTree<T>::leftRotate(Node<T>* x) {
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

template<typename T>
Node<T>* AVLTree<T>::insertNode(Node<T>* node, T value) {
    // Perform normal BST insertion
    if (node == nullptr) return new Node<T>(value);

    if (value < node->data)
        node->left = insertNode(node->left, value);
    else if (value > node->data)
        node->right = insertNode(node->right, value);
    else // Duplicate values not allowed
        return node;

    // Update height of this ancestor node
    node->height = 1 + std::max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = balanceFactor(node);

    // If node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

template<typename T>
Node<T>* AVLTree<T>::removeNode(Node<T>* node, T value) {
    // Base case: If the tree is empty
    if (node == nullptr) return node;

    // If the value to be deleted is smaller than the root's value, then it lies in the left subtree
    if (value < node->data)
        node->left = removeNode(node->left, value);
    // If the value to be deleted is greater than the root's value, then it lies in the right subtree
    else if (value > node->data)
        node->right = removeNode(node->right, value);
    // If the value is the same as the root's value, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (node->left == nullptr) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node<T>* temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->data = temp->data;

        // Delete the inorder successor
        node->right = removeNode(node->right, temp->data);
    }

    // Update the height of the current node
    node->height = 1 + std::max(height(node->left), height(node->right));

    // Get the balance factor of this node to check if it's unbalanced
    int balance = balanceFactor(node);

    // Left Left Case
    if (balance > 1 && balanceFactor(node->left) >= 0)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && balanceFactor(node->right) <= 0)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template<typename T>
Node<T>* AVLTree<T>::minValueNode(Node<T>* node) {
    Node<T>* current = node;

    // Loop down to find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}

template<typename T>
bool AVLTree<T>::searchNode(Node<T>* node, T value) {
    // Base Cases: root is null or value is present at root
    if (node == nullptr || node->data == value)
        return node != nullptr;

    // Value is greater than root's value
    if (node->data < value)
        return searchNode(node->right, value);

    // Value is smaller than root's value
    return searchNode(node->left, value);
}

template<typename T>
void AVLTree<T>::printInOrder(Node<T>* node) {
    if (node == nullptr) return;
    printInOrder(node->left);
    std::cout << node->data << " ";
    printInOrder(node->right);
}

template<typename T>
void AVLTree<T>::printPreOrder(Node<T>* node) {
    if (node == nullptr) return;
    std::cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

template<typename T>
void AVLTree<T>::printPostOrder(Node<T>* node) {
    if (node == nullptr) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->data << " ";
}

template<typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template<typename T>
void AVLTree<T>::insert(T value) {
    root = insertNode(root, value);
}

template<typename T>
void AVLTree<T>::remove(T value) {
    root = removeNode(root, value);
}

template<typename T>
bool AVLTree<T>::search(T value) {
    return searchNode(root, value);
}

template<typename T>
void AVLTree<T>::printInOrder() {
    printInOrder(root);
}

template<typename T>
void AVLTree<T>::printPreOrder() {
    printPreOrder(root);
}

template<typename T>
void AVLTree<T>::printPostOrder() {
    printPostOrder(root);
}

