// Title: Maximum Number of Vowels in a Substring of Given Length
// Source: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
// Difficulty: Medium
// Tags: String, Sliding Window
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
 * Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
 *  
 * Example 1:
 * Input: s = "abciiidef", k = 3
 * Output: 3
 * Explanation: The substring "iii" contains 3 vowel letters.
 * Example 2:
 * Input: s = "aeiou", k = 2
 * Output: 2
 * Explanation: Any substring of length 2 contains 2 vowels.
 * Example 3:
 * Input: s = "leetcode", k = 3
 * Output: 2
 * Explanation: "lee", "eet" and "ode" contain 2 vowels.
 *  
 * Constraints:
 * - 1 <= s.length <= 10^5
 * - s consists of lowercase English letters.
 * - 1 <= k <= s.length
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        string vowels = "aeiou";
        int countVowels = 0;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            countVowels += vowels.find(s[i]) != -1;
            if (i >= k - 1) {
                result = max(result, countVowels);
                countVowels -= vowels.find(s[i - k + 1]) != -1;
            }
        }
        return result;
    }
};