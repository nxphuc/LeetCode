// Title: Factorial Trailing Zeroes
// Source: https://leetcode.com/problems/factorial-trailing-zeroes
// Difficulty: Medium
// Tags: Math
// Author: nxphuc
// Time Complexity: O(logN)
// Space Complexity: O(1)
// Note: 

/**
 * Given an integer n, return the number of trailing zeroes in n!.
 * Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
 *  
 * Example 1:
 * Input: n = 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * Example 2:
 * Input: n = 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * Example 3:
 * Input: n = 0
 * Output: 0
 *  
 * Constraints:
 * - 0 <= n <= 10^4
 *  
 * Follow up: Could you write a solution that works in logarithmic time complexity?
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while (n) {
            n /= 5;
            cnt += n;
        }
        return cnt;
    }
};