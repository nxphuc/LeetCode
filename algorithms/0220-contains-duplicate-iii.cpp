// Title: Contains Duplicate III
// Source: https://leetcode.com/problems/contains-duplicate-iii
// Difficulty: Hard
// Tags: Array, Sliding Window, Sorting, Bucket Sort, Ordered Set
// Author: nxphuc
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// Note: 

/**
 * You are given an integer array nums and two integers indexDiff and valueDiff.
 * Find a pair of indices (i, j) such that:
 * - i != j,
 * - abs(i - j) <= indexDiff.
 * - abs(nums[i] - nums[j]) <= valueDiff, and
 * Return true if such pair exists or false otherwise.
 *  
 * Example 1:
 * Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
 * Output: true
 * Explanation: We can choose (i, j) = (0, 3).
 * We satisfy the three conditions:
 * i != j --> 0 != 3
 * abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
 * abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
 * Example 2:
 * Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
 * Output: false
 * Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
 *  
 * Constraints:
 * - 2 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
 * - 1 <= indexDiff <= nums.length
 * - 0 <= valueDiff <= 10^9
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> st;
        set<int>::iterator it;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            while (r - l > indexDiff)
                st.erase(nums[l++]);
            it = st.lower_bound(nums[r] - valueDiff);
            if (it != st.end() && *it <= nums[r] + valueDiff)
                return true;
            st.insert(nums[r]);
        }
        return false;
    }
};