// Title: Word Break II
// Source: https://leetcode.com/problems/word-break-ii
// Difficulty: Hard
// Tags: Array, Hash Table, String, Dynamic Programming, Backtracking, Trie, Memoization
// Author: nxphuc
// Time Complexity: (N * 2^N)
// Space Complexity: O(N^2)
// Note: 

/**
 * Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
 * Note that the same word in the dictionary may be reused multiple times in the segmentation.
 *  
 * Example 1:
 * Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * Output: ["cats and dog","cat sand dog"]
 * Example 2:
 * Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
 * Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: []
 *  
 * Constraints:
 * - 1 <= s.length <= 20
 * - 1 <= wordDict.length <= 1000
 * - 1 <= wordDict[i].length <= 10
 * - s and wordDict[i] consist of only lowercase English letters.
 * - All the strings of wordDict are unique.
 * - Input is generated in a way that the length of the answer doesn't exceed 10^5.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& result, string current, unordered_set<string>& wordSet, string& s, int idx) {
        if (idx == s.length()) {
            result.push_back(current.substr(1));
            return;
        }
        string word;
        for (int i = idx; i < s.length(); ++i) {
            word += s[i];
            if (wordSet.find(word) != wordSet.end())
                backtrack(result, current + " " + word, wordSet, s, i + 1);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> result;
        string current;
        backtrack(result, current, wordSet, s, 0);
        return result;
    }
};