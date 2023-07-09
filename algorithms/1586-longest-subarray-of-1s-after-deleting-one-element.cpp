// Title: Longest Subarray of 1's After Deleting One Element
// Source: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element
// Difficulty: Medium
// Tags: Array, Dynamic Programming, Sliding Window
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given a binary array nums, you should delete one element from it.
 * Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
 *  
 * Example 1:
 * Input: nums = [1,1,0,1]
 * Output: 3
 * Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
 * Example 2:
 * Input: nums = [0,1,1,1,0,1,1,0,1]
 * Output: 5
 * Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
 * Example 3:
 * Input: nums = [1,1,1]
 * Output: 2
 * Explanation: You must delete one element.
 *  
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - nums[i] is either 0 or 1.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, remain = 1, res = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (!nums[j])
                remain--;
            while (remain < 0)
                remain += nums[i++] == 0;
            res = max(res, j - i);
        }
        return res;
    }
};