// Title: 4Sum
// Source: https://leetcode.com/problems/4sum
// Difficulty: Medium
// Tags: Array, Two Pointers, Sorting
// Author: nxphuc
// Time Complexity: O(N^3)
// Space Complexity: O(1)
// Note: 

/**
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * - 0 <= a, b, c, d < n
 * - a, b, c, and d are distinct.
 * - nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order.
 *  
 * Example 1:
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * Example 2:
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 *  
 * Constraints:
 * - 1 <= nums.length <= 200
 * - -10^9 <= nums[i] <= 10^9
 * - -10^9 <= target <= 10^9
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSum(vector<int>& nums, long long target, int k, int start = 0) {
        vector<vector<int>> result;
        if (k == 2) {
            int i = start, j = nums.size() - 1;
            while (i < j) {
                if (target - nums[i] == nums[j]) {
                    result.push_back({nums[i], nums[j]});
                    ++i;
                    while (i < j && nums[i] == nums[i - 1]) ++i;
                }
                else if (target - nums[i] > nums[j]) ++i;
                else --j;
            }
            return result;
        }
        for (int i = start; i < nums.size() - 1; ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            auto temp = kSum(nums, target - nums[i], k - 1, i + 1);
            for(auto& tuple : temp) {
                tuple.push_back(nums[i]);
                result.push_back(tuple);
            }
        }
        return result;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 4);
    }
};