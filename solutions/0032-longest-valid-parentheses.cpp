// Title: Longest Valid Parentheses
// Source: https://leetcode.com/problems/longest-valid-parentheses
// Difficulty: Hard
// Tags: String, Dynamic Programming, Stack
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
 *  
 * Example 1:
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 * Example 2:
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 * Example 3:
 * Input: s = ""
 * Output: 0
 *  
 * Constraints:
 * - 0 <= s.length <= 3 * 10^4
 * - s[i] is '(', or ')'.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                st.push(i);
            else {
                st.pop();
                if (st.empty()) st.push(i);
                res = max(res, i - st.top());
            }
        }
        return res;
    }
};