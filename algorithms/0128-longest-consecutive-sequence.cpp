// Title: Longest Consecutive Sequence
// Source: https://leetcode.com/problems/longest-consecutive-sequence
// Difficulty: Medium
// Tags: Array, Hash Table, Union Find
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 *  
 * Example 1:
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 * Example 2:
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *  
 * Constraints:
 * - 0 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;
        for (int x : nums) {
            if (numSet.find(x - 1) != numSet.end())
                continue;
            int y = x + 1;
            while (numSet.find(y) != numSet.end())
                ++y;
            res = max(res, y - x);
        }
        return res;
    }
};