// Title: Divide Two Integers
// Source: https://leetcode.com/problems/divide-two-integers
// Difficulty: Medium
// Tags: Math, Bit Manipulation
// Author: nxphuc
// Time Complexity: O(logN)
// Space Complexity: O(1)
// Note: 

/**
 * Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
 * The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
 * Return the quotient after dividing dividend by divisor.
 * Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.
 *  
 * Example 1:
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = 3.33333.. which is truncated to 3.
 * Example 2:
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 *  
 * Constraints:
 * - -2^31 <= dividend, divisor <= 2^31 - 1
 * - divisor != 0
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN)
            return divisor > 0 ? -1 + divide(dividend + divisor, divisor) : 1 + divide(dividend - divisor, divisor);

        int sign = (dividend < 0) ^ (divisor < 0);
        int res = 0;
        dividend = abs(dividend);
        divisor = abs(divisor);

        if (dividend < divisor) return 0;
        for (int i = 30; i >= 0; i--) {
            if ((dividend >> i) >= divisor) {
                res += 1 << i;
                dividend -= divisor << i;
            }
        }
        return sign ? -res : res;
    }
};