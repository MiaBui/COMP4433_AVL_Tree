# AVL Tree Test Cases

This repository contains an implementation of an AVL tree data structure in C++. The purpose of this README is to explain how to execute the test cases provided and interpret their results.

## Instructions

1. **Compile the Code**: Ensure that you have a C++ compiler installed on your system. Compile the `test-avl.cpp` file along with the AVL tree implementation files (`avl_tree.h` and `avl_tree.cpp`). You can use the following command:

    ```
    g++ test-avl.cpp avl_tree.cpp -o test-avl
    ```

2. **Execute the Test Program**: Run the compiled executable `test-avl` to execute the test cases. You can do this by running the following command:

    ```
    ./test-avl
    ```

3. **Interpret the Output**: The test program will execute various operations on the AVL tree, such as insertion, deletion, and searching. It will print the results of these operations along with any relevant information.

## Test Cases and Results

### Test Case 1: Insertion of Elements

- **Description**: Insert several elements into the AVL tree and verify that the tree maintains its balance.
- **Expected Result**: The AVL tree should be balanced after insertion, and the in-order traversal should display the elements in sorted order.

    ```
    Test Case 1.1 - Display the tree following the in-order traversal
    Test Case 1.2 - Display the tree following the pre-order traversal
    Test Case 1.3 - Display the tree following the post-order traversal
    ```

### Test Case 2: Deletion of Elements

- **Description**: Remove elements from the AVL tree and verify that the tree remains balanced.
- **Expected Result**: The AVL tree should be balanced after deletion, and the in-order traversal should display the remaining elements in sorted order.

    ```
    Test Case 4 - Deletion of element 20: Display the tree following the in-order traversal: 10 30 40 50
    ```

### Test Case 3: Searching for Elements

- **Description**: Search for elements in the AVL tree and verify their presence.
- **Expected Result**: The search operation should correctly identify whether the elements are present in the AVL tree.

    ```
    Test Case 5 - Searching for elements:
    Search for 30: Found
    Search for 25: Not found
    ```

### Test Case 4: Efficiency Analysis

- **Description**: Measure the efficiency of insertion and deletion operations on large-scale data.
- **Expected Result**: The time taken for insertion and deletion operations should be reasonable, indicating the efficiency of the AVL tree implementation.

    ```
    Time taken: [time in milliseconds]
    ```

Feel free to customize this README file with additional information or formatting as needed for your project.
