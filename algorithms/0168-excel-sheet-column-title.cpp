// Title: Excel Sheet Column Title
// Source: https://leetcode.com/problems/excel-sheet-column-title
// Difficulty: Easy
// Tags: Math, String
// Author: nxphuc
// Time Complexity: O(logN)
// Space Complexity: O(1)
// Note: 

/**
 * Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
 * For example:
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 * ...
 *  
 * Example 1:
 * Input: columnNumber = 1
 * Output: "A"
 * Example 2:
 * Input: columnNumber = 28
 * Output: "AB"
 * Example 3:
 * Input: columnNumber = 701
 * Output: "ZY"
 *  
 * Constraints:
 * - 1 <= columnNumber <= 2^31 - 1
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while (columnNumber) {
            s = char(--columnNumber % 26 + 'A') + s;
            columnNumber /= 26;
        }
        return s;
    }
};