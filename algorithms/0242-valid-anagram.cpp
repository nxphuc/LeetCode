// Title: Valid Anagram
// Source: https://leetcode.com/problems/valid-anagram
// Difficulty: Easy
// Tags: Hash Table, String, Sorting
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 *  
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *  
 * Constraints:
 * - 1 <= s.length, t.length <= 5 * 10^4
 * - s and t consist of lowercase English letters.
 *  
 * Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        for (char c : s)
            ++cnt[c - 'a'];
        for (char c : t)
            --cnt[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (cnt[i] != 0)
                return false;
        return true;
    }
};