// Title: Basic Calculator II
// Source: https://leetcode.com/problems/basic-calculator-ii
// Difficulty: Medium
// Tags: Math, String, Stack
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given a string s which represents an expression, evaluate this expression and return its value. 
 * The integer division should truncate toward zero.
 * You may assume that the given expression is always valid. All intermediate results will be in the range of [-2^31, 2^31 - 1].
 * Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
 *  
 * Example 1:
 * Input: s = "3+2*2"
 * Output: 7
 * Example 2:
 * Input: s = " 3/2 "
 * Output: 1
 * Example 3:
 * Input: s = " 3+5 / 2 "
 * Output: 5
 *  
 * Constraints:
 * - 1 <= s.length <= 3 * 10^5
 * - s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
 * - s represents a valid expression.
 * - All the integers in the expression are non-negative integers in the range [0, 2^31 - 1].
 * - The answer is guaranteed to fit in a 32-bit integer.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        s += "+0";
        int num = 0;
        char sign = '+';
        for (char c : s) {
            if (c == ' ') continue;
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                continue;
            }
            if (sign == '*') {
                num = num * st.top();
                st.pop();
                st.push(num);
            }
            else if (sign == '/') {
                num = st.top() / num;
                st.pop();
                st.push(num);
            }
            else if (sign == '+') {
                st.push(num);
            }
            else // sign == '-
                st.push(-num);
            num = 0;
            sign = c;
        }
        num = 0;
        while (!st.empty()) {
            num += st.top();
            st.pop();
        }
        return num;
    }
};