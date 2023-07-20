// Title: Average of Levels in Binary Tree
// Source: https://leetcode.com/problems/average-of-levels-in-binary-tree
// Difficulty: Easy
// Tags: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10^-5 of the actual answer will be accepted.
 *  
 * Example 1:
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [3.00000,14.50000,11.00000]
 * Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
 * Hence return [3, 14.5, 11].
 * Example 2:
 * 
 * Input: root = [3,9,20,15,7]
 * Output: [3.00000,14.50000,11.00000]
 *  
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 10^4].
 * - -2^31 <= Node.val <= 2^31 - 1
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
    void dfs(TreeNode* root, int level, vector<int>& cnt, vector<double>& sum) {
        if (!root) return;
        if (level == cnt.size()) {
            cnt.emplace_back();
            sum.emplace_back();
        }
        ++cnt[level];
        sum[level] += root->val;
        dfs(root->left, level + 1, cnt, sum);
        dfs(root->right, level + 1, cnt, sum);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum;
        vector<int> cnt;
        dfs(root, 0, cnt, sum);
        for (int i = 0; i < cnt.size(); ++i)
            sum[i] /= cnt[i];
        return sum;
    }
};