// Title: Minimum Window Substring
// Source: https://leetcode.com/problems/minimum-window-substring
// Difficulty: Hard
// Tags: Hash Table, String, Sliding Window
// Author: nxphuc
// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Note: 

/**
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
 * The testcases will be generated such that the answer is unique.
 *  
 * Example 1:
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
 * Example 2:
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 * Example 3:
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 *  
 * Constraints:
 * - m == s.length
 * - n == t.length
 * - 1 <= m, n <= 10^5
 * - s and t consist of uppercase and lowercase English letters.
 *  
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> diff;
        for (char c : t) ++diff[c];
        int numDiff = diff.size();
        int l = 0, r = 0;
        string res = "";
        while (r < s.length()) {
            --diff[s[r]];
            if (diff[s[r]] == 0)
                --numDiff;
            if (numDiff == 0) {
                while (diff[s[l]] < 0) {
                    ++diff[s[l]];
                    ++l;
                }
                if (res.length() == 0 || res.length() > (r - l + 1))
                    res = s.substr(l, r - l + 1);
                ++numDiff;
                ++diff[s[l++]];
            }
            ++r;
        }
        return res;
    }
};