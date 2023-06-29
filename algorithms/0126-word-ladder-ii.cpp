// Title: Word Ladder II
// Source: https://leetcode.com/problems/word-ladder-ii
// Difficulty: Hard
// Tags: Hash Table, String, Backtracking, Breadth-First Search
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
 * - Every adjacent pair of words differs by a single letter.
 * - Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
 * - sk == endWord
 * Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
 *  
 * Example 1:
 * Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 * Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * Explanation: There are 2 shortest transformation sequences:
 * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
 * "hit" -> "hot" -> "lot" -> "log" -> "cog"
 * Example 2:
 * Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
 * Output: []
 * Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 *  
 * Constraints:
 * - 1 <= beginWord.length <= 5
 * - endWord.length == beginWord.length
 * - 1 <= wordList.length <= 500
 * - wordList[i].length == beginWord.length
 * - beginWord, endWord, and wordList[i] consist of lowercase English letters.
 * - beginWord != endWord
 * - All the words in wordList are unique.
 * - The sum of all shortest transformation sequences does not exceed 10^5.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(string beginWord, string endWord, unordered_set<string> wordSet, unordered_map<string, int>& dist) {
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (int i = 0; i < cur.length(); ++i) {
                string next = cur;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == cur[i]) continue;
                    next[i] = c;
                    if (wordSet.find(next) == wordSet.end() || dist.count(next) != 0) continue;
                    dist[next] = dist[cur] + 1;
                    if (next == endWord) return true;
                    q.push(next);
                }
            }
        }
        return false;
    }

    void backtrack(string beginWord, string endWord, unordered_set<string>& wordSet, unordered_map<string, int>& dist, vector<vector<string>>& res, vector<string>& path) {
        if (beginWord == endWord) {
            res.push_back(path);
            return;
        }
        if (dist[beginWord] == dist[endWord]) return;
        for (int i = 0; i < endWord.length(); ++i) {
            string prev = endWord;
            for (char c = 'a'; c <= 'z'; ++c) {
                prev[i] = c;
                if (wordSet.find(prev) != wordSet.end() && dist[prev] + 1 == dist[endWord]) {
                    path.insert(path.begin(), prev);
                    backtrack(beginWord, prev, wordSet, dist, res, path);
                    path.erase(path.begin());
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dist;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        wordSet.insert(beginWord);
        if (!bfs(beginWord, endWord, unordered_set<string>(wordList.begin(), wordList.end()), dist)) return {};

        vector<vector<string>> res;
        vector<string> path = {endWord};
        backtrack(beginWord, endWord, wordSet, dist, res, path);
        return res;
    }
};