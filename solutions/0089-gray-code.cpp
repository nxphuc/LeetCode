// Title: Gray Code
// Source: https://leetcode.com/problems/gray-code
// Difficulty: Medium
// Tags: Math, Backtracking, Bit Manipulation
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * An n-bit gray code sequence is a sequence of 2^n integers where:
 * - Every integer is in the inclusive range [0, 2^n - 1],
 * - The first integer is 0,
 * - An integer appears no more than once in the sequence,
 * - The binary representation of every pair of adjacent integers differs by exactly one bit, and
 * - The binary representation of the first and last integers differs by exactly one bit.
 * Given an integer n, return any valid n-bit gray code sequence.
 *  
 * Example 1:
 * Input: n = 2
 * Output: [0,1,3,2]
 * Explanation:
 * The binary representation of [0,1,3,2] is [00,01,11,10].
 * - 00 and 01 differ by one bit
 * - 01 and 11 differ by one bit
 * - 11 and 10 differ by one bit
 * - 10 and 00 differ by one bit
 * [0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
 * - 00 and 10 differ by one bit
 * - 10 and 11 differ by one bit
 * - 11 and 01 differ by one bit
 * - 01 and 00 differ by one bit
 * Example 2:
 * Input: n = 1
 * Output: [0,1]
 *  
 * Constraints:
 * - 1 <= n <= 16
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backtrack(vector<int>& gray, vector<bool>& used, int n, int cnt, int prev) {
        if (cnt == 1 << n) return true;

        for (int i = 0; i < n; ++i) {
            if (!used[prev ^ (1 << i)]) {
                used[prev ^ (1 << i)] = true;
                gray[cnt] = prev ^ (1 << i);
                if (backtrack(gray, used, n, cnt + 1, prev ^ (1 << i)))
                    return true;
                used[prev ^ (1 << i)] = false;
            }
        }

        return false;
    }

    vector<int> grayCode(int n) {
        int m = 1 << n;
        vector<int> gray(m);
        vector<bool> used(m, false);
        for (int i = 0; i < m; ++i) {
            used[i] = true;
            if (backtrack(gray, used, n, 1, i))
                return gray;
            used[i] = false;
        }
        return {};
    }
};