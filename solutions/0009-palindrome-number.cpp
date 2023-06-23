// Title: Palindrome Number
// Source: https://leetcode.com/problems/palindrome-number
// Difficulty: Easy
// Tags: Math
// Author: nxphuc
// Time Complexity: O(1)
// Space Complexity: O(1)
// Topic:

/**
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 *  
 * Example 1:
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 * Example 2:
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * Example 3:
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *  
 * Constraints:
 * - -2^31 <= x <= 2^31 - 1
 *  
 * Follow up: Could you solve it without converting the integer to a string?
 **/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int n = 0;
        int m = x;
        while (x) {
            if (n >= INT_MAX/10) return false;
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n == m;
    }
};