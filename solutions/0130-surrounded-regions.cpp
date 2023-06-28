// Title: Surrounded Regions
// Source: https://leetcode.com/problems/surrounded-regions
// Difficulty: Medium
// Tags: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
// Author: nxphuc
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
// Note: 

/**
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *  
 * Example 1:
 * 
 * Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Notice that an 'O' should not be flipped if:
 * - It is on the border, or
 * - It is adjacent to an 'O' that should not be flipped.
 * The bottom 'O' is on the border, so it is not flipped.
 * The other three 'O' form a surrounded region, so they are flipped.
 * Example 2:
 * Input: board = [["X"]]
 * Output: [["X"]]
 *  
 * Constraints:
 * - m == board.length
 * - n == board[i].length
 * - 1 <= m, n <= 200
 * - board[i][j] is 'X' or 'O'.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    vector<pair<int, int>> cells;
                    queue<pair<int, int>> q;
                    bool isOnBorder = false;

                    q.push({i, j});
                    cells.push_back({i, j});
                    vis[i][j] = true;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                            isOnBorder = true;
                        for (int d = 0; d < 4; ++d) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || board[nx][ny] == 'X') continue;
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                            cells.push_back({nx, ny});
                        }
                    }

                    if (!isOnBorder) {
                        for (auto [x, y] : cells)
                            board[x][y] = 'X';
                    }
                }
            }
        }
    }
};