// Title: Palindrome Partitioning
// Source: https://leetcode.com/problems/palindrome-partitioning
// Difficulty: Medium
// Tags: String, Dynamic Programming, Backtracking
// Author: nxphuc
// Time Complexity: (N * 2^N)
// Space Complexity: O(N^2)
// Note: 

/**
 * Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
 *  
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 *  
 * Constraints:
 * - 1 <= s.length <= 16
 * - s contains only lowercase English letters.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<string>>& res, vector<string>& partition, vector<vector<bool>>& isPalin, string& s, int i) {
        if (i == s.length()) {
            res.push_back(partition);
            return;
        }
        for (int j = i; j < s.length(); j++)
            if (isPalin[i][j]) {
                partition.push_back(s.substr(i, j - i + 1));
                backtrack(res, partition, isPalin, s, j + 1);
                partition.pop_back();
            }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
            isPalin[i][i] = true;
        
        // isPalin[i][j] = isPalin[i + 1][j - 1]
        for (int i = n - 1; i >= 0; --i)
            for (int j = i + 1; j < n; ++j)
                isPalin[i][j] = s[i] == s[j] && (i + 1 > j - 1 || isPalin[i + 1][j - 1]);
        
        vector<vector<string>> res;
        vector<string> partition;
        backtrack(res, partition, isPalin, s, 0);
        return res;
    }
};