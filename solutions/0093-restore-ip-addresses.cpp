// Title: Restore IP Addresses
// Source: https://leetcode.com/problems/restore-ip-addresses
// Difficulty: Medium
// Tags: String, Backtracking
// Author: nxphuc
// Time Complexity: O(N^3)
// Space Complexity: O(N)
// Note: 

/**
 * A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
 * - For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
 * Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
 *  
 * Example 1:
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 * Example 2:
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 * Example 3:
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *  
 * Constraints:
 * - 1 <= s.length <= 20
 * - s consists of digits only.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isByte(string s) {
        if (s == "" || s.length() > 3)
            return false;
        if (s[0] == '0')
            return s.length() == 1;
        return stoi(s) <= 255;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        for (int i = 0; i < s.length(); ++i) {
            if (!isByte(s.substr(0, i + 1))) continue;
            for (int j = i + 1; j < s.length(); ++j) {
                if (!isByte(s.substr(i + 1, j - i))) continue;
                for (int k = j + 1; k < s.length(); ++k) {
                    if (isByte(s.substr(j + 1, k - j)) && isByte(s.substr(k + 1))) {
                        result.push_back(
                            s.substr(0, i + 1) +
                            "." + s.substr(i + 1, j - i) +
                            "." + s.substr(j + 1, k - j) +
                            "." + s.substr(k + 1)
                        );
                    }
                }
            }
        }
        return result;
    }
};