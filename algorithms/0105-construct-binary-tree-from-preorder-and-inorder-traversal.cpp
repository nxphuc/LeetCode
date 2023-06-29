// Title: Construct Binary Tree from Preorder and Inorder Traversal
// Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
// Difficulty: Medium
// Tags: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 *  
 * Example 1:
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * Example 2:
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *  
 * Constraints:
 * - 1 <= preorder.length <= 3000
 * - inorder.length == preorder.length
 * - -3000 <= preorder[i], inorder[i] <= 3000
 * - preorder and inorder consist of unique values.
 * - Each value of inorder also appears in preorder.
 * - preorder is guaranteed to be the preorder traversal of the tree.
 * - inorder is guaranteed to be the inorder traversal of the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& idx, int left, int right) {
        if (left > right) return nullptr;
        int pos = left;
        while (inorder[pos] != preorder[idx]) ++pos;
        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = buildTree(preorder, inorder, idx, left, pos - 1);
        root->right = buildTree(preorder, inorder, idx, pos + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int id = 0;
        return buildTree(preorder, inorder, id, 0, inorder.size() - 1);
    }
};