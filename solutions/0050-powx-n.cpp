// Title: Pow(x, n)
// Source: https://leetcode.com/problems/powx-n
// Difficulty: Medium
// Tags: Math, Recursion
// Author: nxphuc
// Time Complexity: O(logN)
// Space Complexity: O(logN)
// Note: 

/**
 * Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
 *  
 * Example 1:
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 * Example 2:
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 * Example 3:
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 *  
 * Constraints:
 * - -100.0 < x < 100.0
 * - -2^31 <= n <= 2^31-1
 * - n is an integer.
 * - Either x is not zero or n > 0.
 * - -10^4 <= x^n <= 10^4
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
            if (n == INT_MIN)
                return 1 / x / myPow(x, -(n + 1));
            return 1/myPow(x, -n);
        }
        double res = myPow(x, n >> 1);
        res *= res;
        if (n & 1) res *= x;
        return res;
    }
};