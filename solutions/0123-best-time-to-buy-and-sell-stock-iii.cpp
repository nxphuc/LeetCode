// Title: Best Time to Buy and Sell Stock III
// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Difficulty: Hard
// Tags: Array, Dynamic Programming
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(N)
// Note: 

/**
 * You are given an array prices where prices[i] is the price of a given stock on the i^th day.
 * Find the maximum profit you can achieve. You may complete at most two transactions.
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 *  
 * Example 1:
 * Input: prices = [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
 * Example 2:
 * Input: prices = [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
 * Example 3:
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *  
 * Constraints:
 * - 1 <= prices.length <= 10^5
 * - 0 <= prices[i] <= 10^5
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> f(3, vector<int>(prices.size(), 0));
        for (int i = 1; i < 3; ++i) {
            int minSoFar = prices[0];
            for (int j = 1; j < prices.size(); ++j) {
                minSoFar = min(minSoFar, prices[j] - f[i - 1][j - 1]);
                f[i][j] = max(f[i][j - 1], prices[j] - minSoFar);
            }
        }
        return f[2][prices.size() - 1];
    }
};