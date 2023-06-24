// Title: Valid Number
// Source: https://leetcode.com/problems/valid-number
// Difficulty: Hard
// Tags: String
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: 
// Note: 

/**
 * A valid number can be split up into these components (in order):
 * - A decimal number or an integer.
 * - (Optional) An 'e' or 'E', followed by an integer.
 * A decimal number can be split up into these components (in order):
 * - (Optional) A sign character (either '+' or '-').
 * - One of the following formats:
 * 	
 * One or more digits, followed by a dot '.'.
 * One or more digits, followed by a dot '.', followed by one or more digits.
 * A dot '.', followed by one or more digits.
 * 
 * An integer can be split up into these components (in order):
 * - (Optional) A sign character (either '+' or '-').
 * - One or more digits.
 * For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
 * Given a string s, return true if s is a valid number.
 *  
 * Example 1:
 * Input: s = "0"
 * Output: true
 * Example 2:
 * Input: s = "e"
 * Output: false
 * Example 3:
 * Input: s = "."
 * Output: false
 *  
 * Constraints:
 * - 1 <= s.length <= 20
 * - s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInteger(string s, bool allowSign = true, bool allowEmpty = false) {
        if (s.length() == 0) return false;
        int i = 0;
        int cnt = 0;
        if (s[0] == '-' || s[0] == '+') {
            if (!allowSign) return false;
            ++i;
        }
        while (i < s.length() && isdigit(s[i])) ++i, ++cnt;
        if (i < s.length()) return false;
        return cnt > 0 || allowEmpty;
    }

    bool isDecimal(string s) {
        int pos = s.find('.');
        if (pos == string::npos)
            return isInteger(s);
        if (pos == 0)
            return isInteger(s.substr(1), false, false);
        if (pos == s.length() - 1)
            return isInteger(s.substr(0, pos));
        return isInteger(s.substr(0, pos), true, true) && isInteger(s.substr(pos + 1), false);
    }

    bool isNumber(string s) {
        int pos = 0;
        while (pos < s.length() && s[pos] != 'e' && s[pos] != 'E') ++pos;
        if (!isDecimal(s.substr(0, pos)))
            return false;
        if (pos < s.length())
            return isInteger(s.substr(pos + 1)) > 0;
        return true;
    }
};