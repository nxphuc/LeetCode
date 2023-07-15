// Title: Maximum Average Subarray I
// Source: https://leetcode.com/problems/maximum-average-subarray-i
// Difficulty: Easy
// Tags: Array, Sliding Window
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * You are given an integer array nums consisting of n elements, and an integer k.
 * Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10^-5 will be accepted.
 *  
 * Example 1:
 * Input: nums = [1,12,-5,-6,50,3], k = 4
 * Output: 12.75000
 * Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
 * Example 2:
 * Input: nums = [5], k = 1
 * Output: 5.00000
 *  
 * Constraints:
 * - n == nums.length
 * - 1 <= k <= n <= 10^5
 * - -10^4 <= nums[i] <= 10^4
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        double sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (i >= k - 1) {
                maxAvg = max(maxAvg, sum / k);
                sum -= nums[i - k + 1];
            }
        }
        return maxAvg;
    }
};