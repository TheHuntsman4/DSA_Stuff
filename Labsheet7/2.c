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
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node* root = NULL;
    
    while (1) {
        printf("1. Insert a node.\n");
        printf("2. Inorder traversal.\n");
        printf("3. Preorder traversal.\n");
        printf("4. Postorder traversal.\n");
        printf("5. Exit.\n");

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
            printf("Preorder Traversal of the Tree: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder Traversal of the Tree: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice. \n");
            break;
        }
    }

    return 0;
}