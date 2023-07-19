// Title: Koko Eating Bananas
// Source: https://leetcode.com/problems/koko-eating-bananas
// Difficulty: Medium
// Tags: Array, Binary Search
// Author: nxphuc
// Time Complexity: O(N * log(max(piles)))
// Space Complexity: O(1)
// Note: 

/**
 * Koko loves to eat bananas. There are n piles of bananas, the i^th pile has piles[i] bananas. The guards have gone and will come back in h hours.
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
 * Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
 * Return the minimum integer k such that she can eat all the bananas within h hours.
 *  
 * Example 1:
 * Input: piles = [3,6,7,11], h = 8
 * Output: 4
 * Example 2:
 * Input: piles = [30,11,23,4,20], h = 5
 * Output: 30
 * Example 3:
 * Input: piles = [30,11,23,4,20], h = 6
 * Output: 23
 *  
 * Constraints:
 * - 1 <= piles.length <= 10^4
 * - piles.length <= h <= 10^9
 * - 1 <= piles[i] <= 10^9
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& piles, int h, int speed) {
        for (int x : piles) {
            int need = (x - 1) / speed + 1;
            if (need > h) return false;
            h -= need;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int res = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(piles, h, mid)) {
                res = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return res;
    }
};