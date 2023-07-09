// Title: Binary Tree Paths
// Source: https://leetcode.com/problems/binary-tree-paths
// Difficulty: Easy
// Tags: String, Backtracking, Tree, Depth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
 * A leaf is a node with no children.
 *  
 * Example 1:
 * 
 * Input: root = [1,2,3,null,5]
 * Output: ["1->2->5","1->3"]
 * Example 2:
 * Input: root = [1]
 * Output: ["1"]
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 100].
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
    void backtrack(TreeNode* root, string curPath, vector<string>& result) {
        if (!root->left && !root->right) {
            result.push_back(curPath);
            return;
        }
        if (root->left)
            backtrack(root->left, curPath + "->" + to_string(root->left->val), result);
        if (root->right)
            backtrack(root->right, curPath + "->" + to_string(root->right->val), result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        backtrack(root, to_string(root->val), res);
        return res;
    }
};