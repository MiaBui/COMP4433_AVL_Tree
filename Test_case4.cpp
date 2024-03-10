#include <iostream>
#include <chrono>
#include "avl_tree.h" // Include your AVL tree header file

#define LARGE_NUMBER 10000 // Define the desired number of insertions and deletions

// Test case 4: Efficiency analysis
    // Perform large-scale insertion and deletion operations and measure the time taken
    // Example:
    // auto start = std::chrono::steady_clock::now();
    // Insert large number of elements
    // Remove large number of elements
    // auto end = std::chrono::steady_clock::now();
    // std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
int main() {
    // Create an instance of AVL tree
    AVLTree<int> avlTree;

    // Measure start time
    auto start = std::chrono::steady_clock::now();

    // Perform large number of insertion operations
    for (int i = 0; i < LARGE_NUMBER; ++i) {
        avlTree.insert(i);
    }

    // Perform large number of deletion operations
    for (int i = 0; i < LARGE_NUMBER; ++i) {
        avlTree.remove(i);
    }

    // Measure end time
    auto end = std::chrono::steady_clock::now();

    // Calculate time taken
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Print result
    std::cout << "Time taken: " << duration.count() << " ms" << std::endl;

    return 0;
}
