// Title: Longest ZigZag Path in a Binary Tree
// Source: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
// Difficulty: Medium
// Tags: Dynamic Programming, Tree, Depth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * You are given the root of a binary tree.
 * A ZigZag path for a binary tree is defined as follow:
 * - Choose any node in the binary tree and a direction (right or left).
 * - If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
 * - Change the direction from right to left or from left to right.
 * - Repeat the second and third steps until you can't move in the tree.
 * Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
 * Return the longest ZigZag path contained in that tree.
 *  
 * Example 1:
 * 
 * Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
 * Output: 3
 * Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
 * Example 2:
 * 
 * Input: root = [1,1,1,null,1,null,null,1,1,null,1]
 * Output: 4
 * Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
 * Example 3:
 * Input: root = [1]
 * Output: 0
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 5 * 10^4].
 * - 1 <= Node.val <= 100
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
    void dfs(TreeNode* root, bool turnLeft, int path, int& maxPath) {
        if (!root) return;
        maxPath = max(maxPath, path);
        if (turnLeft) {
            dfs(root->left, false, path + 1, maxPath);
            dfs(root->right, true, 1, maxPath);
        }
        else {
            dfs(root->right, true, path + 1, maxPath);
            dfs(root->left, false, 1, maxPath);
        }
    }

    int longestZigZag(TreeNode* root) {
        int res = 0;
        dfs(root, false, 0, res);
        dfs(root, true, 0, res);
        return res;
    }
};