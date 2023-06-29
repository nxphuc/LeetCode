// Title: Number of Islands
// Source: https://leetcode.com/problems/number-of-islands
// Difficulty: Medium
// Tags: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
// Author: nxphuc
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
// Note: 

/**
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 *  
 * Example 1:
 * Input: grid = [
 *   ["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]
 * ]
 * Output: 1
 * Example 2:
 * Input: grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * Output: 3
 *  
 * Constraints:
 * - m == grid.length
 * - n == grid[i].length
 * - 1 <= m, n <= 300
 * - grid[i][j] is '0' or '1'.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    void bfs(vector<vector<char>>& grid, int sx, int sy) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({sx, sy});
        grid[sx][sy] = '0';
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                sx = x + dx[i];
                sy = y + dy[i];
                if (sx < 0 || sx == n || sy < 0 || sy == m || grid[sx][sy] == '0')
                    continue;
                grid[sx][sy] = '0';
                q.push({sx, sy});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    bfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};