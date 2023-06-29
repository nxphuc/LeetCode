// Title: Path Sum II
// Source: https://leetcode.com/problems/path-sum-ii
// Difficulty: Medium
// Tags: Backtracking, Tree, Depth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
 * A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
 *  
 * Example 1:
 * 
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2],[5,8,4,5]]
 * Explanation: There are two paths whose sum equals targetSum:
 * 5 + 4 + 11 + 2 = 22
 * 5 + 8 + 4 + 5 = 22
 * Example 2:
 * 
 * Input: root = [1,2,3], targetSum = 5
 * Output: []
 * Example 3:
 * Input: root = [1,2], targetSum = 0
 * Output: []
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 5000].
 * - -1000 <= Node.val <= 1000
 * - -1000 <= targetSum <= 1000
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
    void helper(vector<vector<int>>& result, vector<int>& path, TreeNode* root, int target) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (target == root->val) {
                result.push_back(path);
                result.back().push_back(target);
            }
            return;
        }
        target -= root->val;
        path.push_back(root->val);
        helper(result, path, root->left, target);
        helper(result, path, root->right, target);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>> result;
        vector<int> path;
        helper(result, path, root, targetSum);
        return result;
    }
};