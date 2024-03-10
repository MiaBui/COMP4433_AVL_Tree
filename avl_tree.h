#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <algorithm>
#include <cstddef>

template<typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;
    int height;

    Node(T val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

template<typename T>
class AVLTree {
private:
    Node<T>* root;

    int height(Node<T>* node);
    int balanceFactor(Node<T>* node);
    Node<T>* rightRotate(Node<T>* y);
    Node<T>* leftRotate(Node<T>* x);
    Node<T>* insertNode(Node<T>* node, T value);
    Node<T>* removeNode(Node<T>* node, T value);
    Node<T>* minValueNode(Node<T>* node);
    bool searchNode(Node<T>* node, T value);
    void printInOrder(Node<T>* node);
    void printPreOrder(Node<T>* node);
    void printPostOrder(Node<T>* node);

public:
    AVLTree();
    void insert(T value);
    void remove(T value);
    bool search(T value);
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
};
#include "avl_tree.cpp"
#endif /* AVL_TREE_H */
