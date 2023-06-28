// Title: Distinct Subsequences
// Source: https://leetcode.com/problems/distinct-subsequences
// Difficulty: Hard
// Tags: String, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
// Note: 

/**
 * Given two strings s and t, return the number of distinct subsequences of s which equals t.
 * The test cases are generated so that the answer fits on a 32-bit signed integer.
 *  
 * Example 1:
 * Input: s = "rabbbit", t = "rabbit"
 * Output: 3
 * Explanation:
 * As shown below, there are 3 ways you can generate "rabbit" from s.
 * rabbbit
 * rabbbit
 * rabbbit
 * Example 2:
 * Input: s = "babgbag", t = "bag"
 * Output: 5
 * Explanation:
 * As shown below, there are 5 ways you can generate "bag" from s.
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 *  
 * Constraints:
 * - 1 <= s.length, t.length <= 1000
 * - s and t consist of English letters.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp(vector<vector<int>>& f, string& s, string& t, int n, int m) {
        if (m == 0) return 1;
        if (n < m) return 0;
        if (f[n][m] != -1) return f[n][m];

        if (s[n - 1] == t[m - 1])
            return f[n][m] = dp(f, s, t, n - 1, m - 1) + dp(f, s, t, n - 1, m);
        return f[n][m] = dp(f, s, t, n - 1, m);
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, -1));
        return dp(f, s, t, n, m);
    }
};