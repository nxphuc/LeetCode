// Title: Search in a Binary Search Tree
// Source: https://leetcode.com/problems/search-in-a-binary-search-tree
// Difficulty: Easy
// Tags: Tree, Binary Search Tree, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * You are given the root of a binary search tree (BST) and an integer val.
 * Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
 *  
 * Example 1:
 * 
 * Input: root = [4,2,7,1,3], val = 2
 * Output: [2,1,3]
 * Example 2:
 * 
 * Input: root = [4,2,7,1,3], val = 5
 * Output: []
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 5000].
 * - 1 <= Node.val <= 10^7
 * - root is a binary search tree.
 * - 1 <= val <= 10^7
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        if (root->val > val)
            return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};