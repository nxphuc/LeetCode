// Title: Find Peak Element
// Source: https://leetcode.com/problems/find-peak-element
// Difficulty: Medium
// Tags: Array, Binary Search
// Author: nxphuc
// Time Complexity: O(logN)
// Space Complexity: O(1)
// Note: 

/**
 * A peak element is an element that is strictly greater than its neighbors.
 * Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
 * You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
 * You must write an algorithm that runs in O(log n) time.
 *  
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index number 2.
 * Example 2:
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 5
 * Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 *  
 * Constraints:
 * - 1 <= nums.length <= 1000
 * - -2^31 <= nums[i] <= 2^31 - 1
 * - nums[i] != nums[i + 1] for all valid i.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int l = 1, r = n - 2;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m - 1] < nums[m] && nums[m] > nums[m + 1]) {
                return m;
            }
            if (nums[m] < nums[m + 1])
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
};