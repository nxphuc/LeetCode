// Title: Combinations
// Source: https://leetcode.com/problems/combinations
// Difficulty: Medium
// Tags: Backtracking
// Author: nxphuc
// Time Complexity: O(nCk)
// Space Complexity: O(1)
// Note: 

/**
 * Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
 * You may return the answer in any order.
 *  
 * Example 1:
 * Input: n = 4, k = 2
 * Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * Explanation: There are 4 choose 2 = 6 total combinations.
 * Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
 * Example 2:
 * Input: n = 1, k = 1
 * Output: [[1]]
 * Explanation: There is 1 choose 1 = 1 total combination.
 *  
 * Constraints:
 * - 1 <= n <= 20
 * - 1 <= k <= n
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> c(k, 0);
        for (int i = 0; i < k; i++)
            c[i] = i + 1;
        result.push_back(c);
        int i = k - 1;
        while (i >= 0) {
            ++c[i];
            if (c[i] > n - k + i + 1)
                --i;
            else if (i == k - 1)
                result.push_back(c);
            else {
                ++i;
                c[i] = c[i - 1];
            }
        }
        return result;
    }
};