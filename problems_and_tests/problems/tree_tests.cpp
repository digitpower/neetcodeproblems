#include <gtest/gtest.h>
#include <vector>
#include "inorder_traverse.h"
#include "insert_into_bst.h"


TEST(InsertIntoBSTSuite, InsertManyElementsWork)
{
    auto elements = std::vector<int>{399, 214, 137, 76, 71, 212, 174, 369, 314, 310, 397, 831, 602, 481, 407, 671, 975, 970, 854, 996};

    TreeNode* root = nullptr;
    for (auto el : elements)
        root = insert_into_bst_recursively(root, el);
    
    std::vector<int> res;
    inorder_traverse_recursive(root, res);

    auto expected = std::vector<int>{71,76,137, 174,212,214,310,314,369,397,399,407,481,602,671,831,854,970,975,996};
    ASSERT_TRUE(res == expected);
}