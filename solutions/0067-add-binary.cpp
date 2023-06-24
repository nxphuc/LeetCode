// Title: Add Binary
// Source: https://leetcode.com/problems/add-binary
// Difficulty: Easy
// Tags: Math, String, Bit Manipulation, Simulation
// Author: nxphuc
// Time Complexity: O(max(N, M))
// Space Complexity: O(1)
// Note: 

/**
 * Given two binary strings a and b, return their sum as a binary string.
 *  
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *  
 * Constraints:
 * - 1 <= a.length, b.length <= 10^4
 * - a and b consist only of '0' or '1' characters.
 * - Each string does not contain leading zeros except for the zero itself.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int carry = 0;
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; --i, --j) {
            carry += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
            s = char((carry & 1) + '0') + s;
            carry >>= 1;
        }
        if (carry)
            return "1" + s;
        return s;
    }
};