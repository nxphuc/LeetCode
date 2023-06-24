// Title: Merge Intervals
// Source: https://leetcode.com/problems/merge-intervals
// Difficulty: Medium
// Tags: Array, Sorting
// Author: nxphuc
// Time Complexity: O(NlogN)
// Space Complexity: O(1)
// Note: 

/**
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
 *  
 * Example 1:
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 * Example 2:
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *  
 * Constraints:
 * - 1 <= intervals.length <= 10^4
 * - intervals[i].length == 2
 * - 0 <= starti <= endi <= 10^4
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int idx = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > intervals[idx][1])
                intervals[++idx] = intervals[i];
            else
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
        }
        intervals.resize(idx + 1);
        return intervals;
    }
};