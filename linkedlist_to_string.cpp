// linked list to integer
// Concept: How to handle large power values

#include <iostream>
#include <cmath>

// Define your Node structure
struct Node
{
    bool data;
    Node *next;

    // Constructor
    Node(bool val) : data(val), next(nullptr) {}
};

// Function to calculate the decimal value based on the linked list
long long unsigned int decimalValue(struct Node *head)
{
    // Initialize result variable
    long long unsigned int res = 0;

    // Traverse the linked list
    while (head != NULL)
    {
        // Calculate the decimal value by multiplying the result by 2 and adding current node's data
        // Also, use modular division to ensure the result doesn't exceed the maximum value
        res = ((res * 2) % MOD + head->data) % MOD;

        // Move to the next node
        head = head->next;
    }

    // Return the final decimal value
    return res;
}

// Test case in the main function
int main()
{
    // Create a linked list with nodes
    Node *head = new Node(true);       // Example: true represents binary 1
    head->next = new Node(false);      // Example: false represents binary 0
    head->next->next = new Node(true); // Example: true represents binary 1

    // Calculate and print the decimal value
    std::cout << "Decimal Value: " << decimalValue(head) << std::endl;

    // Free the allocated memory for the linked list
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
