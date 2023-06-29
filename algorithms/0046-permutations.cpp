// Title: Permutations
// Source: https://leetcode.com/problems/permutations
// Difficulty: Medium
// Tags: Array, Backtracking
// Author: nxphuc
// Time Complexity: O(N! * N)
// Space Complexity: O(1)
// Note: 

/**
 * Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 *  
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *  
 * Constraints:
 * - 1 <= nums.length <= 6
 * - -10 <= nums[i] <= 10
 * - All the integers of nums are unique.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }
};