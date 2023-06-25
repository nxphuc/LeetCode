// Title: Word Search
// Source: https://leetcode.com/problems/word-search
// Difficulty: Medium
// Tags: Array, Backtracking, Matrix
// Author: nxphuc
// Time Complexity: O(4^|word|)
// Space Complexity: 
// Note: 

/**
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *  
 * Example 1:
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 * Output: true
 * Example 2:
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 * Output: true
 * Example 3:
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
 * Output: false
 *  
 * Constraints:
 * - m == board.length
 * - n = board[i].length
 * - 1 <= m, n <= 6
 * - 1 <= word.length <= 15
 * - board and word consists of only lowercase and uppercase English letters.
 *  
 * Follow up: Could you use search pruning to make your solution faster with a larger board?
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    bool found (vector<vector<char>>& board, string word, int n, int m, int x, int y, int i = 1) {
        if (i == word.length()) return true;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (0 <= nx && nx < n && 0 <= ny  && ny < m && board[nx][ny] == word[i]) {
                board[nx][ny] = '.';
                if (found(board, word, n, m, nx, ny, i + 1))
                    return true;
                board[nx][ny] = word[i];
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == word[0]) {
                    board[i][j] = '.';
                    if (found(board, word, n, m, i, j))
                        return true;
                    board[i][j] = word[0];
                }
        return false;
    }
};