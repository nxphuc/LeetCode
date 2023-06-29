// Title: Single Number II
// Source: https://leetcode.com/problems/single-number-ii
// Difficulty: Medium
// Tags: Array, Bit Manipulation
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 *  
 * Example 1:
 * Input: nums = [2,2,3,2]
 * Output: 3
 * Example 2:
 * Input: nums = [0,1,0,1,0,1,99]
 * Output: 99
 *  
 * Constraints:
 * - 1 <= nums.length <= 3 * 10^4
 * - -2^31 <= nums[i] <= 2^31 - 1
 * - Each element in nums appears exactly three times except for one element which appears once.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (int num : nums) {
            once = (once ^ num) & (~twice);
            twice = (twice ^ num) & (~once);
        }
        return once;
    }
};