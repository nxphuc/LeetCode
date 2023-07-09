// Title: Number of Digit One
// Source: https://leetcode.com/problems/number-of-digit-one
// Difficulty: Hard
// Tags: Math, Dynamic Programming, Recursion
// Author: nxphuc
// Time Complexity: O(logN)
// Space Complexity: O(1)
// Note: 

/**
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 *  
 * Example 1:
 * Input: n = 13
 * Output: 6
 * Example 2:
 * Input: n = 0
 * Output: 0
 *  
 * Constraints:
 * - 0 <= n <= 10^9
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long temp = i * 10;
            res += (n / temp) * i + min(max(n % temp - i + 1, 0LL), i);
        }
        return res;
    }
};