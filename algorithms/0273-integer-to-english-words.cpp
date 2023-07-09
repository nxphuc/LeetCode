// Title: Integer to English Words
// Source: https://leetcode.com/problems/integer-to-english-words
// Difficulty: Hard
// Tags: Math, String, Recursion
// Author: nxphuc
// Time Complexity: O(logN)
// Space Complexity: O(1)
// Note: 

/**
 * Convert a non-negative integer num to its English words representation.
 *  
 * Example 1:
 * Input: num = 123
 * Output: "One Hundred Twenty Three"
 * Example 2:
 * Input: num = 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * Example 3:
 * Input: num = 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 *  
 * Constraints:
 * - 0 <= num <= 2^31 - 1
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const string LESS_THAN_20[20] = {
        "", "One", "Two", "Three", "Four", 
        "Five", "Six", "Seven", "Eight", "Nine", 
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    const string TENS[10] = {
        "", "Ten", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };
    const string THOUSANDS[4] = {"", "Thousand", "Million", "Billion"};
public:
    string helper(int n) {
        if (!n) return "";
        if (n < 20)
            return LESS_THAN_20[n] + " ";
        if (n < 100)
            return TENS[n / 10] + " " + (n % 10 ? LESS_THAN_20[n % 10] + " " : "");
        return LESS_THAN_20[n / 100] + " Hundred " + helper(n % 100);
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i = 0;
        string res = "";
        while (num) {
            if (num % 1000 != 0)
                res = helper(num % 1000) + THOUSANDS[i] + " " + res;
            num /= 1000;
            ++i;
        }
        while (res.back() == ' ') res.pop_back();
        return res;
    }
};