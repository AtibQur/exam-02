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

struct NodeInsert *getNewNodeInsert(int val)
{
    struct NodeInsert *newNodeInsert = malloc(sizeof(struct NodeInsert));
    newNodeInsert->key   = val;
    newNodeInsert->left  = NULL;
    newNodeInsert->right = NULL;

    return newNodeInsert;
}

struct NodeInsert *insert(struct NodeInsert *root, int val)
{
    if(root == NULL)
        return getNewNode(val);
    if(root->key < val)
        root->right = insert(root->right,val);
    else if(root->key > val)
        root->left = insert(root->left,val);
    return root;
}

//=========================================================//
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
    bool res2 = ifNodeExists(Node->right, key);
    return res2;
}