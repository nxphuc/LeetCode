// Title: Multiply Strings
// Source: https://leetcode.com/problems/multiply-strings
// Difficulty: Medium
// Tags: Math, String, Simulation
// Author: nxphuc
// Time Complexity: O(N * M)
// Space Complexity: O(1)
// Note: 

/**
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
 * Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
 *  
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *  
 * Constraints:
 * - 1 <= num1.length, num2.length <= 200
 * - num1 and num2 consist of digits only.
 * - Both num1 and num2 do not contain any leading zero, except the number 0 itself.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        num2 += '0'; // add leading 0 to num2
        int n = num1.size();
        int m = num2.size();
        vector<int> res(n + m, 0);
        for (int i = 0; i < n; ++i) {
            // multiply num1[i] with num2
            int carry = 0;
            for (int j = 0; j < m; ++j) {
                carry += (num1[i] - '0') * (num2[j] - '0') + res[i + j];;
                res[i + j] = carry % 10;
                carry /= 10;
            }
            // assume that carry is 0 because we added leading zero before
        }
        string s = "";
        while (res.back() == 0) res.pop_back();
        for (int i = res.size() - 1; i >= 0; --i) s += res[i] + '0';
        return s;
    }
};