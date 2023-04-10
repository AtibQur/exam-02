struct node *insert(struct node *root, int val)
{
    if(root == NULL)
        return getNewNode(val);
    if(root->key < val)
        root->right = insert(root->right,val);

    else if(root->key > val)
        root->left = insert(root->left,val);
    return root;
}

bool ifNodeExists(struct Node* node, int key)
{
    if (node == NULL)
        return false;
    if (node->data == key)
        return true;
    bool res1 = ifNodeExists(node->left, key);
    if (res1)
        return true;
    bool res2 = ifNodeExists(node->right, key);
    return res2;
}