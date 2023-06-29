// Title: Maximum Gap
// Source: https://leetcode.com/problems/maximum-gap
// Difficulty: Hard
// Tags: Array, Sorting, Bucket Sort, Radix Sort
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
 * You must write an algorithm that runs in linear time and uses linear extra space.
 *  
 * Example 1:
 * Input: nums = [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
 * Example 2:
 * Input: nums = [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 *  
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - 0 <= nums[i] <= 10^9
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        if (n < 2 || minValue == maxValue) return 0;
        int bucketSize = (maxValue - minValue - 1) / (n - 1) + 1;
        vector<int> minBuckets(n - 1, INT_MAX); // store minimum value of each bucket
        vector<int> maxBuckets(n - 1, INT_MIN); // store maximum value of each bucket
        for (int x : nums) {
            if (x == maxValue) continue;
            int bucket = (x - minValue) / bucketSize;
            minBuckets[bucket] = min(minBuckets[bucket], x);
            maxBuckets[bucket] = max(maxBuckets[bucket], x);
        }
        int prev = maxBuckets[0];
        int maxGap = INT_MIN;
        for (int i = 1; i < n - 1; ++i) {
            if (minBuckets[i] == INT_MAX) continue;
            maxGap = max(maxGap, minBuckets[i] - prev);
            prev = maxBuckets[i];
        }
        return max(maxGap, maxValue - prev);
    }
};