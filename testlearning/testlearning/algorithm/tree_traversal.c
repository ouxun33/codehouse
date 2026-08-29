#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(TreeNode *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelOrder(TreeNode *root) {
    if (root == NULL) return;
    
    TreeNode *queue[MAX_N];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        TreeNode *node = queue[front++];
        printf("%d ", node->data);
        
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}

int main() {
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    printf("二叉树结构:\n");
    printf("      1\n");
    printf("    /   \\\n");
    printf("   2     3\n");
    printf("  / \\   / \\\n");
    printf(" 4   5 6   7\n");
    printf("\n");
    
    printf("前序遍历(根-左-右): ");
    preorder(root);
    printf("\n");
    
    printf("中序遍历(左-根-右): ");
    inorder(root);
    printf("\n");
    
    printf("后序遍历(左-右-根): ");
    postorder(root);
    printf("\n");
    
    printf("层序遍历(BFS): ");
    levelOrder(root);
    printf("\n");
    
    return 0;
}