// Title: Kth Largest Element in an Array
// Source: https://leetcode.com/problems/kth-largest-element-in-an-array
// Difficulty: Medium
// Tags: Array, Divide and Conquer, Sorting, Heap (Priority Queue), Quickselect
// Author: nxphuc
// Time Complexity: O(NlogK)
// Space Complexity: O(K)
// Note: 

/**
 * Given an integer array nums and an integer k, return the k^th largest element in the array.
 * Note that it is the k^th largest element in the sorted order, not the k^th distinct element.
 * Can you solve it without sorting?
 *  
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 *  
 * Constraints:
 * - 1 <= k <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : nums) {
            pq.push(x);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};