// Title: Basic Calculator
// Source: https://leetcode.com/problems/basic-calculator
// Difficulty: Hard
// Tags: Math, String, Stack, Recursion
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
 * Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
 *  
 * Example 1:
 * Input: s = "1 + 1"
 * Output: 2
 * Example 2:
 * Input: s = " 2-1 + 2 "
 * Output: 3
 * Example 3:
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 *  
 * Constraints:
 * - 1 <= s.length <= 3 * 10^5
 * - s consists of digits, '+', '-', '(', ')', and ' '.
 * - s represents a valid expression.
 * - '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
 * - '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
 * - There will be no two consecutive operators in the input.
 * - Every number and running calculation will fit in a signed 32-bit integer.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0, num = 0, sign = 1;
        for (char c : s) {
            if (c == ' ') continue;
            if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (c == '(') {
                // found a sub expression
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
            else {
                res += sign * num;
                num = 0;
                sign = c == '+' ? 1 : -1;
            }
        }
        if (num) res += sign * num;
        return res;
    }
};