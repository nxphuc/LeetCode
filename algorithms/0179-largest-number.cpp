// Title: Largest Number
// Source: https://leetcode.com/problems/largest-number
// Difficulty: Medium
// Tags: Array, String, Greedy, Sorting
// Author: nxphuc
// Time Complexity: O(NLogN)
// Space Complexity: O(1)
// Note: 

/**
 * Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
 * Since the result may be very large, so you need to return a string instead of an integer.
 *  
 * Example 1:
 * Input: nums = [10,2]
 * Output: "210"
 * Example 2:
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 *  
 * Constraints:
 * - 1 <= nums.length <= 100
 * - 0 <= nums[i] <= 10^9
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string strA = to_string(a);
            string strB = to_string(b);
            return strA + strB > strB + strA;
        });
        string res = "";
        for (int x : nums)
            res += to_string(x);
        int i = 0;
        while (i < res.length() - 1 && res[i] == '0')
            ++i;
        return res.substr(i);
    }
};