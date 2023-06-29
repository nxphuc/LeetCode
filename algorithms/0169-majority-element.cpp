// Title: Majority Element
// Source: https://leetcode.com/problems/majority-element
// Difficulty: Easy
// Tags: Array, Hash Table, Divide and Conquer, Sorting, Counting
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 *  
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 *  
 * Constraints:
 * - n == nums.length
 * - 1 <= n <= 5 * 10^4
 * - -10^9 <= nums[i] <= 10^9
 *  
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == major) cnt++;
            else {
                if (--cnt < 0) {
                    cnt = 1;
                    major = nums[i];
                }
            }
        }
        return major;
    }
};