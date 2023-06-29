// Title: Permutations II
// Source: https://leetcode.com/problems/permutations-ii
// Difficulty: Medium
// Tags: Array, Backtracking
// Author: nxphuc
// Time Complexity: O(N! * N)
// Space Complexity: O(1)
// Note:

/**
 * Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
 *  
 * Example 1:
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 *  [1,2,1],
 *  [2,1,1]]
 * Example 2:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *  
 * Constraints:
 * - 1 <= nums.length <= 8
 * - -10 <= nums[i] <= 10
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }
};