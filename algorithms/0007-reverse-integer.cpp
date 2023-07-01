// Title: Reverse Integer
// Source: https://leetcode.com/problems/reverse-integer
// Difficulty: Medium
// Tags: Math
// Author: nxphuc
// Time Complexity: O(1)
// Space Complexity: O(1)
// Topic:

/**
 * Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 *  
 * Example 1:
 * Input: x = 123
 * Output: 321
 * Example 2:
 * Input: x = -123
 * Output: -321
 * Example 3:
 * Input: x = 120
 * Output: 21
 *  
 * Constraints:
 * - -2^31 <= x <= 2^31 - 1
 **/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};