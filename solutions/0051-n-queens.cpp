// Title: N-Queens
// Source: https://leetcode.com/problems/n-queens
// Difficulty: Hard
// Tags: Array, Backtracking
// Author: nxphuc
// Time Complexity: O(N! * N)
// Space Complexity: O(N)
// Note: 

/**
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 *  
 * Example 1:
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
 * Example 2:
 * Input: n = 1
 * Output: [["Q"]]
 *  
 * Constraints:
 * - 1 <= n <= 9
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<string>& board, int n, int r, int c) {
        for (int i = 0; i < n; i++)
            if (board[i][c] == 'Q') return false;
        for (int i = r, j = c; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q') return false;
        for (int i = r, j = c; i < n && j < n; ++i, ++j)
            if (board[i][j] == 'Q') return false;
        for (int i = r, j = c; i >= 0 && j < n; --i, ++j)
            if (board[i][j] == 'Q') return false;
        for (int i = r, j = c; i < n && j >= 0; ++i, --j)
            if (board[i][j] == 'Q') return false;
        return true;
    }

    void backtrack(vector<vector<string>>& result, vector<string>& board, int n, int r = 0) {
        if (r == n) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(board, n, r, i)) {
                board[r][i] = 'Q';
                backtrack(result, board, n, r + 1);
                board[r][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        backtrack(result, board, n);
        return result;
    }
};