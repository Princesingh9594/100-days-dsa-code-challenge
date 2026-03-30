#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int preIndex = 0;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end) {
    if (start > end)
        return NULL;

    int curr = preorder[preIndex++];
    Node* root = newNode(curr);

    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, curr);

    root->left = buildTree(preorder, inorder, start, inIndex - 1);
    root->right = buildTree(preorder, inorder, inIndex + 1, end);

    return root;
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    Node* root = buildTree(preorder, inorder, 0, n - 1);

    postorder(root);

    return 0;
}
