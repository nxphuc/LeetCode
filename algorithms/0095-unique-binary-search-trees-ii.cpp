// Title: Unique Binary Search Trees II
// Source: https://leetcode.com/problems/unique-binary-search-trees-ii
// Difficulty: Medium
// Tags: Dynamic Programming, Backtracking, Tree, Binary Search Tree, Binary Tree
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
 *  
 * Example 1:
 * 
 * Input: n = 3
 * Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 * Example 2:
 * Input: n = 1
 * Output: [[1]]
 *  
 * Constraints:
 * - 1 <= n <= 8
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
    map<pair<int, int>, vector<TreeNode*>> f;

    vector<TreeNode*> dp(int l, int r) {
        if (l > r) return {nullptr};

        if (f.find({l, r}) != f.end())
            return f[{l, r}];

        vector<TreeNode*> res;
        for (int i = l; i <= r; ++i) {
            vector<TreeNode*> leftTree = dp(l, i - 1);
            vector<TreeNode*> rightTree = dp(i + 1, r);
            for (auto left : leftTree)
                for (auto right : rightTree)
                    res.push_back(new TreeNode(i, left, right));
        }
        return f[{l, r}] = res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return dp(1, n);
    }
};