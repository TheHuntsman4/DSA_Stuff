#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* link;
};

// Head pointer
struct node* head = NULL;
struct node* tail = NULL;
// Function to create the linked list
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
    head->link = head;

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
        newnode->link = head;

        temp->link = newnode;
        temp = temp->link;
    }
    tail=temp;
}

// Function to traverse and display the linked list
void traversal() {
    struct node* temp = head;
    int i = 0;

    while (temp->link != head) {
        printf("Value is %d. Address of the next node is %p\n", temp->data, (void*)temp->link);
        temp = temp->link;
        i++;
    }

    printf("The length of the list is %d\n", i);
    printf("this is the tail pointer %p", tail);
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
    tail->link=newnode;
    head=newnode;

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
    newnode->link = NULL;

    if (head == NULL) {
        head = newnode;
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

    temp = head;
    prev = NULL;

    while (temp != NULL && counter < position) {
        prev = temp;
        temp = temp->link;
        counter++;
    }

    if (temp == NULL) {
        printf("Invalid position Inserting at the end\n");
        prev->link = newnode;
    } else {
        newnode->link = temp;
        if (prev == NULL) {
            head = newnode;
        } else {
            prev->link = newnode;
        }
    }

    traversal();
}

// Function to reverse the linked list
void reverse() {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    head = prev;

    traversal();
}

// Function to delete the first node
void deletebeg() {
    if (head == NULL) {
        printf("List is empty unable to delete\n");
        return;
    }
    struct node* temp = head;
    head = head->link;
    free(temp);

    traversal();
}

void deleteend(){
    struct node *temp=head;
    struct node *prev=NULL;
    while(temp->link!=NULL){
        prev=temp;
        temp=temp->link;
    }
    prev->link=head;
    free(temp);
    traversal();
}

void deletepos() {
    int position, counter = 1;
    struct node* temp = head;
    struct node* prev = NULL;

    if (temp == NULL) {
        printf("List is empty unable to delete.");
        return;
    }

    printf("Enter the position to delete: ");
    scanf("%d", &position);
    while (temp != NULL && counter < position) {
        prev = temp;
        temp = temp->link;
        counter++;
    }

    if (temp == NULL) {
        printf("Invalid position. Unable to delete.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->link;
    } else {
        prev->link = temp->link;
    }

    free(temp);

    traversal();
}


void length(){
    struct node *temp=head;
    int counter=0;
    while(temp->link!=NULL){
        counter++;
    }
    printf("The length of the Linked List is %d",counter);
}

int main(){
    int n,op;
    printf("enter the number of nodes ");
    scanf("%d",&n);
    createlist(n);
    printf("Linked List OPERATION MENU\n1. FIND LENGTH OF LINKED LIST\n2. INSERT NODE TO BEGINNING\n3. INSERT NODE TO THE END\n4. INSERT NODE TO A SPECIFIC POINT\n5. REVERSE THE LINKED LIST\n6. DELETE NODE FROM THE BEGINNING\n7. DELETE NODE AT THE END\n8. DELETE FROM SPECIFIED POSITION\n");
    scanf("%d",&op);
    switch(op){
        case 1:
        traversal();
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
    

}
