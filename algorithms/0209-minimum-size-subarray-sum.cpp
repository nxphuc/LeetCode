// Title: Minimum Size Subarray Sum
// Source: https://leetcode.com/problems/minimum-size-subarray-sum
// Difficulty: Medium
// Tags: Array, Binary Search, Sliding Window, Prefix Sum
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 *  
 * Example 1:
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem constraint.
 * Example 2:
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 * Example 3:
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *  
 * Constraints:
 * - 1 <= target <= 10^9
 * - 1 <= nums.length <= 10^5
 * - 1 <= nums[i] <= 10^4
 *  
 * Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int cur = 0;
        int res = INT_MAX;
        while (r < nums.size()) {
            cur += nums[r++];
            while (cur - nums[l] >= target)
                cur -= nums[l++];
            if (cur >= target)
                res = min(res, r - l);
        }
        return res == INT_MAX ? 0 : res;
    }
};