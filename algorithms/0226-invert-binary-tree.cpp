// Title: Invert Binary Tree
// Source: https://leetcode.com/problems/invert-binary-tree
// Difficulty: Easy
// Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given the root of a binary tree, invert the tree, and return its root.
 *  
 * Example 1:
 * 
 * Input: root = [4,2,7,1,3,6,9]
 * Output: [4,7,2,9,6,3,1]
 * Example 2:
 * 
 * Input: root = [2,1,3]
 * Output: [2,3,1]
 * Example 3:
 * Input: root = []
 * Output: []
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 100].
 * - -100 <= Node.val <= 100
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode* left = invertTree(root->right);
        TreeNode* right = invertTree(root->left);
        root->left = left;
        root->right = right;
        return root;
    }
};