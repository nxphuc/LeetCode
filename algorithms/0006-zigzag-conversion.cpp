// Title: Zigzag Conversion
// Source: https://leetcode.com/problems/zigzag-conversion
// Difficulty: Medium
// Tags: String
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Topic:

/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 *  
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * Example 3:
 * Input: s = "A", numRows = 1
 * Output: "A"
 *  
 * Constraints:
 * - 1 <= s.length <= 1000
 * - s consists of English letters (lower-case and upper-case), ',' and '.'.
 * - 1 <= numRows <= 1000
 **/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows);
        for (int d = 1, r = 0, i = 0; i < s.length(); ++i) {
            rows[r] += s[i];
            r += d;
            if (r >= numRows) {
                d = -1;
                r -= 2;
            }
            else if (r < 0) {
                d = 1;
                r = 1;
            }
        }
        s = "";
        for (auto x : rows)
            s += x;
        return s;
    }
};