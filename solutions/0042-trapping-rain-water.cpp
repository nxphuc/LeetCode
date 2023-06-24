// Title: Trapping Rain Water
// Source: https://leetcode.com/problems/trapping-rain-water
// Difficulty: Hard
// Tags: Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 *  
 * Example 1:
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *  
 * Constraints:
 * - n == height.length
 * - 1 <= n <= 2 * 10^4
 * - 0 <= height[i] <= 10^5
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        deque<int> dq;
        int res = 0;
        int maxLeft = 0, maxRight = 0;
        for (int i = 0, j = height.size() - 1; i <= j; ) {
            if (height[i] <= height[j]) {
                if (height[i] > maxLeft)
                    maxLeft = height[i];
                else
                    res += maxLeft - height[i];
                ++i;
            }
            else {
                if (height[j] > maxRight)
                    maxRight = height[j];
                else
                    res += maxRight - height[j];
                --j;
            }
        }
        return res;
    }
};