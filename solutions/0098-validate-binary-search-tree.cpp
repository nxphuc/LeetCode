// Title: Validate Binary Search Tree
// Source: https://leetcode.com/problems/validate-binary-search-tree
// Difficulty: Medium
// Tags: Tree, Depth-First Search, Binary Search Tree, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * A valid BST is defined as follows:
 * - The left subtree of a node contains only nodes with keys less than the node's key.
 * - The right subtree of a node contains only nodes with keys greater than the node's key.
 * - Both the left and right subtrees must also be binary search trees.
 *  
 * Example 1:
 * 
 * Input: root = [2,1,3]
 * Output: true
 * Example 2:
 * 
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 10^4].
 * - -2^31 <= Node.val <= 2^31 - 1
**/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* lower, TreeNode* upper) {
        if (!root) return true;
        if (lower && lower->val >= root->val)
            return false;
        if (upper && upper->val <= root->val)
            return false;
        return isValidBST(root->left, lower, root) && isValidBST(root->right, root, upper);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
};