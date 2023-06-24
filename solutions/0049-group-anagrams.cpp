// Title: Group Anagrams
// Source: https://leetcode.com/problems/group-anagrams
// Difficulty: Medium
// Tags: Array, Hash Table, String, Sorting
// Author: nxphuc
// Time Complexity: O(N * MlogM)
// Space Complexity: O(N * M)
// Note: 

/**
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 *  
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 *  
 * Constraints:
 * - 1 <= strs.length <= 10^4
 * - 0 <= strs[i].length <= 100
 * - strs[i] consists of lowercase English letters.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string& s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            groups[temp].push_back(s);
        }
        vector<vector<string>> result;
        for (auto x : groups)
            result.push_back(x.second);
        return result;
    }
};