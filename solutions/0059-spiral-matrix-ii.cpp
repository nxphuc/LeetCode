// Title: Spiral Matrix II
// Source: https://leetcode.com/problems/spiral-matrix-ii
// Difficulty: Medium
// Tags: Array, Matrix, Simulation
// Author: nxphuc
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Note: 

/**
 * Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.
 *  
 * Example 1:
 * 
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 * Example 2:
 * Input: n = 1
 * Output: [[1]]
 *  
 * Constraints:
 * - 1 <= n <= 20
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int steps[2] = {n, n - 1};
        int x = 0, y = -1;
        int d = 0;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int cnt = 0;
        while (cnt < n * n) {
            for (int i = 0; i < steps[d & 1]; ++i) {
                x += dx[d];
                y += dy[d];
                res[x][y] = ++cnt;
            }
            --steps[d & 1];
            d = (d + 1) & 3;
        }
        return res;
    }
};