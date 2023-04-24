#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

struct NodeInsert
{
    int key;
    struct NodeInsert *left;
    struct NodeInsert *right;
};

struct NodeInsert *getNodeInsert(int val) {
    struct NodeInsert *newNode = malloc(sizeof(struct NodeInsert));
    newNode->key = val;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct NodeInsert *insert(struct NodeInsert *root, int val) {

    if (root == NULL)
        return getNodeInsert(val);
    if (root->key < val)
        root->right = insert(root->right, val);
    if (root->key > val)
        root->left = insert(root->left, val);
    return root;
}

struct Node {
    int data;
    struct Node *left; 
    struct Node *right;
};

bool ifNodeExists(struct Node* Node, int key)
{
    if (Node == NULL)
        return false;
    if (Node->data == key)
        return true;
    
    bool res1 = ifNodeExists(Node->left, key);
    if (res1)
        return true;
    bool res2 = ifNodeExists(Node->right, key)
    return res2;
}