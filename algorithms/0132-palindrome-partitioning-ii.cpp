// Title: Palindrome Partitioning II
// Source: https://leetcode.com/problems/palindrome-partitioning-ii
// Difficulty: Hard
// Tags: String, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Note: 

/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *  
 * Example 1:
 * Input: s = "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
 * Example 2:
 * Input: s = "a"
 * Output: 0
 * Example 3:
 * Input: s = "ab"
 * Output: 1
 *  
 * Constraints:
 * - 1 <= s.length <= 2000
 * - s consists of lowercase English letters only.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
            isPalin[i][i] = true;

        // isPalin[i][j] = isPalin[i + 1][j - 1]
        for (int i = n - 1; i >= 0; --i)
            for (int j = i + 1; j < n; ++j)
                isPalin[i][j] = s[i] == s[j] && (i + 1 > j - 1 || isPalin[i + 1][j - 1]);

        vector<int> f(n + 1, n + 1);
        f[0] = 0;
        for (int r = 1; r <= n; ++r) {
            for (int l = r; l > 0; --l)
                if (isPalin[l - 1][r - 1])
                    f[r] = min(f[r], f[l - 1] + 1);
        }
        return f[n] - 1;
    }
};