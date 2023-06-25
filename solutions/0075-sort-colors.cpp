// Title: Sort Colors
// Source: https://leetcode.com/problems/sort-colors
// Difficulty: Medium
// Tags: Array, Two Pointers, Sorting
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * You must solve this problem without using the library's sort function.
 *  
 * Example 1:
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Example 2:
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 *  
 * Constraints:
 * - n == nums.length
 * - 1 <= n <= 300
 * - nums[i] is either 0, 1, or 2.
 *  
 * Follow up: Could you come up with a one-pass algorithm using only constant extra space?
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = nums.size() - 1;
        // all number index from white to blue is unclassified
        while (white <= blue) {
            if (nums[white] == 0) { // color red
                swap(nums[red], nums[white]);
                ++red;
                ++white;
            }
            else if (nums[white] == 1) // color white
                ++white;
            else {
                swap(nums[white], nums[blue]);
                --blue;
            }
        }
    }
};