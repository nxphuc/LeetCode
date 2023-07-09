// Title: Can Place Flowers
// Source: https://leetcode.com/problems/can-place-flowers
// Difficulty: Easy
// Tags: Array, Greedy
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
 *  
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: true
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: false
 *  
 * Constraints:
 * - 1 <= flowerbed.length <= 2 * 10^4
 * - flowerbed[i] is 0 or 1.
 * - There are no two adjacent flowers in flowerbed.
 * - 0 <= n <= flowerbed.length
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev = -2;
        int cnt = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i]) {
                if (prev == i - 1) --cnt;
                prev = i;
            }
            else if (i - 1 > prev) {
                ++cnt;
                prev = i;
            }
        }
        return cnt >= n;
    }
};