// Title: Sudoku Solver
// Source: https://leetcode.com/problems/sudoku-solver
// Difficulty: Hard
// Tags: Array, Hash Table, Backtracking, Matrix
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * A sudoku solution must satisfy all of the following rules:
 * - Each of the digits 1-9 must occur exactly once in each row.
 * - Each of the digits 1-9 must occur exactly once in each column.
 * - Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 * The '.' character indicates empty cells.
 *  
 * Example 1:
 * 
 * Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is shown below:
 * 
 *  
 * Constraints:
 * - board.length == 9
 * - board[i].length == 9
 * - board[i][j] is a digit or '.'.
 * - It is guaranteed that the input board has only one solution.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y, char c) {
        for (int i = 0; i < board.size(); ++i) {
            if (board[x][i] == c || board[i][y] == c)
                return false;
        }
        int blockX = x / 3 * 3;
        int blockY = y / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[blockX + i][blockY + j] == c)
                    return false;
            }
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] == '.') {
                    for (int x = '1'; x <= '9'; ++x) {
                        if (isValid(board, i, j, x)) {
                            board[i][j] = x;
                            if (backtrack(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        backtrack(board);
    }
};