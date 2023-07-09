#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* link;
};

// Head pointer
struct node* head = NULL;

// Function to create the circular linked list
void createlist(int n) {
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
    head->link = NULL;

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
        newnode->link = NULL;

        temp->link = newnode;
        temp = temp->link;
    }

    // Make the last node point back to the head to form a circular list
    temp->link = head;
}

// Function to traverse and display the circular linked list
void traversal() {
    struct node* temp = head;
    int i = 0;

    do {
        printf("Value is %d. Address of the next node is %p\n", temp->data, (void*)temp->link);
        temp = temp->link;
        i++;
    } while (temp != head);

    printf("The length of the list is %d\n", i);
}

// Function to insert a node at the beginning
void insertbegin() {
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
    newnode->link = head;

    // Update the last node to point to the new node
    struct node* last = head;
    while (last->link != head) {
        last = last->link;
    }
    last->link = newnode;

    head = newnode;

    traversal();
}

// Function to insert a node at the end
void insertend() {
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
    newnode->link = head;

    if (head == NULL) {
        head = newnode;
        newnode->link = head;
    } else {
        temp = head;
        while (temp->link != head) {
            temp = temp->link;
        }
        temp->link = newnode;
    }

    traversal();
}

// Function to insert a node at a specific position
void insertpos() {
    int position, counter = 1;
    int data;
    struct node* newnode, *temp, *prev;

    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Unable to allocate memory.");
        return;
    }

    printf("Enter the position where to insert: ");
    scanf("%d", &position);

    printf("Enter the value of the new node: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->link = NULL;

    temp = head->link;
    prev = temp;


    while (temp != head && counter < position) {
        prev = temp;
        temp = temp->link;
        counter++;
    }

    if (temp == head) {
        printf("Invalid position. Inserting at the end.\n");
        prev->link = newnode;
        newnode->link = head;
    } else {
        newnode->link = temp;
        if (prev == NULL) {
            struct node* last = head;
            while (last->link != head) {
                last = last->link;
            }
            last->link = newnode;
            head = newnode;
        } else {
            prev->link = newnode;
        }
    }

    traversal();
}

// Function to reverse the circular linked list
void reverse() {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    do {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->link = prev;
    head = prev;

    traversal();
}

// Function to delete the first node
void deletebeg() {
    if (head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    struct node* temp = head;
    struct node* last = head;

    while (last->link != head) {
        last = last->link;
    }

    if (head == last) {
        head = NULL;
    } else {
        head = head->link;
        last->link = head;
    }

    free(temp);

    traversal();
}

// Function to delete the last node
void deleteend() {
    struct node* temp = head;
    struct node* prev = NULL;

    if (temp == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    while (temp->link != head) {
        prev = temp;
        temp = temp->link;
    }

    if (prev == NULL) {
        head = NULL;
    } else {
        prev->link = head;
    }

    free(temp);

    traversal();
}

// Function to delete a node at a specific position
void deletepos() {
    int position, counter = 1;
    struct node* temp = head;
    struct node* prev = NULL;

    if (temp == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position == 1) {
        deletebeg();
        return;
    }

    while (temp->link != head && counter < position) {
        prev = temp;
        temp = temp->link;
        counter++;
    }

    if (temp == head) {
        printf("Invalid position. Unable to delete.\n");
        return;
    }

    prev->link = temp->link;

    free(temp);

    traversal();
}


void length(){
    struct node *temp=head;
    int counter=0;
    do {
        counter++;
        temp = temp->link;
    } while (temp != head);
    printf("The length of the Linked List is %d\n", counter);
}

int main() {
    int n, op;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createlist(n);
    printf("Circular Linked List OPERATION MENU\n1. FIND LENGTH OF LINKED LIST\n2. INSERT NODE TO BEGINNING\n3. INSERT NODE TO THE END\n4. INSERT NODE TO A SPECIFIC POINT\n5. REVERSE THE LINKED LIST\n6. DELETE NODE FROM THE BEGINNING\n7. DELETE NODE AT THE END\n8. DELETE FROM SPECIFIED POSITION\n");
    scanf("%d", &op);
    switch (op) {
        case 1:
            length();
            break;
        case 2:
            insertbegin();
            break;
        case 3:
            insertend();
            break;
        case 4:
            insertpos();
            break;
        case 5:
            reverse();
            break;
        case 6:
            deletebeg();
            break;
        case 7:
            deleteend();
            break;
        case 8:
            deletepos();
            break;
        default:
            printf("Invalid op-code, please try again");
    }

    return 0;
}
