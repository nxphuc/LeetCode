// Title: Maximal Square
// Source: https://leetcode.com/problems/maximal-square
// Difficulty: Medium
// Tags: Array, Dynamic Programming, Matrix
// Author: nxphuc
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
// Note: 

/**
 * Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 *  
 * Example 1:
 * 
 * Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 4
 * Example 2:
 * 
 * Input: matrix = [["0","1"],["1","0"]]
 * Output: 1
 * Example 3:
 * Input: matrix = [["0"]]
 * Output: 0
 *  
 * Constraints:
 * - m == matrix.length
 * - n == matrix[i].length
 * - 1 <= m, n <= 300
 * - matrix[i][j] is '0' or '1'.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (matrix[i - 1][j - 1] == '1') {
                    f[i][j] = min(f[i - 1][j - 1], min(f[i][j - 1], f[i - 1][j])) + 1;
                    res = max(res, f[i][j]);
                }
        return res * res;
    }
};