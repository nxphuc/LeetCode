// Title: Contains Duplicate II
// Source: https://leetcode.com/problems/contains-duplicate-ii
// Difficulty: Easy
// Tags: Array, Hash Table, Sliding Window
// Author: nxphuc
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// Note: 

/**
 * Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
 *  
 * Example 1:
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * Example 2:
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * Example 3:
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 *  
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
 * - 0 <= k <= 10^5
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeen;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            it = lastSeen.find(nums[i]);
            if (it != lastSeen.end() && i - it->second <= k)
                return true;
            lastSeen[nums[i]] = i;
        }
        return false;
    }
};