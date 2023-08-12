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

void reverse_inorder(struct node* root, int k, int* count, int* result) {
    if (root == NULL) {
        return;
    }

    reverse_inorder(root->right, k, count, result);

    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }

    reverse_inorder(root->left, k, count, result);
}

int find_kth_largeval(struct node* root, int k) {
    int count = 0;
    int result = -1; // This will hold the kth largest value

    reverse_inorder(root, k, &count, &result);

    return result;
}

int main() {
    struct node* root = NULL;
    
    while (1) {
        printf("1. Insert a node.\n");
        printf("2. Inorder traversal.\n");
        printf("3. Find the kth largest value. \n");
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
                {
                    int k;
                    printf("Enter the value of k: ");
                    scanf("%d", &k);
                    int kth_largest = find_kth_largeval(root, k);
                    printf("The %dth largest value in the tree: %d\n", k, kth_largest);
                }
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