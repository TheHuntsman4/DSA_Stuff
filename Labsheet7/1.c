#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createTreeNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertTreeNode(struct TreeNode** root, int value) {
    if (*root == NULL) {
        *root = createTreeNode(value);
        return;
    }

    if (value < (*root)->value) {
        insertTreeNode(&((*root)->left), value);
    } else {
        insertTreeNode(&((*root)->right), value);
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->value);
    inorderTraversal(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    
    while (1) {
        printf("Binary Search Tree Operations:\n");
        printf("1. Insert a node.\n");
        printf("2. Inorder traversal.\n");
        printf("3. Exit.\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                int value;
                scanf("%d", &value);
                insertTreeNode(&root, value);
                break;

            case 2:
                printf("Inorder Traversal of the Tree: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid choice. \n");
                break;
        }
    }

    return 0;
}

