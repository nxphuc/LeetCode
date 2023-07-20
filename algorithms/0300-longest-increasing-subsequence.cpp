// Title: Longest Increasing Subsequence
// Source: https://leetcode.com/problems/longest-increasing-subsequence
// Difficulty: Medium
// Tags: Array, Binary Search, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// Note: 

/**
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.
 *  
 * Example 1:
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 * Example 2:
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * Example 3:
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 *  
 * Constraints:
 * - 1 <= nums.length <= 2500
 * - -10^4 <= nums[i] <= 10^4
 *  
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (int x : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }
        return lis.size();
    }
};