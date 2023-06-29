// Title: Excel Sheet Column Number
// Source: https://leetcode.com/problems/excel-sheet-column-number
// Difficulty: Easy
// Tags: Math, String
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.
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
 * Input: columnTitle = "A"
 * Output: 1
 * Example 2:
 * Input: columnTitle = "AB"
 * Output: 28
 * Example 3:
 * Input: columnTitle = "ZY"
 * Output: 701
 *  
 * Constraints:
 * - 1 <= columnTitle.length <= 7
 * - columnTitle consists only of uppercase English letters.
 * - columnTitle is in the range ["A", "FXSHRXW"].
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = 0;
        for (char ch : columnTitle)
            n = n * 26 + (ch - 'A') + 1;
        return n;
    }
};