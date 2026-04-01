// #include <stdio.h>

// // Define the Node structure
// struct Node {
//     int data;               // Data stored in the node
//     struct Node* next;      // Pointer to the next node
// };

// // Function to traverse and print the linked list
// void traverseLinkedList(struct Node* head) {
//     struct Node* current = head;

//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }

//     printf("\n");
// }

// int main() {
//     // Create nodes as local variables
//     struct Node node1, node2, node3;

//     // Assign values and link nodes
//     node1.data = 1;
//     node1.next = &node2;

//     node2.data = 2;
//     node2.next = &node3;

//     node3.data = 3;
//     node3.next = NULL;

//     // Call the function with the head node
//     traverseLinkedList(&node1);

//     return 0;
// }



#include <stdio.h>

// Define the Node structure
struct Node {
    int data;               // Data stored in the node
    struct Node* next;      // Pointer to the next node
};

// Function to traverse and print the linked list
void traverseLinkedList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    // Create an array of nodes
    struct Node nodes[3];

    // Assign data and link nodes
    nodes[0].data = 1;
    nodes[0].next = &nodes[1];  // Point to the second node

    nodes[1].data = 2;
    nodes[1].next = &nodes[2];  // Point to the third node

    nodes[2].data = 3;
    nodes[2].next = NULL;       // Last node points to NULL

    // Call the function with the head node
    traverseLinkedList(&nodes[0]);

    return 0;
}
