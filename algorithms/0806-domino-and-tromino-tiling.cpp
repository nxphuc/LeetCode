// Title: Domino and Tromino Tiling
// Source: https://leetcode.com/problems/domino-and-tromino-tiling
// Difficulty: Medium
// Tags: Dynamic Programming
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
 * Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 10^9 + 7.
 * In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.
 *  
 * Example 1:
 * 
 * Input: n = 3
 * Output: 5
 * Explanation: The five different ways are show above.
 * Example 2:
 * Input: n = 1
 * Output: 1
 *  
 * Constraints:
 * - 1 <= n <= 1000
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
        if (n < 2) return 1;
        if (n == 2) return 2;
        int MOD = 1e9 + 7;
        vector<int> f(n + 1, 0);
        f[0] = f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= n; ++i)
            f[i] = (2LL * f[i - 1] + f[i - 3]) % MOD;
        return f[n];
    }
};