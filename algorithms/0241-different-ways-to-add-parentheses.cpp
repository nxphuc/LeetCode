// Title: Different Ways to Add Parentheses
// Source: https://leetcode.com/problems/different-ways-to-add-parentheses
// Difficulty: Medium
// Tags: Math, String, Dynamic Programming, Recursion, Memoization
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
 * The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 10^4.
 *  
 * Example 1:
 * Input: expression = "2-1-1"
 * Output: [0,2]
 * Explanation:
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * Example 2:
 * Input: expression = "2*3-4*5"
 * Output: [-34,-14,-10,-10,10]
 * Explanation:
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 *  
 * Constraints:
 * - 1 <= expression.length <= 20
 * - expression consists of digits and the operator '+', '-', and '*'.
 * - All the integer values in the input expression are in the range [0, 99].
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(string expression, map<string, vector<int>>& memory) {
        if (memory.find(expression) != memory.end())
            return;
        if (expression.size() <= 2) {
            memory[expression] = { stoi(expression) };
            return;
        }
        auto& res = memory[expression];
        for (int i = 0; i < expression.length(); ++i)
            if (!isdigit(expression[i])) {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                helper(left, memory);
                helper(right, memory);
                for (auto& x : memory[left])
                    for (auto& y : memory[right])
                        if (expression[i] == '+')
                            res.push_back(x + y);
                        else if (expression[i] == '-')
                            res.push_back(x - y);
                        else if (expression[i] == '*')
                            res.push_back(x * y);
            }
    }

    vector<int> diffWaysToCompute(string expression) {
        map<string, vector<int>> memory;
        helper(expression, memory);
        return memory[expression];
    }
};