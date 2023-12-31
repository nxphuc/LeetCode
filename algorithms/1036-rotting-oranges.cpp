// Title: Rotting Oranges
// Source: https://leetcode.com/problems/rotting-oranges
// Difficulty: Medium
// Tags: Array, Breadth-First Search, Matrix
// Author: nxphuc
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
// Note: 

/**
 * You are given an m x n grid where each cell can have one of three values:
 * - 0 representing an empty cell,
 * - 1 representing a fresh orange, or
 * - 2 representing a rotten orange.
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
 * Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 *  
 * Example 1:
 * 
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * Example 2:
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
 * Example 3:
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 *  
 * Constraints:
 * - m == grid.length
 * - n == grid[i].length
 * - 1 <= m, n <= 10
 * - grid[i][j] is 0, 1, or 2.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) ++cnt;
                else if (grid[i][j] == 2)
                    q.emplace(i, j);
            }
        int res = 0;
        while (!q.empty() && cnt > 0) {
            int k = q.size();
            ++res;
            while (k--) {
                auto [u, v] = q.front();
                q.pop();

                for (int x, y, i = 0; i < 4; ++i) {
                    x = u + dx[i];
                    y = v + dy[i];
                    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    --cnt;
                    q.emplace(x, y);
                }
            }
        }
        return cnt > 0 ? -1 : res;
    }
};