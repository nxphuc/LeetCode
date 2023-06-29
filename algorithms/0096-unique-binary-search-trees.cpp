// Title: Unique Binary Search Trees
// Source: https://leetcode.com/problems/unique-binary-search-trees
// Difficulty: Medium
// Tags: Math, Dynamic Programming, Tree, Binary Search Tree, Binary Tree
// Author: nxphuc
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Note: 

/**
 * Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
 *  
 * Example 1:
 * 
 * Input: n = 3
 * Output: 5
 * Example 2:
 * Input: n = 1
 * Output: 1
 *  
 * Constraints:
 * - 1 <= n <= 19
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp(vector<vector<int>>& f, int l, int r) {
        if (l > r) return 1;

        if (f[l][r] != -1) return f[l][r];

        int& res = f[l][r];
        res = 0;
        for (int i = l; i <= r; ++i) {
            res += dp(f, l, i - 1) * dp(f, i + 1, r);
        }
        return res;
    }

    int numTrees(int n) {
        vector<vector<int>> f(n + 1, vector<int>(n + 1, -1));
        return dp(f, 1, n);
    }
};