// Title: Pascal's Triangle II
// Source: https://leetcode.com/problems/pascals-triangle-ii
// Difficulty: Easy
// Tags: Array, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// Note: 

/**
 * Given an integer rowIndex, return the rowIndex^th (0-indexed) row of the Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 *  
 * Example 1:
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * Input: rowIndex = 1
 * Output: [1,1]
 *  
 * Constraints:
 * - 0 <= rowIndex <= 33
 *  
 * Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);
        for (int i = 0; i < rowIndex; ++i) {
            row.push_back(1);
            for (int j = row.size() - 2; j > 0; --j)
                row[j] += row[j - 1];
        }
        return row;
    }
};