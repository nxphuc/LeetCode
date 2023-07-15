// Title: Maximum Number of Events That Can Be Attended II
// Source: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii
// Difficulty: Hard
// Tags: Array, Binary Search, Dynamic Programming, Sorting
// Author: nxphuc
// Time Complexity: O(N * (K + logN))
// Space Complexity: O(N * K)
// Note: 

/**
 * You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The i^th event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
 * You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
 * Return the maximum sum of values that you can receive by attending events.
 *  
 * Example 1:
 * 
 * Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
 * Output: 7
 * Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
 * Example 2:
 * 
 * Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
 * Output: 10
 * Explanation: Choose event 2 for a total value of 10.
 * Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
 * Example 3:
 * 
 * Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
 * Output: 9
 * Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
 *  
 * Constraints:
 * - 1 <= k <= events.length
 * - 1 <= k * events.length <= 10^6
 * - 1 <= startDayi <= endDayi <= 10^9
 * - 1 <= valuei <= 10^6
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [&](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        int n = events.size();
        vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            int nxt = lower_bound(events.begin() + i + 1, events.end(), events[i][1] + 1, [](const vector<int>& a, const int& target) {
                return a[0] < target;
            }) - events.begin();
            for (int j = 1; j <= k; ++j) {
                f[i][j] = max(f[i + 1][j], f[nxt][j - 1] + events[i][2]);
            }
        }
        return f[0][k];
    }
};