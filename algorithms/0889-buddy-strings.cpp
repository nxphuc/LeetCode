// Title: Buddy Strings
// Source: https://leetcode.com/problems/buddy-strings
// Difficulty: Easy
// Tags: Hash Table, String
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
 * Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
 * - For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 *  
 * Example 1:
 * Input: s = "ab", goal = "ba"
 * Output: true
 * Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
 * Example 2:
 * Input: s = "ab", goal = "ab"
 * Output: false
 * Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
 * Example 3:
 * Input: s = "aa", goal = "aa"
 * Output: true
 * Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
 *  
 * Constraints:
 * - 1 <= s.length, goal.length <= 2 * 10^4
 * - s and goal consist of lowercase letters.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length() || s.length() < 2) return false;
        if (s == goal) {
            vector<int> cnt(26);
            for (char c : s)
                if (++cnt[c - 'a'] > 1)
                    return true;
            return false;
        }
        int firstDiff = -1, secondDiff = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == goal[i]) continue;
            if (firstDiff == -1)
                firstDiff = i;
            else if (secondDiff == -1)
                secondDiff = i;
            else
                return false;
        }
        return secondDiff != -1 && s[firstDiff] == goal[secondDiff] && s[secondDiff] == goal[firstDiff];
    }
};