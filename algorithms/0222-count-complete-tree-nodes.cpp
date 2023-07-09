// Title: Count Complete Tree Nodes
// Source: https://leetcode.com/problems/count-complete-tree-nodes
// Difficulty: Medium
// Tags: Binary Search, Tree, Depth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given the root of a complete binary tree, return the number of the nodes in the tree.
 * According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2^h nodes inclusive at the last level h.
 * Design an algorithm that runs in less than O(n) time complexity.
 *  
 * Example 1:
 * 
 * Input: root = [1,2,3,4,5,6]
 * Output: 6
 * Example 2:
 * Input: root = []
 * Output: 0
 * Example 3:
 * Input: root = [1]
 * Output: 1
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 5 * 10^4].
 * - 0 <= Node.val <= 5 * 10^4
 * - The tree is guaranteed to be complete.
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
    int height(TreeNode* root) {
        int h = -1;
        while (root) {
            ++h;
            root = root->left;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int h = height(root);
        if (height(root->right) == h - 1)
            return (1 << h) + countNodes(root->right);
        return (1 << (h - 1)) + countNodes(root->left);
    }
};