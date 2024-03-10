#include "avl_tree.h"

int main() {
    AVLTree<int> avlTree;

    // Insert test data
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);

    // Print in-order traversal to verify AVL properties
    avlTree.printInOrder(); // Expected output: 10 20 30 40 50

    return 0;
}
