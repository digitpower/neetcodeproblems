#include "inorder_traverse.h"

void inorder_traverse_recursive(TreeNode* node, std::vector<int>& values)
{
    if(node == nullptr)
        return;
    inorder_traverse_recursive(node->left, values);
    values.push_back(node->val);
    inorder_traverse_recursive(node->right, values);
}