// Title: Substring With Largest Variance
// Source: https://leetcode.com/problems/substring-with-largest-variance
// Difficulty: Hard
// Tags: Array, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(N * 26^2)
// Space Complexity: O(1)
// Note: 

/**
 * The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.
 * Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.
 * A substring is a contiguous sequence of characters within a string.
 *  
 * Example 1:
 * Input: s = "aababbb"
 * Output: 3
 * Explanation:
 * All possible variances along with their respective substrings are listed below:
 * - Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
 * - Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
 * - Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
 * - Variance 3 for substring "babbb".
 * Since the largest possible variance is 3, we return it.
 * Example 2:
 * Input: s = "abcde"
 * Output: 0
 * Explanation:
 * No letter occurs more than once in s, so the variance of every substring is 0.
 *  
 * Constraints:
 * - 1 <= s.length <= 10^4
 * - s consists of lowercase English letters.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int freq[26] = {0};
        for (char c : s)
            ++freq[c - 'a'];
        int res = 0;
        for (int a = 0; a < 26; ++a) {
            if (!freq[a]) continue;
            for (int b = 0; b < 26; ++b) {
                if (!freq[b] || a == b) continue;
                int freqA = 0, freqB = 0;
                int remainB = freq[b];
                for (char c : s) {
                    if (c - 'a' == a)
                        ++freqA;
                    if (c - 'a' == b) {
                        ++freqB;
                        --remainB;
                    }
                    if (freqB)
                        res = max(res, freqA - freqB);
                    if (freqA < freqB && remainB > 0) {
                        freqA = freqB = 0;
                    }
                }
            }
        }
        return res;
    }
};