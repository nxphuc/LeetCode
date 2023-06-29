// Title: Maximum Subarray
// Source: https://leetcode.com/problems/maximum-subarray
// Difficulty: Medium
// Tags: Array, Divide and Conquer, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 *  
 * Example 1:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 * Example 2:
 * Input: nums = [1]
 * Output: 1
 * Explanation: The subarray [1] has the largest sum 1.
 * Example 3:
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 *  
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 *  
 * Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int res = nums[0];
        for (auto& x : nums) {
            cur += x;
            res = max(res, cur);
            if (cur < 0) cur = 0;
        }
        return res;
    }
};