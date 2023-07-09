// Title: Add Digits
// Source: https://leetcode.com/problems/add-digits
// Difficulty: Easy
// Tags: Math, Simulation, Number Theory
// Author: nxphuc
// Time Complexity: O(1)
// Space Complexity: O(1)
// Note: 

/**
 * Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
 *  
 * Example 1:
 * Input: num = 38
 * Output: 2
 * Explanation: The process is
 * 38 --> 3 + 8 --> 11
 * 11 --> 1 + 1 --> 2 
 * Since 2 has only one digit, return it.
 * Example 2:
 * Input: num = 0
 * Output: 0
 *  
 * Constraints:
 * - 0 <= num <= 2^31 - 1
 *  
 * Follow up: Could you do it without any loop/recursion in O(1) runtime?
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return num == 0 ? 0 : (num - 1) % 9 + 1;
    }
};