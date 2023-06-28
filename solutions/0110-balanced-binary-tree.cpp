// Title: Balanced Binary Tree
// Source: https://leetcode.com/problems/balanced-binary-tree
// Difficulty: Easy
// Tags: Tree, Depth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given a binary tree, determine if it is height-balanced.
 *  
 * Example 1:
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 * Example 2:
 * 
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 * Example 3:
 * Input: root = []
 * Output: true
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 5000].
 * - -10^4 <= Node.val <= 10^4
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
    // returns height of rooted subtree
    // if subtree is not balanced, return -1
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};