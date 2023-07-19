// Title: Equal Row and Column Pairs
// Source: https://leetcode.com/problems/equal-row-and-column-pairs
// Difficulty: Medium
// Tags: Array, Hash Table, Matrix, Simulation
// Author: nxphuc
// Time Complexity: O(N^2 * logN)
// Space Complexity: O(N)
// Note: 

/**
 * Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
 * A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).
 *  
 * Example 1:
 * 
 * Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
 * Output: 1
 * Explanation: There is 1 equal row and column pair:
 * - (Row 2, Column 1): [2,7,7]
 * Example 2:
 * 
 * Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
 * Output: 3
 * Explanation: There are 3 equal row and column pairs:
 * - (Row 0, Column 0): [3,1,2,2]
 * - (Row 2, Column 2): [2,4,2,2]
 * - (Row 3, Column 2): [2,4,2,2]
 *  
 * Constraints:
 * - n == grid.length == grid[i].length
 * - 1 <= n <= 200
 * - 1 <= grid[i][j] <= 10^5
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt = 0;

        int n = grid.size();
        map<vector<int>, int> hashRow;
        for (int r = 0; r < n; ++r) {
            ++hashRow[grid[r]];
        }

        for (int c = 0; c < n; ++c) {
            vector<int> col;
            for (int r = 0; r < n; ++r)
                col.emplace_back(grid[r][c]);
            cnt += hashRow[col];
        }
        return cnt;
    }
};