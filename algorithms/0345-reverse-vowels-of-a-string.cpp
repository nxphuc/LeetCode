// Title: Reverse Vowels of a String
// Source: https://leetcode.com/problems/reverse-vowels-of-a-string
// Difficulty: Easy
// Tags: Two Pointers, String
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given a string s, reverse only all the vowels in the string and return it.
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
 *  
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 *  
 * Constraints:
 * - 1 <= s.length <= 3 * 10^5
 * - s consist of printable ASCII characters.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiou";
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            while (i < j && vowels.find(tolower(s[i])) == -1) ++i;
            while (i < j && vowels.find(tolower(s[j])) == -1) --j;
            if (i < j) swap(s[i], s[j]);
        }
        return s;
    }
};