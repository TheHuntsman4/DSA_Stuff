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

struct node* find_min_node(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* delete_node(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = find_min_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }

    return root;
}

int main() {
    struct node* root = NULL;
    
    while (1) {
        printf("1. Insert a node.\n");
        printf("2. Inorder traversal.\n");
        printf("3. Delete a node.\n");
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
            printf("enter the data to delete: ");
            int val;
            scanf("%d", &val);
            delete_node(root, val);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice. \n");
            break;
        }
    }

    return 0;
}