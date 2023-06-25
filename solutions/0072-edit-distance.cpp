// Title: Edit Distance
// Source: https://leetcode.com/problems/edit-distance
// Difficulty: Medium
// Tags: String, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)
// Note: 

/**
 * Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
 * You have the following three operations permitted on a word:
 * - Insert a character
 * - Delete a character
 * - Replace a character
 *  
 * Example 1:
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * Example 2:
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 *  
 * Constraints:
 * - 0 <= word1.length, word2.length <= 500
 * - word1 and word2 consist of lowercase English letters.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
        for (int i = 0; i <= n; ++i)
            f[i][0] = i;
        for (int i = 0; i <= m; ++i)
            f[0][i] = i;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = min({f[i - 1][j - 1], f[i][j - 1], f[i - 1][j]}) + 1;
            }
        }
        return f[n][m];
    }
};