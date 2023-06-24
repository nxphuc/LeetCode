// Title: N-Queens II
// Source: https://leetcode.com/problems/n-queens-ii
// Difficulty: Hard
// Tags: Backtracking
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 *  
 * Example 1:
 * 
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
 * Example 2:
 * Input: n = 1
 * Output: 1
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

    int backtrack(vector<string>& board, int n, int r = 0) {
        if (r == n)
            return 1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (isValid(board, n, r, i)) {
                board[r][i] = 'Q';
                res += backtrack(board, n, r + 1);
                board[r][i] = '.';
            }
        }
        return res;
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        return backtrack(board, n);
    }
};