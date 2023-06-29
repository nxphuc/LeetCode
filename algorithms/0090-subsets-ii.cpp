// Title: Subsets II
// Source: https://leetcode.com/problems/subsets-ii
// Difficulty: Medium
// Tags: Array, Backtracking, Bit Manipulation
// Author: nxphuc
// Time Complexity: O(2^N)
// Space Complexity: O(1)
// Note: 

/**
 * Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 *  
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 *  
 * Constraints:
 * - 1 <= nums.length <= 10
 * - -10 <= nums[i] <= 10
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        sort(nums.begin(), nums.end());
        for (int j = 0, i = 0; i < nums.size(); i = j) {
            while (j < nums.size() && nums[i] == nums[j]) ++j;
            int len = result.size();
            for (int k = 0; k < len; k++) {
                for (int cnt = 1; cnt <= j - i; ++cnt) {
                    result.push_back(result[k]);
                    result.back().insert(result.back().end(), cnt, nums[i]);
                }
            }
        }
        return result;
    }
};