#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *insert_new(struct node* root, int val) {
    struct node *ret = malloc(sizeof(struct node));
    ret->key = val;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

struct node *insert(struct node* root, int val) {
    if (root == NULL)
        return insert_new(root, val);
    if (root->key < val)
        root->right = insert(root->right, val);
    else if (root->key > val)
        root->left = insert(root->left, val);
    return root;    
}

struct Node {
    int data;
    struct Node *left, *right;
};

bool search(struct Node* root, int val) {
    if (root == NULL)
        return false;
    if (root->data == val)
        return true;
    bool res1 = search(root->left, val);
    if (res1)
        return true;
    bool res2 = search(root->right, val);
    if (res2)
        return res2;
}