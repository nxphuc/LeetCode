// Title: Maximize the Confusion of an Exam
// Source: https://leetcode.com/problems/maximize-the-confusion-of-an-exam
// Difficulty: Medium
// Tags: String, Binary Search, Sliding Window, Prefix Sum
// Author: nxphuc
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// Note: 

/**
 * A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).
 * You are given a string answerKey, where answerKey[i] is the original answer to the i^th question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:
 * - Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
 * Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
 *  
 * Example 1:
 * Input: answerKey = "TTFF", k = 2
 * Output: 4
 * Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
 * There are four consecutive 'T's.
 * Example 2:
 * Input: answerKey = "TFFT", k = 1
 * Output: 3
 * Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
 * Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
 * In both cases, there are three consecutive 'F's.
 * Example 3:
 * Input: answerKey = "TTFTTFTT", k = 1
 * Output: 5
 * Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
 * Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
 * In both cases, there are five consecutive 'T's.
 *  
 * Constraints:
 * - n == answerKey.length
 * - 1 <= n <= 5 * 10^4
 * - answerKey[i] is either 'T' or 'F'
 * - 1 <= k <= n
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& pref, int n, int k, int len) {
        for (int i = len; i <= n; ++i) {
            if (pref[i] - pref[i - len] <= k || len - pref[i] + pref[i - len] <= k)
                return true;
        }
        return false;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; ++i)
            pref[i] = pref[i - 1] + (answerKey[i - 1] == 'T');
        int left = k, right = n;
        int res = left;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (isValid(pref, n, k, mid)) {
                res = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return res;
    }
};