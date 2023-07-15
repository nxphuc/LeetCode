// Title: Unique Number of Occurrences
// Source: https://leetcode.com/problems/unique-number-of-occurrences
// Difficulty: Easy
// Tags: Array, Hash Table
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
 *  
 * Example 1:
 * Input: arr = [1,2,2,1,1,3]
 * Output: true
 * Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
 * Example 2:
 * Input: arr = [1,2]
 * Output: false
 * Example 3:
 * Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * Output: true
 *  
 * Constraints:
 * - 1 <= arr.length <= 1000
 * - -1000 <= arr[i] <= 1000
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int x : arr)
            cnt[x]++;
        unordered_set<int> st;
        for (auto kvp : cnt)
            st.insert(kvp.second);
        return st.size() == cnt.size();
    }
};