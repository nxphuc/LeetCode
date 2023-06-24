// Title: 3Sum Closest
// Source: https://leetcode.com/problems/3sum-closest
// Difficulty: Medium
// Tags: Array, Two Pointers, Sorting
// Author: nxphuc
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Note: 

/**
 * Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *  
 * Example 1:
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * Example 2:
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 * Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 *  
 * Constraints:
 * - 3 <= nums.length <= 500
 * - -1000 <= nums[i] <= 1000
 * - -10^4 <= target <= 10^4
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int j, k, i = 0; i < nums.size(); ++i) {
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                int current = nums[i] + nums[j] + nums[k];
                if (abs(target - closest) > abs(target - current))
                    closest = current;
                if (current < target) ++j;
                else --k;
            }
        }
        return closest;
    }
};