// Title: Binary Tree Preorder Traversal
// Source: https://leetcode.com/problems/binary-tree-preorder-traversal
// Difficulty: Easy
// Tags: Stack, Tree, Depth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given the root of a binary tree, return the preorder traversal of its nodes' values.
 *  
 * Example 1:
 * 
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
 * Example 2:
 * Input: root = []
 * Output: []
 * Example 3:
 * Input: root = [1]
 * Output: [1]
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 100].
 * - -100 <= Node.val <= 100
 *  
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    void preorderTraversal(TreeNode* root, vector<int>& order) {
        if (!root) return;
        order.push_back(root->val);
        preorderTraversal(root->left, order);
        preorderTraversal(root->right, order);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        preorderTraversal(root, order);
        return order;
    }
};