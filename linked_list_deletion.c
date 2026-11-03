#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Delete first node
void deleteFirst() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}

// Delete a specified element
void deleteSpecified(int value) {
    struct Node *temp, *ptr;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == value) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;

    while (temp->next != NULL &&
           temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element not found\n");
        return;
    }

    ptr = temp->next;
    temp->next = ptr->next;

    free(ptr);
}

// Delete last node
void deleteLast() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Display linked list
void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    int n, value, choice, i;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    do {
        printf("\n1. Delete first node");
        printf("\n2. Delete specified element");
        printf("\n3. Delete last node");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFirst();
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                deleteSpecified(value);
                break;

            case 3:
                deleteLast();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}


