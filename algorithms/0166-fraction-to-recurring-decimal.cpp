// Title: Fraction to Recurring Decimal
// Source: https://leetcode.com/problems/fraction-to-recurring-decimal
// Difficulty: Medium
// Tags: Hash Table, Math, String
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note:

/**
 * Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * If multiple answers are possible, return any of them.
 * It is guaranteed that the length of the answer string is less than 10^4 for all the given inputs.
 *  
 * Example 1:
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * Example 2:
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * Example 3:
 * Input: numerator = 4, denominator = 333
 * Output: "0.(012)"
 *  
 * Constraints:
 * - -2^31 <= numerator, denominator <= 2^31 - 1
 * - denominator != 0
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator;
        long long denom = denominator;
        map<pair<long long, long long>, int> mp;
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
        string res;
        if (num < 0) {
            res = "-";
            num = -num;
        }
        res += to_string(num / denom);
        num %= denom;
        if (!num)
            return res;
        res += ".";
        while (num) {
            auto it = mp.find({num, denom});
            if (it != mp.end()) {
                res.insert(res.begin() + it->second, '(');
                res += ')';
                break;
            }
            mp[{num, denom}] = res.length();
            res += (num * 10 / denom) + '0';
            num = num * 10 % denom;
        }
        return res;
    }
};