// Title: Minimum Absolute Difference in BST
// Source: https://leetcode.com/problems/minimum-absolute-difference-in-bst
// Difficulty: Easy
// Tags: Tree, Depth-First Search, Breadth-First Search, Binary Search Tree, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
 *  
 * Example 1:
 * 
 * Input: root = [4,2,6,1,3]
 * Output: 1
 * Example 2:
 * 
 * Input: root = [1,0,48,null,null,12,49]
 * Output: 1
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [2, 10^4].
 * - 0 <= Node.val <= 10^5
 *  
 * Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    int dfs(TreeNode* root, int& prev) {
        if (!root) return INT_MAX;
        int res = dfs(root->left, prev);
        res = min(res, root->val - prev);
        prev = root->val;
        res = min(res, dfs(root->right, prev));
        return res;
    }

    int getMinimumDifference(TreeNode* root) {
        int prev = -1e6;
        return dfs(root, prev);
    }
};