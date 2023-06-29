// Title: Spiral Matrix
// Source: https://leetcode.com/problems/spiral-matrix
// Difficulty: Medium
// Tags: Array, Matrix, Simulation
// Author: nxphuc
// Time Complexity: O(M * N)
// Space Complexity: O(1)
// Note: 

/**
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *  
 * Example 1:
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * Example 2:
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *  
 * Constraints:
 * - m == matrix.length
 * - n == matrix[i].length
 * - 1 <= m, n <= 10
 * - -100 <= matrix[i][j] <= 100
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int steps[2] = {n, m - 1};
        int x = 0, y = -1;
        int d = 0;
        vector<int> res;
        while (res.size() < n * m) {
            for (int i = 0; i < steps[d & 1]; ++i) {
                x += dx[d];
                y += dy[d];
                res.push_back(matrix[x][y]);
            }
            --steps[d & 1];
            d = (d + 1) & 3;
        }
        return res;
    }
};