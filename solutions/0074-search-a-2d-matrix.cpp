// Title: Search a 2D Matrix
// Source: https://leetcode.com/problems/search-a-2d-matrix
// Difficulty: Medium
// Tags: Array, Binary Search, Matrix
// Author: nxphuc
// Time Complexity: O(log(M * N))
// Space Complexity: O(1)
// Note: 

/**
 * You are given an m x n integer matrix matrix with the following two properties:
 * - Each row is sorted in non-decreasing order.
 * - The first integer of each row is greater than the last integer of the previous row.
 * Given an integer target, return true if target is in matrix or false otherwise.
 * You must write a solution in O(log(m * n)) time complexity.
 *  
 * Example 1:
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * Example 2:
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 *  
 * Constraints:
 * - m == matrix.length
 * - n == matrix[i].length
 * - 1 <= m, n <= 100
 * - -10^4 <= matrix[i][j], target <= 10^4
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        int l = 0, r = nRow * nCol;
        while (l < r) {
            int m = (l + r) >> 1;
            if (matrix[m / nCol][m % nCol] == target)
                return true;
            if (matrix[m / nCol][m % nCol] > target)
                r = m;
            else
                l = m + 1;
        }
        return false;
    }
};