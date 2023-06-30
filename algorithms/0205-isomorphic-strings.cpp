// Title: Isomorphic Strings
// Source: https://leetcode.com/problems/isomorphic-strings
// Difficulty: Easy
// Tags: Hash Table, String
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
 *  
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *  
 * Constraints:
 * - 1 <= s.length <= 5 * 10^4
 * - t.length == s.length
 * - s and t consist of any valid ascii character.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPair(string s, string t) {
        unordered_map<char, char> paired;
        for (int i = 0; i < s.length(); ++i) {
            auto it = paired.find(s[i]);
            if (it != paired.end() && it->second != t[i])
                return false;
            paired[s[i]] = t[i];
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return canPair(s, t) && canPair(t, s);
    }
};