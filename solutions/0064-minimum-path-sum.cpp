// Title: Minimum Path Sum
// Source: https://leetcode.com/problems/minimum-path-sum
// Difficulty: Medium
// Tags: Array, Dynamic Programming, Matrix
// Author: nxphuc
// Time Complexity: O(N * M)
// Space Complexity: O(M)
// Note: 

/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 *  
 * Example 1:
 * 
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 * Example 2:
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 *  
 * Constraints:
 * - m == grid.length
 * - n == grid[i].length
 * - 1 <= m, n <= 200
 * - 0 <= grid[i][j] <= 200
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> f(m, INT_MAX - 1000);
        f[0] = grid[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;
                if (j > 0) f[j] = min(f[j], f[j - 1]);
                f[j] += grid[i][j];
            }
        }
        return f[m - 1];
    }
};