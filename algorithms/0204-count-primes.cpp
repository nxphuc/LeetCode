// Title: Count Primes
// Source: https://leetcode.com/problems/count-primes
// Difficulty: Medium
// Tags: Array, Math, Enumeration, Number Theory
// Author: nxphuc
// Time Complexity: O(NloglogN)
// Space Complexity: O(N)
// Note: 

/**
 * Given an integer n, return the number of prime numbers that are strictly less than n.
 *  
 * Example 1:
 * Input: n = 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * Example 2:
 * Input: n = 0
 * Output: 0
 * Example 3:
 * Input: n = 1
 * Output: 0
 *  
 * Constraints:
 * - 0 <= n <= 5 * 10^6
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> mark(n, true);
        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            cnt += mark[i];
            if (mark[i] && n / i >= i) {
                for (int j = i * i; j < n; j += i)
                    mark[j] = false;
            }
        }
        return cnt;
    }
};