// Title: Largest Rectangle in Histogram
// Source: https://leetcode.com/problems/largest-rectangle-in-histogram
// Difficulty: Hard
// Tags: Array, Stack, Monotonic Stack
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
 *  
 * Example 1:
 * 
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10 units.
 * Example 2:
 * 
 * Input: heights = [2,4]
 * Output: 4
 *  
 * Constraints:
 * - 1 <= heights.length <= 10^5
 * - 0 <= heights[i] <= 10^4
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res = 0;
        for(int i = 0; i <= heights.size(); ++i){
            while(!st.empty() && heights[st.top()] > (i == heights.size() ? -1 : heights[i])) {
                int val = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                res = max(res, width * heights[val]);
            }
            st.push(i);
        }
        return res;
    }
};