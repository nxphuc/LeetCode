// Title: Binary Tree Postorder Traversal
// Source: https://leetcode.com/problems/binary-tree-postorder-traversal
// Difficulty: Easy
// Tags: Stack, Tree, Depth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given the root of a binary tree, return the postorder traversal of its nodes' values.
 *  
 * Example 1:
 * 
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
 * Example 2:
 * Input: root = []
 * Output: []
 * Example 3:
 * Input: root = [1]
 * Output: [1]
 *  
 * Constraints:
 * - The number of the nodes in the tree is in the range [0, 100].
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
    void postorderTraversal(TreeNode* root, vector<int>& order) {
        if (!root) return;
        postorderTraversal(root->left, order);
        postorderTraversal(root->right, order);
        order.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        postorderTraversal(root, order);
        return order;
    }
};