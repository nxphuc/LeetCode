// Title: Word Pattern
// Source: https://leetcode.com/problems/word-pattern
// Difficulty: Easy
// Tags: Hash Table, String
// Author: nxphuc
// Time Complexity: O(N + M)
// Space Complexity: O(N)
// Note: 

/**
 * Given a pattern and a string s, find if s follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
 *  
 * Example 1:
 * Input: pattern = "abba", s = "dog cat cat dog"
 * Output: true
 * Example 2:
 * Input: pattern = "abba", s = "dog cat cat fish"
 * Output: false
 * Example 3:
 * Input: pattern = "aaaa", s = "dog cat cat dog"
 * Output: false
 *  
 * Constraints:
 * - 1 <= pattern.length <= 300
 * - pattern contains only lower-case English letters.
 * - 1 <= s.length <= 3000
 * - s contains only lowercase English letters and spaces ' '.
 * - s does not contain any leading or trailing spaces.
 * - All the words in s are separated by a single space.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> pToS;
        unordered_map<string, char> sToP;
        int start = 0;
        int idx = 0;
        s += " ";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                if (idx == pattern.length()) return false;
                string t = s.substr(start, i - start);
                if (pToS.find(pattern[idx]) != pToS.end() && pToS[pattern[idx]] != t)
                    return false;
                if (sToP.find(t) != sToP.end() && sToP[t] != pattern[idx])
                    return false;
                sToP[t] = pattern[idx];
                pToS[pattern[idx++]] = t;
                start = i + 1;
            }
        }
        return idx == pattern.length();
    }
};