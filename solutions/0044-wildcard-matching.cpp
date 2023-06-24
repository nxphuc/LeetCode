// Title: Wildcard Matching
// Source: https://leetcode.com/problems/wildcard-matching
// Difficulty: Hard
// Tags: String, Dynamic Programming, Greedy, Recursion
// Author: nxphuc
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
// Note: 

/**
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
 * - '?' Matches any single character.
 * - '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 *  
 * Example 1:
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * Example 2:
 * Input: s = "aa", p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * Example 3:
 * Input: s = "cb", p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 *  
 * Constraints:
 * - 0 <= s.length, p.length <= 2000
 * - s contains only lowercase English letters.
 * - p contains only lowercase English letters, '?' or '*'.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < n && p[i] == '*'; ++i)
            dp[i + 1][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[i - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else
                    dp[i][j] = (p[i - 1] == s[j - 1] || p[i - 1] == '?') && dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};