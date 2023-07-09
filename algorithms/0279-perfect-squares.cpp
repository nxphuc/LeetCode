// Title: Perfect Squares
// Source: https://leetcode.com/problems/perfect-squares
// Difficulty: Medium
// Tags: Math, Dynamic Programming, Breadth-First Search
// Author: nxphuc
// Time Complexity: O(N*sqrt(N))
// Space Complexity: O(N)
// Note: 

/**
 * Given an integer n, return the least number of perfect square numbers that sum to n.
 * A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
 *  
 * Example 1:
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 * Example 2:
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 *  
 * Constraints:
 * - 1 <= n <= 10^4
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, n + 1);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j)
                f[i] = min(f[i], f[i - j * j] + 1);
        }
        return f[n];
    }
};