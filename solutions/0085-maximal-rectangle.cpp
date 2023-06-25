// Title: Maximal Rectangle
// Source: https://leetcode.com/problems/maximal-rectangle
// Difficulty: Hard
// Tags: Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
// Author: nxphuc
// Time Complexity: O(N * M)
// Space Complexity: O(M)
// Note: 

/**
 * Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 *  
 * Example 1:
 * 
 * Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 6
 * Explanation: The maximal rectangle is shown in the above picture.
 * Example 2:
 * Input: matrix = [["0"]]
 * Output: 0
 * Example 3:
 * Input: matrix = [["1"]]
 * Output: 1
 *  
 * Constraints:
 * - rows == matrix.length
 * - cols == matrix[i].length
 * - 1 <= row, cols <= 200
 * - matrix[i][j] is '0' or '1'.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res = 0;
        for(int i = 0; i < heights.size(); ++i){
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int val = st.top();
                st.pop();
                res = max(res, (st.empty() ? i : i - st.top() - 1) * heights[val]);
            }
            st.push(i);
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m + 1, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
};