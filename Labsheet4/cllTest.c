#include <stdio.h>

struct node{
    int data;
    struct node* link;
};

struct node* tail=NULL;

void sort(){
    struct node* current=tail->link;
    struct node* next;
    int temp;
    do{
        next=current->link;
        while(next!=tail->link){
        if(current->data > next->data){
            temp=current->data;
            current->data=next->data;
            next->data=temp;
        }
            next=next->link;
        }current=current->link;
    }while(current!=tail->link);
}


void insertAtEnd(){
    struct node* newnode;
    int data;
    printf("enter the data ");
    scanf("%d",&data);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(tail==NULL){
        tail=newnode;
        newnode->link=tail;
    }
    else{
        newnode->link=tail->link;
        tail->link=newnode;
        tail=newnode;

    }
    
}

void insertAtBeg(){
    struct node* newnode;
    int data;
    printf("enter the data ");
    scanf("%d",&data);
    newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(tail==NULL){
        tail=newnode;
        tail->link=newnode;
    }
    else{
        newnode->link=(tail->link);
        tail->link=newnode;
    }
}

void insertAtPos(){
    struct node* newnode,*temp;
    int data, position;
    printf("enter the data ");
    scanf("%d",&data);
    printf("enter the position to insert node ");
    scanf("%d",&position);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    temp=tail;
    int counter = 1;
    while(counter!=position){
        temp=temp->link;
        counter++;
    }
    newnode->link=temp->link;
    temp->link=newnode;
    
}

void deletebeg(){
    struct node* temp;
    temp=tail->link;
    tail->link=temp->link;
    free(temp);
}

void deleteend(){
    struct node* temp=tail->link;
    while(temp->link!=tail){
        temp=temp->link;
    }
    temp->link=tail->link;
    free(tail);
    tail=temp;
}

void reverse(){
    struct node* prev = NULL;
    struct node* current = tail->link;
    struct node* next;
    do{
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    while(current!=tail->link);
    tail=prev;
}
void display(){
if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* current = tail->link;  // Start from the head (tail->next)

    printf("Circular Linked List: ");

    do {
        printf("%d\n the address is %p\n ", current->data,(void*)current->link);
        current = current->link;
    } while (current != tail->link);  // Stop when we reach the head again

    printf("\n");

}

int main(){
    int len=0;
    int choice;
    printf("Enter the lenght of the linked list");
    scanf("%d",&len);
    for(int i =0;i<len;i++){
        insertAtEnd();
    }
    display();
    printf("enter which op to do ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        insertAtBeg();
        display();
        break;
        case 2:
        insertAtEnd();
        display();
        break;
        case 3:
        insertAtPos();
        display();
        break;
        case 4:
        deletebeg();
        display();
        break;
        case 5:
        reverse();
        display();
        break;
        case 6:
        sort();
        display();
        default:
        printf("invaid op code");
    }
    return 0;
}