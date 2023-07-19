// Title: Guess Number Higher or Lower
// Source: https://leetcode.com/problems/guess-number-higher-or-lower
// Difficulty: Easy
// Tags: Binary Search, Interactive
// Author: nxphuc
// Time Complexity: O(logN)
// Space Complexity: O(1)
// Note: 

/**
 * We are playing the Guess Game. The game is as follows:
 * I pick a number from 1 to n. You have to guess which number I picked.
 * Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
 * You call a pre-defined API int guess(int num), which returns three possible results:
 * - -1: Your guess is higher than the number I picked (i.e. num > pick).
 * - 1: Your guess is lower than the number I picked (i.e. num < pick).
 * - 0: your guess is equal to the number I picked (i.e. num == pick).
 * Return the number that I picked.
 *  
 * Example 1:
 * Input: n = 10, pick = 6
 * Output: 6
 * Example 2:
 * Input: n = 1, pick = 1
 * Output: 1
 * Example 3:
 * Input: n = 2, pick = 1
 * Output: 1
 *  
 * Constraints:
 * - 1 <= n <= 2^31 - 1
 * - 1 <= pick <= n
**/

#include <bits/stdc++.h>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = (0LL + left + right) >> 1;
            int res = guess(mid);
            if (res == 0) return mid;
            if (res == -1)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};