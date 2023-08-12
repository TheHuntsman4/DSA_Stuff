#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert_node(struct node **root, int data){
    if(*root == NULL){
        *root = create_node(data);
        return;
    }

    if((*root)->data > data){
        insert_node(&((*root)->left), data);
    } else{
        insert_node(&((*root)->right), data);
    }
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int find_min(struct node* root){
    if(root == NULL){
        printf("The Tree is empty!!");
        return -1;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

int find_max(struct node *root){
    if(root == NULL){
        printf("Tree is empty!!");
        return -1;
    }

    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
}

int main(){
    struct node *root = NULL;

    while(1){
        printf("1. Insert a node in the Tree. \n");
        printf("2. Inorder Traversal of the Tree. \n");
        printf("3. Find the minimum value. \n");
        printf("4. Find the maximum value. \n");
        printf("5. Exit. \n");

        int choice;
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("enter data to be inserted: ");
                int data;
                scanf("%d", &data);
                insert_node(&root, data);
                break;

            case 2:
                printf("Inorder Traversal of the Tree: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                {
                    int min_val = find_min(root);
                    if(min_val != -1){
                        printf("Minimum value of the tree = %d\n", min_val);
                    }
                }
                break;

            case 4:
                {
                    int max_val = find_max(root);
                    if(max_val != -1){
                        printf("Maximum value of the tree = %d\n", max_val);
                    }
                }
                break;

            case  5:
                exit(0);
                break;

            default:
                printf("enter a valid choice!!!\n");
                break;
        }
    }
}
