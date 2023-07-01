// Title: Shortest Palindrome
// Source: https://leetcode.com/problems/shortest-palindrome
// Difficulty: Hard
// Tags: String, Rolling Hash, String Matching, Hash Function
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * You are given a string s. You can convert s to a palindrome by adding characters in front of it.
 * Return the shortest palindrome you can find by performing this transformation.
 *  
 * Example 1:
 * Input: s = "aacecaaa"
 * Output: "aaacecaaa"
 * Example 2:
 * Input: s = "abcd"
 * Output: "dcbabcd"
 *  
 * Constraints:
 * - 0 <= s.length <= 5 * 10^4
 * - s consists of lowercase English letters only.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        t = s + "#" + t;
        vector<int> pref(t.length());
        for (int j = 0, i = 1; i < t.length(); ++i) {
            while (j > 0 && t[i] != t[j])
                j = pref[j - 1];
            if (t[i] == t[j])
                pref[i] = ++j;
        }
        return t.substr(s.length() + 1, s.length() - pref.back()) + s;
    }
};