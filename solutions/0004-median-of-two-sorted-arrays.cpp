// Title: Median of Two Sorted Arrays
// Source: https://leetcode.com/problems/median-of-two-sorted-arrays
// Difficulty: Hard
// Tags: Array, Binary Search, Divide and Conquer
// Author: nxphuc
// Time Complexity: O(log(m + n))
// Space Complexity: O(1)
// Topic: Binary Search

/**
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 *  
 * Example 1:
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * Example 2:
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 *  
 * Constraints:
 * - nums1.length == m
 * - nums2.length == n
 * - 0 <= m <= 1000
 * - 0 <= n <= 1000
 * - 1 <= m + n <= 2000
 * - -10^6 <= nums1[i], nums2[i] <= 10^6
 **/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k, int pos1 = 0, int pos2 = 0) {
        if (pos1 >= nums1.size())
            return nums2[pos2 + k - 1];
        if (pos2 >= nums2.size())
            return nums1[pos1 + k - 1];
        if (k == 1)
            return min(nums1[pos1], nums2[pos2]);
        int n1 = min((int)nums1.size() - pos1, k / 2);
        int n2 = min((int)nums2.size() - pos2, k / 2);

        if (nums1[pos1 + n1 - 1] < nums2[pos2 + n2 - 1])
            return getKthElement(nums1, nums2, k - n1, pos1 + n1, pos2);
        return getKthElement(nums1, nums2, k - n2, pos1, pos2 + n2);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n & 1)
            return getKthElement(nums1, nums2, (n + 1) / 2);
        return (
            getKthElement(nums1, nums2, n / 2) + 
            getKthElement(nums1, nums2, n / 2 + 1)
        ) / 2.0;
    }
};