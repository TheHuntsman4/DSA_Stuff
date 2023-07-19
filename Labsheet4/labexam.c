#include<stdio.h>

struct node{
    int data;
    struct node* link;
};

struct node* tail=NULL;

void insertAtEnd(){
    struct node*newnode;
    int data;
    scanf("%d",&data);
    newnode=(struct node*)malloc(sizeof(struct node));
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

void sort(){
    struct node* current=tail->link;
    struct node* next;
    int temp;
    do{
        next=current->link;
        while(next!=tail->link){
            if(current->data>next->data){
                temp=current->data;
                current->data=next->data;
                next->data=temp;
            }next=next->link;
        }current=current->link;
    }
    while(current!=tail->link);

}

void reverse(){
    struct node* prev=NULL;
    struct node* current= tail->link;
    struct node* next;

    do{
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }while(current!=tail->link);
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
    int len;
    printf("enter the length of the linked list");
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        insertAtEnd();
    }
    display();
    sort();
    display();
    reverse();
    display();
    return 0;
}