// Title: Ransom Note
// Source: https://leetcode.com/problems/ransom-note
// Difficulty: Easy
// Tags: Hash Table, String, Counting
// Author: nxphuc
// Time Complexity: O(N + M)
// Space Complexity: O(1)
// Note: 

/**
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
 * Each letter in magazine can only be used once in ransomNote.
 *  
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *  
 * Constraints:
 * - 1 <= ransomNote.length, magazine.length <= 10^5
 * - ransomNote and magazine consist of lowercase English letters.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int diff[26] = {0};
        for (char c : ransomNote)
            --diff[c - 'a'];
        for (char c : magazine)
            ++diff[c - 'a'];
        for (int i = 0; i < 26; ++i)
            if (diff[i] < 0)
                return false;
        return true;
    }
};