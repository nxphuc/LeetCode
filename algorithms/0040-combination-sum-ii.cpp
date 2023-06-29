// Title: Combination Sum II
// Source: https://leetcode.com/problems/combination-sum-ii
// Difficulty: Medium
// Tags: Array, Backtracking
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
 * Each number in candidates may only be used once in the combination.
 * Note: The solution set must not contain duplicate combinations.
 *  
 * Example 1:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * Example 2:
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 *  
 * Constraints:
 * - 1 <= candidates.length <= 100
 * - 1 <= candidates[i] <= 50
 * - 1 <= target <= 30
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& selected, vector<int>& candidates, int target, int last = 0) {
        if (target == 0) {
            res.push_back(selected);
            return;
        }
        for (int i = last; i < candidates.size(); ++i) {
            if (target < candidates[i]) continue;
            if (i > last && candidates[i] == candidates[i - 1]) continue;
            selected.push_back(candidates[i]);
            backtrack(res, selected, candidates, target - candidates[i], i + 1);
            selected.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> selected;
        sort(candidates.begin(), candidates.end());
        backtrack(res, selected, candidates, target);
        return res;
    }
};