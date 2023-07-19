// Title: Smallest Sufficient Team
// Source: https://leetcode.com/problems/smallest-sufficient-team
// Difficulty: Hard
// Tags: Array, Dynamic Programming, Bit Manipulation, Bitmask
// Author: nxphuc
// Time Complexity: O(N * 2^M)
// Space Complexity: O(2^M)
// Note: 

/**
 * In a project, you have a list of required skills req_skills, and a list of people. The i^th person people[i] contains a list of skills that the person has.
 * Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.
 * - For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
 * Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.
 * It is guaranteed an answer exists.
 *  
 * Example 1:
 * Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
 * Output: [0,2]
 * Example 2:
 * Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
 * Output: [1,2]
 *  
 * Constraints:
 * - 1 <= req_skills.length <= 16
 * - 1 <= req_skills[i].length <= 16
 * - req_skills[i] consists of lowercase English letters.
 * - All the strings of req_skills are unique.
 * - 1 <= people.length <= 60
 * - 0 <= people[i].length <= 16
 * - 1 <= people[i][j].length <= 16
 * - people[i][j] consists of lowercase English letters.
 * - All the strings of people[i] are unique.
 * - Every skill in people[i] is a skill in req_skills.
 * - It is guaranteed a sufficient team exists.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skillIdx;
        int nSkills = 0;
        for (string& s : req_skills) {
            if (skillIdx.find(s) == skillIdx.end())
                skillIdx[s] = nSkills++;
        }
        int n = people.size();
        vector<int> peopleSkills(n);
        for (int i = 0; i < n; ++i) {
            for (string& s : people[i])
                if (skillIdx.find(s) != skillIdx.end())
                    peopleSkills[i] |= 1 << skillIdx[s];
        }
        int nMask = 1 << nSkills;
        vector<long long> f(nMask, (1LL << n) - 1);
        f[0] = 0;
        for (int skillMask = 1; skillMask < nMask; ++skillMask)
            for (int i = 0; i < n; ++i) {
                int subSkillMask = skillMask & ~peopleSkills[i];
                if (skillMask != subSkillMask && __builtin_popcountll(f[subSkillMask] | (1LL << i)) < __builtin_popcountll(f[skillMask]))
                    f[skillMask] = f[subSkillMask] | (1LL << i);
            }
        vector<int> res;
        long long mask = f[nMask - 1];
        for (int i = 0; i < n; ++i)
            if ((mask >> i) & 1)
                res.push_back(i);
        return res;
    }
};