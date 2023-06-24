// Title: Find First and Last Position of Element in Sorted Array
// Source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
// Difficulty: Medium
// Tags: Array, Binary Search
// Author: nxphuc
// Time Complexity: O(logN)
// Space Complexity: O(1)
// Note: 

/**
 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
 * If target is not found in the array, return [-1, -1].
 * You must write an algorithm with O(log n) runtime complexity.
 *  
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *  
 * Constraints:
 * - 0 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
 * - nums is a non-decreasing array.
 * - -10^9 <= target <= 10^9
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int p = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (p == nums.size() || nums[p] != target)
            return {-1, -1};
        return {p, int(lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin() - 1)};
    }
};