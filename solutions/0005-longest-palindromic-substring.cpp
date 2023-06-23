// Title: Longest Palindromic Substring
// Source: https://leetcode.com/problems/longest-palindromic-substring
// Difficulty: Medium
// Tags: String, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(n)
// Space Complexity: O(n)
// Topic: Manacher

/**
 * Given a string s, return the longest palindromic substring in s.
 *  
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * Example 2:
 * Input: s = "cbbd"
 * Output: "bb"
 *  
 * Constraints:
 * - 1 <= s.length <= 1000
 * - s consist of only digits and English letters.
 **/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> manacher(string s) {
        int n = s.length();
        vector<int> p(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = i > r ? 0 : min(p[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) ++k;
            p[i] = --k;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        return p;
    }
    
    string longestPalindrome(string s) {
        string t = "#";
        for (char ch :s)
            t += ch + string("#");
        auto p = manacher(t);
        int i = 0;
        for (int j = 1; j < t.length(); ++j)
            if (p[j] > p[i]) i = j;
        return s.substr((i - p[i]) / 2, p[i]);
    }
};