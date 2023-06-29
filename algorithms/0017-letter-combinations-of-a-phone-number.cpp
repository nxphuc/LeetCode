// Title: Letter Combinations of a Phone Number
// Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number
// Difficulty: Medium
// Tags: Hash Table, String, Backtracking
// Author: nxphuc
// Time Complexity: O(N * 4^N)
// Space Complexity: O(1)
// Note: 

/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
 * A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 *  
 * Example 1:
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * Example 2:
 * Input: digits = ""
 * Output: []
 * Example 3:
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *  
 * Constraints:
 * - 0 <= digits.length <= 4
 * - digits[i] is a digit in the range ['2', '9'].
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};

        map<char, string> keys = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };
        deque<string> q;
        q.emplace_back("");
        for (int i = 0; i < digits.length(); ++i) {
            while (q.front().size() == i) {
                string s = q.front();
                q.pop_front();
                for (char c : keys[digits[i]])
                    q.push_back(s + c);
            }
        }
        return vector<string>(q.begin(), q.end());
    }
};