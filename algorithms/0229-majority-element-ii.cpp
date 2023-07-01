// Title: Majority Element II
// Source: https://leetcode.com/problems/majority-element-ii
// Difficulty: Medium
// Tags: Array, Hash Table, Sorting, Counting
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 *  
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: [3]
 * Example 2:
 * Input: nums = [1]
 * Output: [1]
 * Example 3:
 * Input: nums = [1,2]
 * Output: [1,2]
 *  
 * Constraints:
 * - 1 <= nums.length <= 5 * 10^4
 * - -10^9 <= nums[i] <= 10^9
 *  
 * Follow up: Could you solve the problem in linear time and in O(1) space?
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, cnt1 = 0;
        int candidate2 = 1, cnt2 = 0;
        for (int x : nums) {
            if (x == candidate1)
                ++cnt1;
            else if (x == candidate2)
                ++cnt2;
            else if (!cnt1) {
                candidate1 = x;
                cnt1 = 1;
            }
            else if (!cnt2) {
                candidate2 = x;
                cnt2 = 1;
            }
            else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = cnt2 = 0;
        for (int x : nums) {
            if (x == candidate1) ++cnt1;
            else if (x == candidate2) ++cnt2;
        }
        vector<int> res;
        if (cnt1 > nums.size() / 3)
            res.push_back(candidate1);
        if (cnt2 > nums.size() / 3)
            res.push_back(candidate2);
        return res;
    }
};