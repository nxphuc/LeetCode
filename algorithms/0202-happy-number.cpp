// Title: Happy Number
// Source: https://leetcode.com/problems/happy-number
// Difficulty: Easy
// Tags: Hash Table, Math, Two Pointers
// Author: nxphuc
// Time Complexity: O(1)
// Space Complexity: O(1)
// Note: 

/**
 * Write an algorithm to determine if a number n is happy.
 * A happy number is a number defined by the following process:
 * - Starting with any positive integer, replace the number by the sum of the squares of its digits.
 * - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 * - Those numbers for which this process ends in 1 are happy.
 * Return true if n is a happy number, and false if not.
 *  
 * Example 1:
 * Input: n = 19
 * Output: true
 * Explanation:
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * Example 2:
 * Input: n = 2
 * Output: false
 *  
 * Constraints:
 * - 1 <= n <= 2^31 - 1
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int root(int n) {
        int r = 0;
        while (n) {
            int d = n % 10;
            n /= 10;
            r += d*d;
        }
        return r;
    }
    bool isHappy(int n) {
        set<int> found;
        while (n > 1 && found.find(n) == found.end()) {
            found.insert(n);
            n = root(n);
        }
        return n == 1;
    }
};