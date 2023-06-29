// Title: Construct Binary Tree from Inorder and Postorder Traversal
// Source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
// Difficulty: Medium
// Tags: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
 *  
 * Example 1:
 * 
 * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * Output: [3,9,20,null,null,15,7]
 * Example 2:
 * Input: inorder = [-1], postorder = [-1]
 * Output: [-1]
 *  
 * Constraints:
 * - 1 <= inorder.length <= 3000
 * - postorder.length == inorder.length
 * - -3000 <= inorder[i], postorder[i] <= 3000
 * - inorder and postorder consist of unique values.
 * - Each value of postorder also appears in inorder.
 * - inorder is guaranteed to be the inorder traversal of the tree.
 * - postorder is guaranteed to be the postorder traversal of the tree.
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
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int& idx, int left, int right) {
        if (left > right) return nullptr;
        int pos = left;
        while (inorder[pos] != postorder[idx]) ++pos;
        TreeNode *root = new TreeNode(postorder[idx--]);
        root->right = buildTree(postorder, inorder, idx, pos + 1, right);
        root->left = buildTree(postorder, inorder, idx, left, pos - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int id = postorder.size() - 1;;
        return buildTree(postorder, inorder, id, 0, inorder.size() - 1);
    }
};