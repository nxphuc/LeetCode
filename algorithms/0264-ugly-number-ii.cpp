// Title: Ugly Number II
// Source: https://leetcode.com/problems/ugly-number-ii
// Difficulty: Medium
// Tags: Hash Table, Math, Dynamic Programming, Heap (Priority Queue)
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
 * Given an integer n, return the n^th ugly number.
 *  
 * Example 1:
 * Input: n = 10
 * Output: 12
 * Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
 * Example 2:
 * Input: n = 1
 * Output: 1
 * Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 *  
 * Constraints:
 * - 1 <= n <= 1690
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> f(n);
        f[0] = 1;
        int fact2 = 0, fact3 = 0, fact5 = 0;
        for (int i = 1; i < n; i++) {
            f[i] = min({f[fact2] * 2, f[fact3] * 3, f[fact5] * 5});
            if (f[i] == f[fact2] * 2) ++fact2;
            if (f[i] == f[fact3] * 3) ++fact3;
            if (f[i] == f[fact5] * 5) ++fact5;
        }
        return f[n - 1];
    }
};