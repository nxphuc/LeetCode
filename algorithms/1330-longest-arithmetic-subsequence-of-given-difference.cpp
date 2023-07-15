// Title: Longest Arithmetic Subsequence of Given Difference
// Source: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference
// Difficulty: Medium
// Tags: Array, Hash Table, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
 * A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.
 *  
 * Example 1:
 * Input: arr = [1,2,3,4], difference = 1
 * Output: 4
 * Explanation: The longest arithmetic subsequence is [1,2,3,4].
 * Example 2:
 * Input: arr = [1,3,5,7], difference = 1
 * Output: 1
 * Explanation: The longest arithmetic subsequence is any single element.
 * Example 3:
 * Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
 * Output: 4
 * Explanation: The longest arithmetic subsequence is [7,5,3,1].
 *  
 * Constraints:
 * - 1 <= arr.length <= 10^5
 * - -10^4 <= arr[i], difference <= 10^4
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int res = 0;
        for (int x : arr) {
            if (dp.find(x - difference) != dp.end())
                dp[x] = max(dp[x], dp[x - difference] + 1);
            else
                dp[x] = 1;
            res = max(res, dp[x]);
        }
        return res;
    }
};