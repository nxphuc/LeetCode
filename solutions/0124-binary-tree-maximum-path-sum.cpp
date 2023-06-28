// Title: Binary Tree Maximum Path Sum
// Source: https://leetcode.com/problems/binary-tree-maximum-path-sum
// Difficulty: Hard
// Tags: Dynamic Programming, Tree, Depth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
 * The path sum of a path is the sum of the node's values in the path.
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
 *  
 * Example 1:
 * 
 * Input: root = [1,2,3]
 * Output: 6
 * Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
 * Example 2:
 * 
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 3 * 10^4].
 * - -1000 <= Node.val <= 1000
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
    // first is maximum path sum in subtree of root
    // second is maximum path sum from root to some node in subtree
    pair<int, int> maxPathSumHelper(TreeNode* root) {
        if (!root)
            return {(int)-1e8, 0};

        auto left = maxPathSumHelper(root->left);
        auto right = maxPathSumHelper(root->right);
        return {
            max({ root->val + left.second + right.second, left.first, right.first }),
            max({ 0, root->val + max(left.second, right.second) })
        };
    }

    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        return maxPathSumHelper(root).first;
    }
};