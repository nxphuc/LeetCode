// Title: Maximum Level Sum of a Binary Tree
// Source: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree
// Difficulty: Medium
// Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: OI(N)
// Note: 

/**
 * Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
 * Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
 *  
 * Example 1:
 * 
 * Input: root = [1,7,0,7,-8,null,null]
 * Output: 2
 * Explanation: 
 * Level 1 sum = 1.
 * Level 2 sum = 7 + 0 = 7.
 * Level 3 sum = 7 + -8 = -1.
 * So we return the level with the maximum sum which is level 2.
 * Example 2:
 * Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * Output: 2
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 10^4].
 * - -10^5 <= Node.val <= 10^5
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
    void dfs(TreeNode* root, int level, unordered_map<int, int>& levelSum) {
        if (!root) return;
        levelSum[level] += root->val;
        dfs(root->left, level + 1, levelSum);
        dfs(root->right, level + 1, levelSum);
    }

    int maxLevelSum(TreeNode* root) {
        unordered_map<int, int> levelSum;
        int res = 1;
        dfs(root, 1, levelSum);
        for (int i = 1; levelSum.find(i) != levelSum.end(); ++i)
            if (levelSum[i] > levelSum[res]) res = i;
        return res;
    }
};