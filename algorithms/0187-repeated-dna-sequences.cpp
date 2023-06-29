// Title: Repeated DNA Sequences
// Source: https://leetcode.com/problems/repeated-dna-sequences
// Difficulty: Medium
// Tags: Hash Table, String, Bit Manipulation, Sliding Window, Rolling Hash, Hash Function
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
 * - For example, "ACGAATTCCG" is a DNA sequence.
 * When studying DNA, it is useful to identify repeated sequences within the DNA.
 * Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
 *  
 * Example 1:
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * Output: ["AAAAACCCCC","CCCCCAAAAA"]
 * Example 2:
 * Input: s = "AAAAAAAAAAAAA"
 * Output: ["AAAAAAAAAA"]
 *  
 * Constraints:
 * - 1 <= s.length <= 10^5
 * - s[i] is either 'A', 'C', 'G', or 'T'.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq;
        int n = s.length();
        vector<string> res;
        for (int i = 0; i + 10 <= n; ++i) {
            if (++freq[s.substr(i, 10)] == 2)
                res.push_back(s.substr(i, 10));
        }
        return res;
    }
};