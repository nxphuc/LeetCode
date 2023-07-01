// Title: Longest Substring Without Repeating Characters
// Source: https://leetcode.com/problems/longest-substring-without-repeating-characters
// Difficulty: Medium
// Tags: Hash Table, String, Sliding Window
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Topic:

/**
 * Given a string s, find the length of the longest substring without repeating characters.
 *  
 * Example 1:
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * Example 2:
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * Example 3:
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *  
 * Constraints:
 * - 0 <= s.length <= 5 * 10^4
 * - s consists of English letters, digits, symbols and spaces.
 **/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool mark[128] = {false};
        int res = 0;
        for (int i = 0, j = 0; i < s.length(); ++i) {
            while (mark[s[i]]) {
                mark[s[j++]] = false;
            }
            mark[s[i]] = true;
            res = max(res, i - j + 1);
        }
        return res;
    }
};