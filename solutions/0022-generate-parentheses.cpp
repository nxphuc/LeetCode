// Title: Generate Parentheses
// Source: https://leetcode.com/problems/generate-parentheses
// Difficulty: Medium
// Tags: String, Dynamic Programming, Backtracking
// Author: nxphuc
// Time Complexity: O(4^N/sqrt(N))
// Space Complexity: O(N)
// Note: 

/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *  
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 *  
 * Constraints:
 * - 1 <= n <= 8
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& res, int n, string s = "", int open = 0, int close = 0) {
        if (s.length() == 2 * n) {
            res.push_back(s);
            return;
        }
        // number of open parentheses must be not greater than n at any time
        if (open < n)
            backtrack(res, n, s + '(', open + 1, close);
        // number of close parentheses must be not greater than open parentheses at any time
        if (close < open)
            backtrack(res, n, s + ')', open, close + 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, n);
        return res;
    }
};