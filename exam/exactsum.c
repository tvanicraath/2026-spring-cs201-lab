#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(int data) {   // initializes node with no children
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        // good practice to check malloc failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert_left(Node* u, int data) {
    return u->left = newNode(data);
}

Node* insert_right(Node* u, int data) {
    return u->right = newNode(data);
}

Node* build_tree() {    // builds the tree shown in the problem statement
    Node* root = newNode(1);
    Node* a = insert_left(root, 7);
    Node* b = insert_right(root, 9);
    insert_left(a, 2);
    Node* c = insert_right(a, 6);
    insert_left(c, 5);
    insert_right(c, 11);
    Node* d = insert_right(b, 9);
    insert_left(d, 5);
    return root;
}

void free_tree(Node* node) {
    if (node == NULL) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

int is_leaf(const Node* node) {
    // a node is a leaf if it is not NULL and has no children
    return node && !node->left && !node->right;
}

int exact_sum(const Node* root, int target) {
    if (root == NULL) return 0; // base case
    if (is_leaf(root))  return root->data == target;    // if we are at a leaf, check if the target is equal to the leaf's value
    target -= root->data;
    return exact_sum(root->left, target) || exact_sum(root->right, target); // recursively check if we can find the target in either subtree
}

int main() {
    Node* root = build_tree();
    printf("exact_sum(19) = %d\n", exact_sum(root, 19)); // true
    printf("exact_sum(20) = %d\n", exact_sum(root, 20)); // false
    free_tree(root);    // each malloc should have a corresponding free to avoid memory leaks
    return 0;
}