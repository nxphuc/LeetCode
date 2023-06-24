// Title: Find the Index of the First Occurrence in a String
// Source: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
// Difficulty: Easy
// Tags: Two Pointers, String, String Matching
// Author: nxphuc
// Time Complexity: O(N + M)
// Space Complexity: O(M)
// Note: 

/**
 * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *  
 * Example 1:
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6.
 * The first occurrence is at index 0, so we return 0.
 * Example 2:
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" did not occur in "leetcode", so we return -1.
 *  
 * Constraints:
 * - 1 <= haystack.length, needle.length <= 10^4
 * - haystack and needle consist of only lowercase English characters.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kmpPreprocess(string& p) {
        int m = p.length();
        vector<int> pref(m, 0);

        int j = 0;
        for (int i = 1; i < m; i++) {
            while (j > 0 && p[j] != p[i])
                j = pref[j - 1];
            if (p[i] == p[j])
                j++;
            pref[i] = j;
        }

        return pref;
    }

    int strStr(string haystack, string needle) {
        auto pref = kmpPreprocess(needle);
        int n = haystack.length(), m = needle.length();

        int i, j = 0;
        for (i = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j])
                j = pref[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == m)
                return i - m + 1;
        }
        return -1;
    }
};