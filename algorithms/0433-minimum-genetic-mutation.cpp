// Title: Minimum Genetic Mutation
// Source: https://leetcode.com/problems/minimum-genetic-mutation
// Difficulty: Medium
// Tags: Hash Table, String, Breadth-First Search
// Author: nxphuc
// Time Complexity: O(N * len(S))
// Space Complexity: O(N)
// Note: 

/**
 * A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
 * Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.
 * - For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
 * There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
 * Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
 * Note that the starting point is assumed to be valid, so it might not be included in the bank.
 *  
 * Example 1:
 * Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
 * Output: 1
 * Example 2:
 * Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
 * Output: 2
 *  
 * Constraints:
 * - 0 <= bank.length <= 10
 * - startGene.length == endGene.length == bank[i].length == 8
 * - startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, int> dist;
        string choices = "ACGT";
        for (string& s : bank)
            dist[s] = -1;
        if (dist.find(endGene) == dist.end())
            return -1;
        queue<string> q;
        q.push(startGene);
        dist[startGene] = 0;
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            for (int i = 0; i < u.length(); ++i) {
                string v = u;
                for (int j = 0; j < 4; ++j) {
                    if (u[i] == choices[j]) continue;
                    v[i] = choices[j];
                    if (dist.find(v) == dist.end() || dist[v] != -1) continue;
                    dist[v] = dist[u] + 1;
                    if (v == endGene) return dist[v];
                    q.push(v);
                }
            }
        }
        return -1;
    }
};