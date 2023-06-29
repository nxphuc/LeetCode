// Title: Permutation Sequence
// Source: https://leetcode.com/problems/permutation-sequence
// Difficulty: Hard
// Tags: Math, Recursion
// Author: nxphuc
// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Note: 

/**
 * The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
 * - "123"
 * - "132"
 * - "213"
 * - "231"
 * - "312"
 * - "321"
 * Given n and k, return the k^th permutation sequence.
 *  
 * Example 1:
 * Input: n = 3, k = 3
 * Output: "213"
 * Example 2:
 * Input: n = 4, k = 9
 * Output: "2314"
 * Example 3:
 * Input: n = 3, k = 1
 * Output: "123"
 *  
 * Constraints:
 * - 1 <= n <= 9
 * - 1 <= k <= n!
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact[9] = {1};
        for (int i = 1; i < 9; ++i) fact[i] = fact[i - 1] * i;
        string res = "";
        string perm = "123456789";

        --k;
        for (int i = n - 1; i >= 0; --i) {
            int d = k / fact[i];
            res += perm[d];
            perm.erase(perm.begin() + d);
            k -= d * fact[i];
        }
        return res;
    }
};