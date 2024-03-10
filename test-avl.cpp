#include <iostream>
#include "avl_tree.h" // Include your AVL tree header file

int main() {
    // Create an AVL tree object
    AVLTree<int> avlTree;

    // Test case 1: Insertion of elements
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);

    // Expected AVL tree after insertion: 30 -> (20, 40) -> (10, _, _, _, _, 50)
    std::cout << "Test Case 1 - Display the tree following the in-order traversal: ";
    avlTree.printInOrder(); // Expected output: 10 20 30 40 50
    std::cout << std::endl;

      std::cout << "Test Case 2 - Display the tree following the pre-order traversal: ";
    avlTree.printPreOrder(); // Expected output: 30 20 10 40 50
    std::cout << std::endl;

      std::cout << "Test Case 3 - Display the tree following the post-order traversal: ";
    avlTree.printPostOrder(); // Expected output:10 20 50 40 30
    std::cout << std::endl;

    // Test case 2: Deletion of elements
    avlTree.remove(20);

    // Expected AVL tree after deletion of 20: 30 -> (10, 40) -> (_, _, _, _, _, 50)
    std::cout << "Test Case 4- Deletion of element 20: ";
    std::cout << "Display the tree following the in-order traversal: ";
    avlTree.printInOrder(); // Expected output: 10 30 40 50
    std::cout << std::endl;

    // Test case 3: Searching for elements
    std::cout << "Test Case 5 - Searching for elements: ";
    std::cout << "Search for 30: " << (avlTree.search(30) ? "Found" : "Not found") << std::endl; // Expected output: Found
    std::cout << "Search for 25: " << (avlTree.search(25) ? "Found" : "Not found") << std::endl; // Expected output: Not found

    // Test case 4: Efficiency analysis
    // Perform large-scale insertion and deletion operations and measure the time taken
    // Example:
    // auto start = std::chrono::steady_clock::now();
    // Insert large number of elements
    // Remove large number of elements
    // auto end = std::chrono::steady_clock::now();
    // std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    return 0;
}
