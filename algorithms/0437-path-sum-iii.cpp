// Title: Path Sum III
// Source: https://leetcode.com/problems/path-sum-iii
// Difficulty: Medium
// Tags: Tree, Depth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
 * The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
 *  
 * Example 1:
 * 
 * Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * Output: 3
 * Explanation: The paths that sum to 8 are shown.
 * Example 2:
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: 3
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 1000].
 * - -10^9 <= Node.val <= 10^9
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
    int dfs(TreeNode* root, int targetSum, long long curSum, unordered_map<long long, int>& prefixSum) {
        if (!root) return 0;
        curSum += root->val;
        int res = prefixSum[curSum - targetSum];
        ++prefixSum[curSum];
        res += dfs(root->left, targetSum, curSum, prefixSum);
        res += dfs(root->right, targetSum, curSum, prefixSum);
        --prefixSum[curSum];
        return res;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        return dfs(root, targetSum, 0, prefixSum);
    }
};