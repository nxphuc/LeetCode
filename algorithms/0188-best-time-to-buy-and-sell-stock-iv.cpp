// Title: Best Time to Buy and Sell Stock IV
// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
// Difficulty: Hard
// Tags: Array, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(N*K))
// Space Complexity: O(N*K)
// Note: 

/**
 * You are given an integer array prices where prices[i] is the price of a given stock on the i^th day, and an integer k.
 * Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 *  
 * Example 1:
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
 * Example 2:
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 *  
 * Constraints:
 * - 1 <= k <= 100
 * - 1 <= prices.length <= 1000
 * - 0 <= prices[i] <= 1000
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // reuse solution of Best Time to Buy and Sell Stock II
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i)
            res += max(0, prices[i] - prices[i - 1]);
        return res;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(k + 1, vector<int>(n, 0));

        if (k >= n/2)
            return maxProfit(prices);

        for (int i = 1; i <= k; ++i) {
            int bestProfitToHold = -prices[0];
            for (int j = 1; j < n; ++j) {
                f[i][j] = max(f[i][j - 1], prices[j] + bestProfitToHold);
                bestProfitToHold = max(bestProfitToHold, f[i - 1][j - 1] - prices[j]);
            }
        }
        return f[k][n - 1];
    }
};