#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

// Head pointer
struct node* head = NULL;

// Function to create the doubly linked list
void createList(int n) {
    struct node* newnode, *temp;
    int data, i;

    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Unable to allocate memory.");
        return;
    }

    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->prev = NULL;
    head->next = NULL;

    temp = head;
    for (i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        if (newnode == NULL) {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->prev = temp;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
}

// Function to traverse and display the doubly linked list
void traversal() {
    struct node* temp = head;
    int count = 0;

    while (temp != NULL) {
        printf("Value: %d, Address: %p, Prev: %p, Next: %p\n", temp->data, (void*)temp, (void*)temp->prev, (void*)temp->next);
        temp = temp->next;
        count++;
    }

    printf("The length of the list is %d\n", count);
}

// Function to insert a node at the beginning
void insertBegin() {
    struct node* newnode;
    int data;

    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Unable to allocate memory.");
        return;
    }

    printf("Enter the value of the new node: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }

    head = newnode;

    traversal();
}

// Function to insert a node at the end
void insertEnd() {
    struct node* newnode, *temp;
    int data;

    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Unable to allocate memory.");
        return;
    }

    printf("Enter the value of the new node: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

    traversal();
}

// Function to insert a node at a specific position
void insertPos() {
    int position, counter = 1;
    int data;
    struct node* newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Unable to allocate memory.");
        return;
    }

    printf("Enter the position to insert: ");
    scanf("%d", &position);

    printf("Enter the value of the new node: ");
    scanf("%d", &data);

    newnode->data = data;

    if (position == 1) {
        newnode->prev = NULL;
        newnode->next = head;

        if (head != NULL) {
            head->prev = newnode;
        }

        head = newnode;
    } else {
        temp = head;
        while (temp != NULL && counter < position - 1) {
            temp = temp->next;
            counter++;
        }

        if (temp == NULL) {
            printf("Invalid position. Inserting at the end\n");
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        } else {
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;

            if (newnode->next != NULL) {
                newnode->next->prev = newnode;
            }
        }
    }

    traversal();
}

// Function to reverse the doubly linked list
void reverse() {
    struct node* temp = NULL;
    struct node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    traversal();
}

// Function to delete the first node
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    struct node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);

    traversal();
}

// Function to delete the last node
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    struct node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);

    traversal();
}

// Function to delete a node at a specific position
void deletePos() {
    if (head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    int position, counter = 1;
    struct node* temp = head;

    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }

        free(temp);
    } else {
        while (temp != NULL && counter < position) {
            temp = temp->next;
            counter++;
        }

        if (temp == NULL) {
            printf("Invalid position. Unable to delete.\n");
            return;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        free(temp);
    }

    traversal();
}

int main() {
    int choice, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createList(n);

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert node at the beginning\n");
        printf("2. Insert node at the end\n");
        printf("3. Insert node at a specific position\n");
        printf("4. Delete node from the beginning\n");
        printf("5. Delete node from the end\n");
        printf("6. Delete node from a specific position\n");
        printf("7. Reverse the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertBegin();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertPos();
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deletePos();
                break;
            case 7:
                reverse();
                break;
            case 8:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}
