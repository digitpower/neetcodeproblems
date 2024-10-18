#include "insert_into_bst.h"


TreeNode* insert_into_bst_recursively(TreeNode* root, int value)
{
    if(root == nullptr)
    {
        TreeNode* newNode = new TreeNode(value);
        return newNode;
    }
    if(value < root->val)
        root->left = insert_into_bst_recursively(root->left, value);
    else if(value > root->val)
        root->right = insert_into_bst_recursively(root->right, value);
    return root;
}