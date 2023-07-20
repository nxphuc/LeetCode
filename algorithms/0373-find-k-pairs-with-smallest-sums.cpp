// Title: Find K Pairs with Smallest Sums
// Source: https://leetcode.com/problems/find-k-pairs-with-smallest-sums
// Difficulty: Medium
// Tags: Array, Heap (Priority Queue)
// Author: nxphuc
// Time Complexity: O(KlogN)
// Space Complexity: O(N)
// Note: 

/**
 * You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
 * Define a pair (u, v) which consists of one element from the first array and one element from the second array.
 * Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
 *  
 * Example 1:
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]]
 * Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * Example 2:
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [[1,1],[1,1]]
 * Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * Example 3:
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [[1,3],[2,3]]
 * Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 *  
 * Constraints:
 * - 1 <= nums1.length, nums2.length <= 10^5
 * - -10^9 <= nums1[i], nums2[i] <= 10^9
 * - nums1 and nums2 both are sorted in non-decreasing order.
 * - 1 <= k <= 10^4
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        typedef pair<int, int> ii;
        typedef pair<int, ii> iii;

        priority_queue<iii, vector<iii>, greater<iii>> pq;
        for (int i = 0; i < nums1.size(); ++i) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        vector<vector<int>> res;
        while (k-- && !pq.empty()) {
            auto [s, p] = pq.top();
            pq.pop();
            res.push_back({nums1[p.first], nums2[p.second]});
            if (++p.second < nums2.size())
                pq.push({nums1[p.first] + nums2[p.second], {p.first, p.second}});
        }
        return res;
    }
};