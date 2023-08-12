#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

void insert_node(struct node** root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    if (data < (*root)->data) {
        insert_node(&((*root)->left), data);
    } else {
        insert_node(&((*root)->right), data);
    }
}

void inorder(struct node* root) {
    if (root ==  NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct node* search_val(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search_val(root->left, data);
    } else {
        return search_val(root->right, data);
    }
}

int main() {
    struct node* root = NULL;

    while (1) {
        printf("1. Insert a node.\n");
        printf("2. Inorder traversal.\n");
        printf("3. Search an element.\n");
        printf("4. Exit.\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
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
                printf("Enter the value to be searched: ");
                int val;
                scanf("%d", &val);
                struct node* result = search_val(root, val);
                if (result != NULL) {
                    printf("%d is found in the tree\n", val);
                } else {
                    printf("%d is not found in the tree\n", val);
                }
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Enter a valid choice!!!\n");
                break;
        }
    }

    return 0;
}